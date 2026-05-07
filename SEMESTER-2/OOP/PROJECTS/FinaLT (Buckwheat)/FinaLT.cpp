#include <iostream>			// for input/output
#include <string>			// for std::string
#include <vector>			// for std::vector
#include <deque>			// for std::deque
#include <algorithm>		// for std::remove()
#include <cctype>			// for tolower()
#include <limits>			// for std::numeric_limits and max()

// commenting out cctype and limits headers won't give compile errors, but they are used in this program. This might be because of 'Transitive includes'.

// ============================================================
// Utils
// ============================================================

std::string tolowerString(std::string str)
{
	for (auto& x : str)
	{
		x = tolower(x);
	}
	
	return str;
}

// ============================================================
// Transaction
// ============================================================

class Transaction
{
	private:
		double amount;
		std::string name;
		
	public:
		Transaction(std::string name, double amount) : amount(amount), name(name){}
		
		double getAmount()
		{
			return amount;
		}
		
		std::string getName()
		{
			return name;
		}
};

// ============================================================
// Budget  (RECEIVER)
// ============================================================

class Budget  // RECEIVER
{
	private:
		std::string name;
		double limit;
		std::vector <Transaction*> transactionVctr;	// a vector to store pointers to 'Transaction' objects
	
	public:
		Budget(std::string name, double limit) : name(name), limit(limit) {}
		
		~Budget()
		{
			for (Transaction* t : transactionVctr)
				delete t;
		}
		
		std::string getName()
		{
			return name;
		}
		
		void setName(std::string name)
		{
			this -> name = name;
		}
		
		double getLimit()
		{
			return limit;
		}
		
		void setLimit(double limit)
		{
			this -> limit = limit;
		}
		
		double getTotalSpent()						// on the fly calculations help reduce the code because the changes are automatically done
		{
			double total = 0;
			for (Transaction* t : transactionVctr)
				total += t->getAmount();
				
			return total;
		}
		
		double getRemaining()
		{
			return limit - getTotalSpent();
		}
		
		void listTransaction()
		{
			if (transactionVctr.empty())
				std::cout << "\nNo transactions found!\n";
			
			else
			{
				for (auto* x : transactionVctr)
				{
				std::cout << "\n" << x->getName();
				}
			}
		}
		
		void pushTransaction(Transaction* t)
		{
			transactionVctr.push_back(t);
		}
		
		Transaction* inputTransaction()
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');			// calling because of getline()
			std::string name, details;
			std::cout << "\nEnter transaction name: ";
			std::getline(std::cin, name);
			
			double amount;
			std::cout << "\nEnter amount: ";
			std::cin >> amount;
			while (std::cin.fail())
			{
				std::cin.clear();		// resets the fail 'alarms'
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');			// ignores or 'discards' all the characters before and including the newline character
				
				std::cout << "\nINVALID INPUT!\n";
				std::cin >> amount;
			}
			
			Transaction* t = new Transaction(name, amount);
			
			return t;
		}
		
		Transaction* findTransaction(std::string name)  // to search if a transaction already exists
		{
			for (Transaction* t : transactionVctr)
			{
				if (tolowerString(name) == tolowerString(t->getName()))
					return t;
			}
			
			return nullptr;		// i.e; not found
		}
		
		void removeTransaction(Transaction* t)  // this method is required for undo as it does NOT delete the object itself
		{
			auto it = std::find(transactionVctr.begin(), transactionVctr.end(), t);			// .begin() returns the first element of the vector
			if (it != transactionVctr.end())												// .end() returns an imaginary element after the last element of the vector, not the last element itself.
				transactionVctr.erase(it);
		}
};

// ============================================================
// Command  (base + concrete commands)
// ============================================================

class Command  // BASE/ABSTRACT COMMAND
{
	public:
		virtual void execute()	= 0;
		virtual void undo()		= 0;
		
		virtual ~Command() {};
};

class AddTransactionCommand : public Command    // CONCRETE COMMAND
{
    private:
        Budget* receiver;      			// the object that does the actual work
        Transaction* transaction; 		// the data needed to do and undo
        bool inBudget = false;			// Transfer of ownership. Need this flag for memory management, because in some case Transaction pointers become dangling pointers. 
										// default is false beacause when this command is created the pointer is NOT in the budgetVctr vector
    
    public:
        AddTransactionCommand(Budget* b, Transaction* t) : receiver(b), transaction(t) {}
        
        ~AddTransactionCommand()		// this class conditionally owns Transaction
        {
        	if (!inBudget)				// if the transation is NOT in Budget, only then delete it
        		delete transaction;
        }
        
        void execute() override			// override tells the compiler that this method is defining a virtual method of a parent class, and that its not a new method. so if no matching method is found, an error will be thrown
        {
            receiver->pushTransaction(transaction);
            inBudget = true;
        }
        
        void undo() override
        {
            receiver->removeTransaction(transaction);
            inBudget = false;
        }
};

class DeleteTransactionCommand : public Command
{
	private:
		Budget* receiver;
		Transaction* transaction;
		bool inBudget = true;			// Transfer of ownership. Need this flag for memory management, because in some case Transaction pointers become dangling pointers. 
										// default is true beacause when this command is created the pointer is already in the category vector
		
	public:
		DeleteTransactionCommand(Budget* b, Transaction* t) : receiver(b), transaction(t) {}
		
		~DeleteTransactionCommand()		// this class conditionally owns Transaction
		{
			if (!inBudget)				// if the transation is NOT in Budget, only then delete it. Temporary ownership. Transfer of ownership
				delete transaction;
		}
		
		void execute() override 		// remove it from the Budget
		{
			receiver->removeTransaction(transaction);
			inBudget = false;
		}
		
		void undo() override			// add it back to Budget
		{
			receiver->pushTransaction(transaction);
			inBudget = true;
		}
};


// ============================================================
// BudgetManager  (INVOKER for command pattern — Singleton)
// ============================================================

class BudgetManager  // INVOKER for command pattern
{
	private:
		BudgetManager()	{}									// private constructor to prevent initialization in main()
		Budget* currentBudget = nullptr;					// only *one* budget exists
		std::deque <Command*> history;						// Deque stands for 'Double-ended queue'. Chose a deque because of pop_front() and push_front()
		const int MAX_UNDO	= 10;							// max undo/redo limit of 10
		int cursor = -1;									// this is the index of the last executed command. default value of -1 means that nothing can be undone, ie; end of history. 
															// if a command is executed, the index becomes. counting starts from 0  :)
		
		BudgetManager(const BudgetManager&) = delete;				// deleting copy constructor
		BudgetManager& operator=(const BudgetManager&) = delete;	// deleting assignment operator
		
	public:
		~BudgetManager() 									// BudgetManager owns Budget
		{	
			delete currentBudget;							// even if currentBudget is nullptr, no problem. delete has built-in checks for that
			
			for (Command* cmd : history)					// BudgetManager owns Command
				delete cmd;									// deleting the history
		}
		
		static BudgetManager& getInstance()  				// a static mathod to call for
		{
			static BudgetManager instance;  				// static ensures that its created only once along with the private constructor
			return instance;
		}
		
		Budget* getBudget()
		{
			return currentBudget;
		}
		
		void createNewBudget()
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');			// calling because of getline()
			std::string budName;
			std::cout << "\nEnter budget name: ";
			std::getline(std::cin, budName);
			
			double limit;
			std::cout << "\nEnter budget limit: ";
			std::cin >> limit;
			
			while (std::cin.fail())					// Input validation
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				
				std::cout << "\nINVALID INPUT!\n";
				std::cin >> limit;
			}
			
			for (Command* cmd : history) delete cmd;
        	history.clear();
        	cursor = -1;
			delete currentBudget;
			
			currentBudget = new Budget(budName, limit);
		}
		
// 		COMMANDS
		
		void executeCommand(Command* cmd)
		{
			while ((int)history.size() > cursor + 1)	// casting history.size() to int because it returns an unsigned int, as cursor is signed. 
			{
				delete history.back();					// deleting the history after the cursor because if a user performs a new action after undo then redo cannot be performed because it becomes invalid
				history.pop_back();
			}
			
			cmd->execute();								// execute the command
			history.push_back(cmd);						// add it to history deque
			cursor++;									// move the pointer forward (increment the index) to point at it
			
			if ((int)history.size() > MAX_UNDO) 		// if the history is too big
			{
				delete history.front();					// delete the oldest command pointer
				history.pop_front();					// remove from history
				cursor--;								// move the cursor back (decrement) to compensate
			}
		}
		
		void undo()
		{
			if (cursor < 0)
			{
				std::cout << "\nNothing to undo!";
				return;
			}
			
			history[cursor] -> undo();
			cursor--;
			std::cout << "\n*UNDO PERFORMED*\n";
		}
		
		void redo()
		{
			if (cursor + 1 >= (int)history.size())
			{
				std::cout << "\nNothing to redo!";
				return;									// no need for an else block because of this early return
			}
			
			cursor++; 									// move the cursor right (increment), ie; _undo_ the undo()
			history[cursor] -> execute();				// then execute that command
			std::cout << "\n*REDO PERFORMED*\n";
		}
};

// ============================================================
// main
// ============================================================

int main()
{
	std::cout << "\n======== FinaLT ========\n";
	
	BudgetManager& manager = BudgetManager::getInstance();  // used a reference because it points to the same instance. Without it, the copy constructor will be invoked, which has been deleted for this class
	
	// MAIN MENU
		
	char choice;
	bool menuFlag = true;									// used a flag so that the prgram can be terminated from inside a switch case
	
	while (menuFlag)
	{
		Budget* currentBudget = manager.getBudget();
		
		if (currentBudget == nullptr)
		{
			std::cout << "\nPlease, add a budget to start using this app.\n";
                
            manager.createNewBudget();  					// addBudget handles the amount
            currentBudget = manager.getBudget();
		}
		
		std::cout << "\nBudget Name: " << (currentBudget != nullptr ? currentBudget->getName() : "NULL" )
				  << "\t|\t"
				  << "PKR " << currentBudget->getRemaining() << " left of PKR " << currentBudget->getLimit()
				  << "\t(PKR " << currentBudget->getTotalSpent() << " spent)\n";
		
		std::cout << "\n---- CHOOSE AN OPTION ----\n\n"
				  << "1. Add a new transaction \t 2. Delete a transaction \t 3. List all Transaction\n"
				  << "4. Edit Budget\n"
				  << "U. Undo \t R. Redo\n"
				  << "0. EXIT PROGRAM\n";
		
		std::cin >> choice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');			// cleaning input buffer
		
		switch (choice)
        {
            case '0':
                menuFlag = false;
                break;
            
            case '1':  // add transaction
            {
                Transaction* t = currentBudget->inputTransaction();
                Command* cmd = new AddTransactionCommand(currentBudget, t);		// this cmd is deleted in undo() inside BudgetManager
                manager.executeCommand(cmd);									// adding the transaction to transactionVctr and pushing it onto undoStack
            }
            break;
            
            case '2':  // delete transaction
            {
                currentBudget->listTransaction();
                
                std::string name;
                std::cout << "\nEnter transaction name: ";
                std::getline(std::cin, name);
                
                Transaction* t = currentBudget->findTransaction(name);
                if (t != nullptr)
                {
                    Command* cmd = new DeleteTransactionCommand(currentBudget, t);
                    manager.executeCommand(cmd);
                }
                else
                    std::cout << "\nTransaction not found!";
            }
            break;
            
            case '3':  // list Transaction
            {
                currentBudget->listTransaction();
            }
            break;
            
            case '4':  // edit budget
            {
            	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');			// called because of getline()
                std::cout << "\n=== Edit name ===\n";
                std::string name;
                std::cout << "\nEnter name: ";
                std::getline(std::cin, name);
                currentBudget->setName(name);
                
                std::cout << "\n=== Edit limit ===\n";
                double limit;
                std::cout << "\nEnter limit: ";
                currentBudget->setLimit(limit);
            }
            break;
            
            case 'u':
            case 'U':
                manager.undo();
                break;
            
            case 'r':
            case 'R':
                manager.redo();
                break;
            
            default:
                std::cout << "\nINVALID INPUT\n";
        }
	}
}

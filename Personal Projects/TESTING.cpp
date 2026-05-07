#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

// ============================================================
// 1. Core Data Object
// ============================================================
class Transaction {
private:
    std::string name;
    double amount;
public:
    Transaction(std::string name, double amount) : name(name), amount(amount) {}
    std::string getName() { return name; }
    double getAmount() { return amount; }
};

// ============================================================
// 2. RECEIVER
// ============================================================
class Budget {
private:
    std::string name;
    std::vector<Transaction*> transactions;
public:
    Budget(std::string name) : name(name) {}
    ~Budget() {
        for (Transaction* t : transactions) delete t;
    }
    
    void addTransaction(Transaction* t) {
        transactions.push_back(t);
    }
    
    void removeTransaction(Transaction* t) {
        transactions.erase(std::remove(transactions.begin(), transactions.end(), t), transactions.end());
    }

    void printSummary() {
        double total = 0;
        std::cout << "\n--- Budget: " << name << " ---\n";
        for (Transaction* t : transactions) {
            std::cout << "- " << t->getName() << ": $" << t->getAmount() << "\n";
            total += t->getAmount();
        }
        std::cout << "Total Spent: $" << total << "\n--------------------------\n";
    }
};

// ============================================================
// 3. COMMAND INTERFACE
// ============================================================
class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() {}
};

// ============================================================
// 4. CONCRETE COMMAND
// ============================================================
class AddTransactionCommand : public Command {
private:
    Budget* receiver;
    Transaction* transaction;
    bool inBudget = false; // Tracks ownership to prevent memory leaks

public:
    AddTransactionCommand(Budget* b, Transaction* t) : receiver(b), transaction(t) {}
    
    ~AddTransactionCommand() {
        if (!inBudget) delete transaction; // Cleans up if undone/orphaned
    }
    
    void execute() override {
        receiver->addTransaction(transaction);
        inBudget = true;
    }
    
    void undo() override {
        receiver->removeTransaction(transaction);
        inBudget = false;
    }
};

// ============================================================
// 5. INVOKER & SINGLETON (Pattern 1 & 2)
// ============================================================
class BudgetManager {
private:
    BudgetManager() {} // Private constructor
    std::deque<Command*> history;

    // Delete copy/assignment to enforce Singleton
    BudgetManager(const BudgetManager&) = delete;
    BudgetManager& operator=(const BudgetManager&) = delete;

public:
    ~BudgetManager() {
        for (Command* cmd : history) delete cmd;
    }

    static BudgetManager& getInstance() {
        static BudgetManager instance;
        return instance;
    }
    
    void executeCommand(Command* cmd) {
        cmd->execute();
        history.push_back(cmd);
        std::cout << "[Action] Executed Command.\n";
    }
    
    void undo() {
        if (!history.empty()) {
            history.back()->undo();
            history.pop_back(); // Removes from history
            std::cout << "[Action] Undid Command.\n";
        }
    }
};

// ============================================================
// 6. MAIN (Automated Test Run)
// ============================================================
int main() {
    // 1. Get Singleton Invoker
    BudgetManager& manager = BudgetManager::getInstance();
    
    // 2. Create Receiver
    Budget myBudget("Semester Expenses");
    
    std::cout << "Initial State:";
    myBudget.printSummary();

    // 3. Execute Commands
    manager.executeCommand(new AddTransactionCommand(&myBudget, new Transaction("Textbooks", 150.00)));
    manager.executeCommand(new AddTransactionCommand(&myBudget, new Transaction("Coffee", 5.50)));
    
    std::cout << "\nAfter Adding Transactions:";
    myBudget.printSummary();

    // 4. Undo the last action
    manager.undo(); // Removes coffee
    
    std::cout << "\nAfter Undo:";
    myBudget.printSummary();

    return 0;
}




//// Source - https://stackoverflow.com/a/27856440
//// Posted by G S, modified by community. See post 'Timeline' for change history
//// Retrieved 2026-04-25, License - CC BY-SA 4.0
//
//#include <iostream>
////#include <chrono>
//#include <ctime>
//
//int main()
//{
//	time_t now = time(nullptr);
//	std::cout << now; 				// time since UNIX epoch in seconds
//	std::cout << ctime(now);
//}
// 









//#include <iostream>
//#include <string>
//#include <cctype>
//
//int main()
//{
//	std::string str = "HELLO";
//	for (auto& i : str)
//	{
//		i = tolower(i);
//		
//	}
//	
//	std::cout << "\n " << str;
//}




//#include <iostream>
//#include <string>
//
//class Vehicle
//{
//    std::string type;
//    std::string make;
//    std::string model;
//    std::string colour;
//    std::string year;
//    std::string totalMileage;
//
//public:
//    Vehicle(std::string t, std::string m, std::string mdl, std::string c, std::string y, std::string tM)
//        : type(t), make(m), model(mdl), colour(c), year(y), totalMileage(tM) {}
//
//    void print() {
//        std::cout << type << " | " << make << " " << model << " | " << colour << " | " << year << " | " << totalMileage << "km\n";
//    }
//};
//
//class GasVehicle : public Vehicle
//{
//    float fuelCapacity;
//
//public:
//    GasVehicle(Vehicle v, float fc)
//        : Vehicle(v), fuelCapacity(fc) {}
//
//    void print() {
//        Vehicle::print();
//        std::cout << "Fuel Capacity: " << fuelCapacity << "L\n";
//    }
//};
//
//class ElectricVehicle : public Vehicle
//{
//    float batteryCapacity;  // in kWh
//
//public:
//    ElectricVehicle(Vehicle v, float bc)
//        : Vehicle(v), batteryCapacity(bc) {}
//
//    void print() {
//        Vehicle::print();
//        std::cout << "Battery Capacity: " << batteryCapacity << "kWh\n";
//    }
//};
//
//int main()
//{
//    Vehicle v("Car", "Toyota", "Corolla", "Red", "2020", "0");
//    GasVehicle g(v, 50.0f);
//    ElectricVehicle e(Vehicle("Car", "Tesla", "Model 3", "White", "2023", "0"), 75.0f);
//
//    std::cout << "-- Gas Vehicle --\n";
//    g.print();
//
//    std::cout << "\n-- Electric Vehicle --\n";
//    e.print();
//}





//#include <iostream>
//using namespace std;
//class beta;
//class alpha{
//private:
//int data;
//public:
//alpha( ): data(3) { }
//friend int frifunc(alpha, beta);
//};
//class beta{
//private:
//int data;
//public:
//beta( ): data(7) { }
//friend int frifunc(alpha, beta);
//};
//int frifunc(alpha a, beta b){
//return(a.data+b.data);
//}
//int main( ){
//alpha aa;
//beta bb;
//cout << frifunc(aa, bb) << endl;
//return 0;
//}






//#include <iostream>
//int foo()
//{
//	int x = 5;
//	return x;
//}
//
//int main()
//{
//	if (foo() == 5)
//		std::cout << "OK";
//}



//#include <iostream>
//#include <string>
//
///**
// * The Command interface declares a method for executing a command.
// */
//class Command {
// public:
//  virtual ~Command() {
//  }
//  virtual void Execute() const = 0;
//};
///**
// * Some commands can implement simple operations on their own.
// */
//class SimpleCommand : public Command {
// private:
//  std::string pay_load_;
//
// public:
//  explicit SimpleCommand(std::string pay_load) : pay_load_(pay_load) {
//  }
//  void Execute() const override {
//    std::cout << "SimpleCommand: See, I can do simple things like printing (" << this->pay_load_ << ")\n";
//  }
//};
//
///**
// * The Receiver classes contain some important business logic. They know how to
// * perform all kinds of operations, associated with carrying out a request. In
// * fact, any class may serve as a Receiver.
// */
//class Receiver {
// public:
//  void DoSomething(const std::string &a) {
//    std::cout << "Receiver: Working on (" << a << ".)\n";
//  }
//  void DoSomethingElse(const std::string &b) {
//    std::cout << "Receiver: Also working on (" << b << ".)\n";
//  }
//};
//
///**
// * However, some commands can delegate more complex operations to other objects,
// * called "receivers."
// */
//class ComplexCommand : public Command {
//  /**
//   * @var Receiver
//   */
// private:
//  Receiver *receiver_;
//  /**
//   * Context data, required for launching the receiver's methods.
//   */
//  std::string a_;
//  std::string b_;
//  /**
//   * Complex commands can accept one or several receiver objects along with any
//   * context data via the constructor.
//   */
// public:
//  ComplexCommand(Receiver *receiver, std::string a, std::string b) : receiver_(receiver), a_(a), b_(b) {
//  }
//  /**
//   * Commands can delegate to any methods of a receiver.
//   */
//  void Execute() const override {
//    std::cout << "ComplexCommand: Complex stuff should be done by a receiver object.\n";
//    this->receiver_->DoSomething(this->a_);
//    this->receiver_->DoSomethingElse(this->b_);
//  }
//};
//
///**
// * The Invoker is associated with one or several commands. It sends a request to
// * the command.
// */
//class Invoker {
//  /**
//   * @var Command
//   */
// private:
//  Command *on_start_;
//  /**
//   * @var Command
//   */
//  Command *on_finish_;
//  /**
//   * Initialize commands.
//   */
// public:
//  ~Invoker() {
//    delete on_start_;
//    delete on_finish_;
//  }
//
//  void SetOnStart(Command *command) {
//    this->on_start_ = command;
//  }
//  void SetOnFinish(Command *command) {
//    this->on_finish_ = command;
//  }
//  /**
//   * The Invoker does not depend on concrete command or receiver classes. The
//   * Invoker passes a request to a receiver indirectly, by executing a command.
//   */
//  void DoSomethingImportant() {
//    std::cout << "Invoker: Does anybody want something done before I begin?\n";
//    if (this->on_start_) {
//      this->on_start_->Execute();
//    }
//    std::cout << "Invoker: ...doing something really important...\n";
//    std::cout << "Invoker: Does anybody want something done after I finish?\n";
//    if (this->on_finish_) {
//      this->on_finish_->Execute();
//    }
//  }
//};
///**
// * The client code can parameterize an invoker with any commands.
// */
//
//int main() {
//  Invoker *invoker = new Invoker;
//  invoker->SetOnStart(new SimpleCommand("Say Hi!"));
//  Receiver *receiver = new Receiver;
//  invoker->SetOnFinish(new ComplexCommand(receiver, "Send email", "Save report"));
//  invoker->DoSomethingImportant();
//
//  delete invoker;
//  delete receiver;
//
//  return 0;
//}











//#include <iostream>
//#include <string>
//#include <vector>
//
//class Category; // forward decalaration, because 'Category' is used before it is defined in 'Transactions', line 14
//
//class Transactions
//{
//	private:
//		double amount;
//		// date and time
//		std::string name;
//		std::string details;
//		Category* category;
//		
//	public:
//		Transactions(std::string name, double amount, std::string details/*, Category *category/* , date and time*/) : amount(amount), name(name), details(details)/*, category(category)*/ {}
//		
//		double getAmount()  // in order to updating/editing
//		{
//			return amount;
//		}
//};
//
//class Category
//{
//	private:
//		std::string name;
//	
//	public:
//		Category(std::string name) : name(name){}
//		
//		std::string getName()
//		{
//			return name;
//		}
//		
//		void addTransaction()
//		{
//			std::string name, details, catName;
//		//	Category* category;
//			double amount;
//			std::cout << "\nEnter the name, amount, details, category";
//			std::cin >> name >> amount >> details/* >> category*/; 
//			
//			std::cout << "\nEnter amount: ";
//			std::cin >> amount;
//			
//			std::cout << "\nEnter details: ";
//			std::cin >> details;
//			
//			std::cout << "\nEnter category: ";
//			std::cin >> catName;
////			Transactions* t(name, amount, details, *category);
//		}
//		
//};
//
//class Budget // for multiple budgets
//{
//	private:
//		std::string name;
//		double limit;
////		double daily;  // a daily spending limit calculated using limit and budget duration, exceeding this will cause it  to be recalculated
////		int duration  // to-do
//		std::vector <Transactions*> transactionVctr;  // a vector to store pointers to 'Transactions' objects
//		std::vector <Category*> categoryVctr; // a vector to store pointers to 'Category' objects
//		
//	public:
//		Budget(std::string name, double limit) : name(name), limit(limit) {}
//		
//		Category* findCategory(std::string catName)  // to search if a category already exists
//		{
//			for (Category* c : categoryVctr)
//			{
//				if (catName == c->getName())
//				{
//					return c;
//				}
//			}
//			
//			return nullptr; // not found, i.e; create new category
//		}
//		
//		void addCategory(std::string catName)
//		{
//			Category* catPtr = findCategory(catName);
//			
//			if (catPtr == nullptr)
//				categoryVctr.push_back(new Category(catName));
//				
//			else
//				std::cout << "\nCategory already exists!";
//		}
//};
//
///* the singleton
//excerpt from Refactoring Guru:
//All implementations of the Singleton have these two steps in common:
//
//    1. Make the default constructor private, to prevent other objects from using the new operator with the Singleton class.
//    2. Create a static creation method that acts as a constructor. Under the hood, this method calls the private constructor to create an object and saves it in a static field. All following calls to this method return the cached object.
//
//If your code has access to the Singleton class, then it’s able to call the Singleton’s static method. So whenever that method is called, the same object is always returned. */
//
//class BudgetManager
//{
//	private:
//		BudgetManager() { std::cout << "Called\n";};
//		std::vector <Budget*> budgetVctr;  // vector to store pointers to 'Budget' objects
//		
//		BudgetManager(const BudgetManager&) = delete;  // deleting copy constructor
//		BudgetManager& operator=(const BudgetManager&) = delete; // deleting assignment operator
//		
//	public:
//		static BudgetManager& getInstance()  // a static mathod to call for
//		{
//			static BudgetManager instance;  // static ensures that its created only once along with the private constructor
//			return instance;
//		}
//};
//
//int main()
//{
//	std::cout << "\n-------- FinaLT --------\n";
//	
//	BudgetManager& manager = BudgetManager::getInstance();  // used a reference because it points to the same instance. Without it, the copy constructor will be invoked, which has been deleted for this class
//	
//	// main menu
//	int choice;
//	std::cout << "1. Add Transaction \t 2. Create a new budget\n";
//	std::cin >> choice;
//	
////	switch (choice)
////	{
////		case 1:
////			
////	}
//	
//}








//#include <iostream>
//#include <string>
//#include <cctype>
//
//int main()
//{
//	float price;
//	
//	float priceArray[] = price;
//}
//


















//// OOP Assignment - ABC Bank Account purpose: a program for banking operations like deposit and withdrawal
//
//#include <iostream>
//
//class bankAccount 
//{ 
//	public:
//		
//		float balance; 
//		int transactions;
//			
//		// adding money to the account
//		void deposit(float amountIN)
//		{
//			balance = balance + amountIN;
//			transactions++; // manually increasing transaction count
//			std::cout << "\nDeposit of " << amountIN << " was successful.";
//		}
//	
//		// taking money out of the account
//		void withdraw(float amountIN)
//		{
//			if (amountIN > balance)
//			{
//				std::cout << "\nError: You do not have enough balance!";
//			}
//			else
//			{
//				balance = balance - amountIN;
//				transactions = transactions + 1;
//				std::cout << "\nWithdrawal of " << amountIN << " was successful.";
//			}
//		}
//	
//		// calculating interest for the period (hardcoded 2.5%)
//		float checkInterest()
//		{
//			float interestEarned;
//			interestEarned = balance * 0.025;
//			return interestEarned;
//		}
//
//};
//
//int main() 
//{ 
//	bankAccount userAccount; userAccount.initialize(1000.0); // starting balance of 1000
//
//	int choice;
//	float inputAmount;
//
//	// using while loop for the menu as it's easier to repeat
//	while (true)
//	{
//		std::cout << "\n\n--- ABC Bank Management System ---";
//		std::cout << "\n1. Display the account balance";
//		std::cout << "\n2. Display the number of transactions";
//		std::cout << "\n3. Display interest earned for this period";
//		std::cout << "\n4. Make a deposit";
//		std::cout << "\n5. Make a withdrawal";
//		std::cout << "\n6. Exit the program";
//	
//		std::cout << "\n\nEnter choice (1-6): ";
//		std::cin >> choice;
//	
//		switch (choice)
//		{
//				case 1:
//			{
//				std::cout << "\nYour current balance is: " << userAccount.balance;
//			}
//	
//			case 2:
//			{
//				std::cout << "\nTotal transactions performed: " << userAccount.transactions;
//			}
//		
//			case 3:
//			{
//				std::cout << "\nInterest earned for this period: " << userAccount.checkInterest();
//			}
//		
//			case 4:
//			{
//				std::cout << "\nEnter amount to deposit: ";
//				std::cin >> inputAmount;
//				userAccount.deposit(inputAmount);
//			}
//		
//			case 5:
//			{
//				std::cout << "\nEnter amount to withdraw: ";
//				std::cin >> inputAmount;
//				userAccount.withdraw(inputAmount);
//			}
//		
//			case 6:
//			{
//				std::cout << "\nExiting... Thank you for using ABC Bank.";
//				break; // breaks out of the while loop
//			}
//		
//			default
//			{
//				std::cout << "\nInvalid input! Please choose between 1 and 6.";
//			}
//		}
//	
//}
//
//}


//#include <iostream>
//void swap(int &x, int &y) { // x and y are references to original variables
//    int temp = x;
//    x = y;
//    y = temp;
//}
//
//int main() {
//    int num1 = 10.2, num2 = 20;
//    std::cout << "Before swap: num1=" << num1 << ", num2=" << num2 << std::endl;
//    swap(num1, num2); // The function modifies num1 and num2 directly
//    std::cout << "After swap: num1=" << num1 << ", num2=" << num2 << std::endl;
//    return 0;
//}
//
//
//
//
















//#include <stdio.h>
//#include <unistd.h>
//
//int main()
//{
//	int num1= 9, num2 = 3, num3 = 2;
//	printf("Result = %d", num3 * num1 / num2);
////	printf("Loading...");	
////	fflush(stdout);
////	for (int i=0; i<=100;i++)
////	{
////		printf("\rProgress: %d%%", i);
////		fflush(stdout);
////		usleep(50000);
////	}
////	printf("\nDone!");
//}







//#include <stdio.h>
//int main(void)
//{
//	int matrix[3][3]={{1,2,3}, {4,5,6}, {7,8,9}};
//	int Count=0;
//	for (int i=0; i<3;i++)
//	{
//		for (int j=0;j<3;j++)
//		{
//			if (matrix[i][j] %2 == 1)
//			{
//				Count++;
//			}
//		}
//	}
//	printf("Numbers are: %d", Count);
//	return 0;
//}





//#include <stdio.h>
//
//void func(int x);
//
//int main(void)
//{
//	func(5);
//	func(5);
//	return 0;
//}
//
//void func(int x)
//{
//
//	static int a=1;
//	a =a *x;
//	printf("a=%d \nx=%d \n", a, x);
//}


//#include <stdio.h>
//
//int main(void)
//{
//	int matrix[2][3] = {{1,2,3},{4,5,6}};
//	int *ptr = &matrix[0][0];
//	printf("%d", *(ptr+4));
//	return 0;
//}


















//#include <stdio.h>
//int main(void)
//{
//	int array[10] = {3,0,8,1,12,8,9,2,13,10}, x, y, z;
//	x = ++array[2];
//	y = array[2]++;
//	z = array[x++];
//	
//	printf("%d %d %d", x,y,z);
//}



//#include <stdio.h>
//#include <string.h>
//
//int main() {
//    char str[100], rev[100];
//    int len, i;
//
//    printf("Enter a string: ");
//    gets(str);  // use fgets in real code
//
//    len = strlen(str);
//
//    // reverse the string
//    for(i = 0; i < len; i++) {
//        rev[i] = str[len - 1 - i];
//    }
//    rev[len] = '\0';
//
//    // compare both
//    if(strcmp(str, rev) == 0)
//        printf("Palindrome\n");
//    else
//        printf("Not Palindrome\n");
//
//    return 0;
//}









//#include <stdio.h>
//
//int count_vowels(char str[]);
//
//int main(void)
//{
//	char str[500];
//	printf("Enter a string: ");
//	fgets(str, sizeof(str), stdin);
//	int count = count_vowels(str);
//	printf("Vowels = %d", count);
//	
//	return 0;
//}
//
//int count_vowels(char str[])
//{
//	int count = 0;
//	for (int i =0; i<str[i] != '\0'; i++)
//	{
//		char ch = str[i];
//		if (ch >= 'A' && ch <= 'Z')
//		{
//			ch += 32;
//		}
//		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' )
//		{
//			count++;
//		}
//	}
//	return count;
//}
//
//


















//#include <stdio.h>
//int main(void)
//{
//	for (int i = 1; i<=4; i++)
//	{
//		for (int space = 0; space <4-i; space++)
//		{
//			printf(" ");
//		}
//		for (int j=0; j<2*i-1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//int i, j, space, rows = 4;
//for (i = 1; i <= rows; i++) {
//        // Print leading spaces
//        for (space = 1; space <= rows - i; space++) {
//            printf(" ");
//        }
//        // Print asterisks
//        for (j = 1; j <= 2 * i - 1; j++) {
//            printf("*");
//        }
//        printf("\n");
//    }
//}
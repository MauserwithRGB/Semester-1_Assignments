// OOP Theory assignment:            create 3 classses, implement everything learned so far

#include <iostream>
#include <string>
#include <vector>

class book
{
	private:
		const int bookID;
		std::string Title;
		std::string Author;
		float Price;
		static inline int totalBooks = 0;   // in c++ 17, the keyword 'inline' is introduced. Using that we can define  a static variable in a single line; no need for separate declaration and definition.
		int copies;
		
		// private methods
		float inputPrice()
		{
			float price;
			std::cout << "\nEnter the price for the book: ";
			std::cin >> price;
			
			while (std::cin.fail())  // inside the cin class, theres a fail() method. Its a bool that returns true if cin failed to stored the value inside the given variable. In this case its a float. If a user enters an alphabet, it will throw an error
			{
				std::cout << "\nInvalid price!\nTry again.\n";
				
				std::cin.clear();    // another method inside cin. it sets the state of cin from 'failed' to 'good'
				std::cin.ignore(64, '\n');  // again, a method. this ignores the input for a given number of characters (1st argument) or until the delimiter character (2nd argument) is encountered
				std::cin >> price;   // takes input again
			}
			
			while (price < 0)  // Constraint : price cannot be negative
			{
				std::cout << "\nInvalid price!\nTry again.\n";
				
				std::cin.clear();
				std::cin.ignore(64, '\n');
				std::cin >> price;
			}
			
			return price;
		}
		
		void setBookPrice(float price)  
		{
			this -> Price = price;
		}
		
	public:
		
		book(int idBook, std::string Title, std::string Author) : bookID(idBook)
		{
			this -> Title = Title;
			this -> Author = Author;
			this -> copies = 1;  // set to 1 due to the scope of this question
			Price = 0;  // i set the default price to 0; i.e it is free and because theres no validation here. below is a setter for price that needs to be called each time price is to be set
			totalBooks++; // incremented upon instantiation
			
		}
		
		int getBookID()
		{
			return bookID;
		}
		
		std::string getTitle()
		{
			return Title;
		}
		
		std::string getAuthor()
		{
			return Author;
		}
		
		float getPrice()
		{
			return Price;
		}
		
		static int getTotalBooks() // static function for a static variable
		{
			return totalBooks;
		}
		
		void setPrice()
		{
			setBookPrice(inputPrice());
		}
		
		bool isAvailable()  //  to check book availability
		{
			if (copies > 0)
				return true;
				
			return false;
		}
		
		void setNA()
		{
			copies = 0;
		}
};

class member
{
	private:
		int memberID;
		std::string Name;
		const static inline int bookLimit = 5;
		int booksBorrowed;
		static inline int totalMembers = 0;
		
	public:
		member(int memberID, std::string memberName)
		{
			this -> memberID = memberID;
			this -> Name = Name;
			totalMembers++;  // increments totalMembers upon instantiation
			booksBorrowed = 0; 
		}
		
		int getMemberID()
		{
			return memberID;
		}
		
		std::string getName()
		{
			return Name;
		}
		
		static int getTotalMembers()
		{
			return totalMembers;
		}
		
		int getBooksBorrowed()
		{
			return booksBorrowed;
		}
		
		static int getBookLimit()  // static function for a static variable
		{
			return bookLimit;
		}
		
		void newBookBorrowed()
		{
			booksBorrowed++;
		}
};

class library
{
	public:
		std::vector <member*> memberList;  // both these vectors store pointers to the objects. This makes updating their data easier
		std::vector <book*> bookList;
		
		void addM(member* newMember)
		{
			memberList.push_back(newMember);
		}
		
		void addB(book* newBook)
		{
			bookList.push_back(newBook);
		}
		
		const void displayB()
		{
			std::cout << "\nTotal books in this library: " << book::getTotalBooks() << "\n\n";
			for (book *i : bookList)
			{
				std::cout << "Title: " << i -> getTitle() << "\t|\tAuthor: " << i -> getAuthor() << "\t|\tBook ID:" << i -> getBookID() << "\t|\tPrice: $ " << i -> getPrice() << "\n\n";
			}
		}
		
		const void displayM()
		{
			std::cout << "\nTotal members registered with the library: " << member::getTotalMembers() << "\n\n";
			
			for (member* i : memberList)
				std::cout << "Name: " << i -> getName() << "\t|\tMember ID: " << i -> getMemberID() << "\t|\tBooks Borrowed: " << i -> getBooksBorrowed() << "\n\n";
		}
		
		void issueB(book &Book, member &Member)
		{
			if (Book.isAvailable() && Member.getBooksBorrowed() < member::getBookLimit())
				{
					Member.newBookBorrowed();
					Book.setNA();
				}
			else if (!Book.isAvailable())
				std::cout << "\n" << Book.getTitle() << " is already issued, and is not available, currently.";
			
			else if (Member.getBooksBorrowed() == member::getBookLimit())
				std::cout << "\n" << Member.getName() << " has reached the book borrowing limit.";
				
			else
				std::cout << "\n\nERROR\n\n";
		}
};

int main()
{
	library library1;
	member member1(1, "Muneeb");
	library1.addM(&member1);
	
	book book1(92, "BOOK1", "AUTHOR1");
	library1.addB(&book1);
	
	library1.displayM();
	
	library1.issueB(book1, member1);
	library1.displayB();
	
	book1.setPrice();
	library1.displayB();
	
	library1.issueB(book1, member1);
	library1.displayM();
}
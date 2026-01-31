// OOP Theory assignment:            create 3 classses, implement everything learned so far
// This is still far from complete, i couldn't complete it in time (2026/01/31 11:59pm). Partially because i added things the question didn't ask for and got a bit ambitious, almost took it as a passion project

#include <iostream>
#include <string>
#include <vector>

class book
{
	private:
		const int bookID;
		std::string bookTitle;
		std::string bookAuthor;
		float bookPrice;
		static inline int totalBooks = 0;   // in c++ 17, the keyword 'inline' is introduced. Using that we can define  a static variable in a single line; no need for separate declaration and definition.
		bool bookAvailable = false;   // book availability flag, false by default for safe-keeping
		
		
	public:
		int bookCopies;    // the total numbe of copies available. I had to make this public because the getter would create issues with line 193; i couldn't decrement. So for the sake of simplicity i chose this way
		
		book(int idBook, std::string bookTitle, std::string bookAuthor, int bookCopies) : bookID(idBook)
		{
			this -> bookTitle = bookTitle;
			this -> bookAuthor = bookAuthor;
			this -> bookCopies = bookCopies;
			bookPrice = 0;  // i set the default price to 0; i.e it is free. below is a setter for price that needs to be called each time price is to be set
			bookAvailable = true;  // when the object is created it becomes true
			totalBooks++; // incremented upon instantiation
			
		}
		
		int getBookID()
		{
			return bookID;
		}
		
		std::string getBookTitle()
		{
			return bookTitle;
		}
		
		std::string getBookAuthor()
		{
			return bookAuthor;
		}
		
		float getBookPrice()
		{
			return bookPrice;
		}
		
		static int getTotalBooks()
		{
			return totalBooks;
		}
		
		bool isBookAvailable()  //  to check book availability
		{
			if (bookAvailable)
				return true;
				
			return false;
		}
		
		void setBookFalse()   // flag for book availability. I also had to make these flags because the private bool bookAvailable creates issues. Before, i had it public
		{
			bookAvailable = false;
		}
		
		void setBookTrue()  // flag for book availability.
		{
			bookAvailable = true;
		}
				
		void setBookPrice()  // this is also incomplete, 
		{
			float price;
			std::cout << "\nEnter the price for the book: ";
			std::cin >> price;
			
			while (std::cin.fail())  // the logic:  inside the cin class, theres a fail() method. Its a bool that returns true if cin failed to stored the value inside the given variable. In this case its a float. If a user enters an alphabet, it will throw an error
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
			
			bookPrice = price;
		}
};

class member
{
	private:
		int memberID;
		std::string memberName;
		const static inline int bookLimit = 5;  // i dont really understand what inline means right now, but it lets me initialize a const static without any headache
		int booksBorrowed;
		static int totalMembers;
		
	public:
		member(int memberID, std::string memberName)
		{
			this -> memberID = memberID;
			this -> memberName = memberName;
			totalMembers++;  // when a new object is created, a constructor is called, and when the constructor is called it increments totalMembers by 1
			booksBorrowed = 0; 
		}
		
		int getMemberID()
		{
			return memberID;
		}
		
		std::string getMemberName()
		{
			return memberName;
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
		
		void setBooksBorrowed()
		{
			booksBorrowed++;
		}
};

int member::totalMembers = 0;

class library
{
	public:
		std::vector <member> memberList;
		std::vector <book> bookList;
		
		void addMember(member newMember)
		{
			memberList.push_back(newMember);
		}
		
		void addBook(book newBook)
		{
			bookList.push_back(newBook);
		}
		
		const void displayBooks()  // needs proper formatting and details
		{
			std::cout << "Total books in this library: " << book::getTotalBooks() << "\n\n";
			for (book &i : bookList)
			{
				std::cout << "Title: " << i.getBookTitle() << "    |    Author: " << i.getBookAuthor() << "    |    Book ID:" << i.getBookID() << "    |    Price: $ " << i.getBookPrice() << "\n\n";
			}
		}
		
		const void displayMembers()  // needs proper formatting and details
		{
			std::cout << "Total members registered with the library: " << member::getTotalMembers() << "\n\n";
			
			for (member &i : memberList)
				std::cout << "Name: " << i.getMemberName() << "    |    Member ID: " << i.getMemberID() << "    |    Books Borrowed: " << i.getBooksBorrowed() << "\n\n";
		}
		
		void issueBook(int bookIndex, book &Book, member &Member)  // the index of the book in bookList vetcor is passed
		{
			if (Book.bookCopies == 0)
			{	
				Book.setBookFalse();
				std::cout << "\nBook is not available!";
				return;
			}
			
			else if (Book.isBookAvailable() && Member.getBooksBorrowed() < member::getBookLimit())
				{
					Member.setBooksBorrowed();
					Book.bookCopies--;
				}
		}
};

int main()  // main() is also incomplete
{
	library library1;
	member member1(1, "Muneeb");
	
	book book1(92, "BOOK1", "AUTHOR1", 3);
	
	library1.addBook(book1);
	library1.addMember(member1);
	
	library1.displayMembers();  // testing ouput, 1st working test 8:54pm, 2026/01/30
	
	library1.issueBook(1, book1, member1);
	library1.displayBooks();
	
	library1.bookList[0].setBookPrice();  // cant improve upon this due to the time limit. Here, the book instance inside the vector bookList is getting updating, and thats how it should work. The problem is that bookList stores copies of the instances, so the original book instance stays the same. This requires pointers for it to be efficient 
	library1.displayBooks();
	
}








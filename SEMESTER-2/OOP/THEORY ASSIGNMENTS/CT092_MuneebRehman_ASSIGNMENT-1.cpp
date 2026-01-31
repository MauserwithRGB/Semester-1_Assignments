// OOP Theory assignment:            create 3 classses, implement everything learned so far

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
		static int totalBooks;   // in c++ 17, the keyword 'inline' is introduced. Using that we can define  a static variable in a single line; no need for separate declaration and definition. but this is c++14 :(
		
	public:
		bool bookAvailable = false;   // book availability flag, false by default for safe-keeping
		int bookCopies;    // the total numbe of copies available
		
		book(int idBook, std::string bookTitle, std::string bookAuthor, int bookCopies) : bookID(idBook)
		{
			this -> bookTitle = bookTitle;
			this -> bookAuthor = bookAuthor;
			this -> bookCopies = bookCopies;
			bookPrice = 0;
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
		
//		void setBookPrice(float priceBook)
//		{
//			if (priceBook >= 0)
//			
//		}
};
int book::totalBooks = 0;  // definition for static variable


class member
{
	private:
		int memberID;
		std::string memberName;
		const int booksLimit = 5;
		int booksBorrowed;
		static int totalMembers;
		
	public:
		member(int memberID, std::string memberName) : booksLimit(5)
		{
			this -> memberID = memberID;
			this -> memberName = memberName;
			totalMembers++;  // when a new object is called,a constructor is called, and when the constructor is called it increments totalMembers by 1
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
		
		void addMember(const member &newMember)
		{
			memberList.push_back(newMember);
		}
		
		void addBook(const book &newBook)
		{
			bookList.push_back(newBook);
		}
		
		const void displayBooks()  // needs proper formatting and details
		{
			std::cout << "Total books in this library: " << book::getTotalBooks() << "\n\n";
			for (book &i : bookList)
			{
				std::cout << i.getBookTitle() << "    |    " << i.getBookAuthor() << "    |    " << i.getBookID() << "    |    " << i.getBookPrice() << "\n\n";
			}
		}
		
		const void displayMembers()  // needs proper formatting and details
		{
			std::cout << "Total members registered with the library: " << member::getTotalMembers() << "\n\n";
			
			for (member &i : memberList)
				std::cout << i.getMemberName() << "    |    " << i.getMemberID() << "    |    " << i.getBooksBorrowed() << "\n\n";
		}
		
		void issueBook(int bookIndex, book &Book, member &Member)  // the index of the book in bookList vetcor is passed
		{
				if (Member.getBooksBorrowed() + 1 <= 5)
				{
					Member.setBooksBorrowed();
					Book.bookCopies--;
					
					if (Book.bookCopies == 0)
						Book.bookAvailable = false;
				}
		}
};

int main()
{
	library library1;
	member member1(1, "Muneeb");
	
	book book1(92, "BOOK1", "AUTHOR1", 3);
	
	library1.addBook(book1);
	library1.addMember(member1);
	
	library1.displayMembers();  // testing ouput, 1st working test 8:54pm, 2026/01/30
	
	library1.issueBook(1, book1, member1);
	library1.displayBooks();
	
}








#include <iostream>
#include <string>

class Media
{
protected:
    std::string title;
    bool borrowed;
public:
    Media(std::string t) : title(t), borrowed(false) {}
    void borrow() {
        if (!borrowed) { borrowed = true;  std::cout << title << " borrowed.\n"; }
        else             std::cout << title << " is already borrowed.\n";
    }
    void returnMedia() {
        if (borrowed) { borrowed = false; std::cout << title << " returned.\n"; }
        else            std::cout << title << " was not borrowed.\n";
    }
    virtual void display() = 0;
    virtual ~Media() {}
};

class Book : public Media
{
    std::string author;
public:
    Book(std::string t, std::string a) : Media(t), author(a) {}
    void display() override {
        std::cout << "=== Book ===\n"
                  << "Title: "    << title    << "\n"
                  << "Author: "   << author   << "\n"
                  << "Status: "   << (borrowed ? "Borrowed" : "Available") << "\n";
    }
};

class Magazine : public Media
{
    int issueNumber;
public:
    Magazine(std::string t, int issue) : Media(t), issueNumber(issue) {}
    void display() override {
        std::cout << "=== Magazine ===\n"
                  << "Title: "  << title       << "\n"
                  << "Issue: "  << issueNumber << "\n"
                  << "Status: " << (borrowed ? "Borrowed" : "Available") << "\n";
    }
};

class DVD : public Media
{
    std::string director;
public:
    DVD(std::string t, std::string d) : Media(t), director(d) {}
    void display() override {
        std::cout << "=== DVD ===\n"
                  << "Title: "    << title    << "\n"
                  << "Director: " << director << "\n"
                  << "Status: "   << (borrowed ? "Borrowed" : "Available") << "\n";
    }
};

int main()
{
    Book book("The Hobbit", "J.R.R. Tolkien");
    Magazine mag("National Geographic", 245);
    DVD dvd("Inception", "Christopher Nolan");

    book.display();
    book.borrow();
    book.borrow();  // try borrowing again
    book.returnMedia();

    std::cout << "\n";
    mag.display();
    mag.borrow();

    std::cout << "\n";
    dvd.display();
    dvd.borrow();
    dvd.returnMedia();
}
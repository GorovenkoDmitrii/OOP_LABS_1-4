#include <iostream>
#include <vector>
using namespace std;
class Book {
private:
    string author;
    string title;
    bool isFiction;
public:
    Book(string author, string title, bool isFiction) :
        author(author), title(title), isFiction(isFiction) {}
    string getAuthor() const { return author; }
    string getTitle() const { return title; }
    bool getIsFiction() const { return isFiction; }
};
class Library {
private:
    vector<Book> books;
public:
    void addBook(const Book& book) { books.push_back(book); }
    void printBooks() const {
        for (const Book& book : books) {
            cout << "Author: " << book.getAuthor() << endl;
            cout << "Title: " << book.getTitle() << endl;
            cout << "Type: " << (book.getIsFiction() ? "Fiction" : "Non-Fiction") << endl;
        }
    }
};
int main() {
    Library library;
    library.addBook(Book("George Orwell", "1984", true));
    library.addBook(Book("Ray Bradbury", "Fahrenheit 451", true));
    library.addBook(Book("Jane Austen", "Pride and Prejudice", true));
    library.addBook(Book("Arthur C. Clarke", "2001: A Space Odyssey", false));
    library.addBook(Book("Isaac Asimov", "Foundation", false));
    library.addBook(Book("Richard Feynman", "Surely You're Joking, Mr. Feynman!", false));
    library.printBooks();
}
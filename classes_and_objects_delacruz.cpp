#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100; // max number supposedly

class Book {
    private:
        string title;
        string author;
        int year;

    public:
        // constructor here
        Book() {
            title = " ";
            author = " ";
            year = 0;
        }

        // setter here
        void setTitle(string t) {
            title = t;
        }

            void setAuthor(string a) {
                author = a;
            }

                void setYear(int y) {
                    year = y;
                }

        // get stuff here
        string getTitle() const {
            return title;
        }

            string getAuthor() const {
                return author;
            }

                int getYear() const {
                    return year;
                }

        // Display Book Details
        void displayBook() const {
            cout << title << "\t" << author << "\t" << year << endl;
        }
};

class Library {
    private:
        Book books[MAX_BOOKS]; // array for books
        int bookCount;       

    public:
    
        Library() {
            bookCount = 0;
        }

        // add books here
        void addBook() {
            if (bookCount < MAX_BOOKS) {
                string title, author;
                     int year;

                cout << "Enter title: ";
                      cin.ignore(); 
                           getline(cin, title);

                            cout << "Enter author: ";
                                getline(cin, author);

                                cout << "Enter year: ";
                                        cin >> year;

                books[bookCount].setTitle(title);
                      books[bookCount].setAuthor(author);
                            books[bookCount].setYear(year);

                bookCount++;

                cout << "Book added successfully!" << endl;

            } 
            
            else {
                cout << "Library is full! Cannot add more books." << endl;
            }
        }
   
        void displayBooks() const {
            if (bookCount == 0) {
               
                cout << "No books available." << endl;
                
                return;
            }

            cout << "Book List:" << endl;

                     cout << "Title\t\t\tAuthor\t\tYear" << endl;

            for (int i = 0; i < bookCount; i++) {

                books[i].displayBook();

            }
        }

        void searchBook() const {
            
            string searchTitle;

                cout << "Enter a book to search: ";

            cin.ignore(); 
                
                getline(cin, searchTitle);

            for (int i = 0; i < bookCount; i++) {

                if (books[i].getTitle() == searchTitle) {

                    cout << "Book found!" << endl;

                         cout << "Title: " << books[i].getTitle() << endl;

                            cout << "Author: " << books[i].getAuthor() << endl;

                                cout << "Year: " << books[i].getYear() << endl;
                        return;

                }
            }

            cout << "Book not found!" << endl;
        }
};

int main() {
    Library library;
    int choice;

    do {
        // Display menu
        cout << "Menu: " << endl;
            cout << "1 - Add Book" << endl;
                cout << "2 - Display Books" << endl;
                    cout << "3 - Search Book" << endl;
                        cout << "4 - Exit" << endl;
                            cout << "Enter your choice: ";
        
        cin >> choice;

        switch (choice) {
           
            case 1:
                library.addBook();
                break;

            case 2:
                library.displayBooks();
                break;

            case 3:
                library.searchBook();
                break;

            case 4:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;

    } while (choice != 4);

    return 0;
}

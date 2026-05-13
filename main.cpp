#include <iostream>
#include <fstream>
using namespace std;

class Book {
private:
    int bookId;
    string title;
    string author;
    int quantity;

public:
    void addBook() {
        cout << "Enter Book ID: ";
        cin >> bookId;

        cin.ignore();
        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    void displayBook() {
        cout << "\nBook ID  : " << bookId;
        cout << "\nTitle    : " << title;
        cout << "\nAuthor   : " << author;
        cout << "\nQuantity : " << quantity << endl;
    }

    int getBookId() {
        return bookId;
    }

    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }

    void issueBook() {
        if (quantity > 0) {
            quantity--;
            cout << "Book issued successfully!\n";
        } else {
            cout << "Book not available!\n";
        }
    }

    void returnBook() {
        quantity++;
        cout << "Book returned successfully!\n";
    }

    void saveToFile() {
        ofstream file("library.txt", ios::app);

        file << bookId << endl;
        file << title << endl;
        file << author << endl;
        file << quantity << endl;

        file.close();
    }
};

int main() {
    Book books[50];
    int count = 0;
    int choice, id;
    string searchText;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Search Book by Title\n";
        cout << "6. Search Book by Author\n";
        cout << "7. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            books[count].addBook();
            books[count].saveToFile();
            count++;
            cout << "Book added successfully!\n";
            break;

        case 2:
            if (count == 0) {
                cout << "No books available!\n";
            } else {
                for (int i = 0; i < count; i++) {
                    books[i].displayBook();
                }
            }
            break;

        case 3:
            cout << "Enter Book ID to Issue: ";
            cin >> id;

            for (int i = 0; i < count; i++) {
                if (books[i].getBookId() == id) {
                    books[i].issueBook();
                    break;
                }
            }
            break;

        case 4:
            cout << "Enter Book ID to Return: ";
            cin >> id;

            for (int i = 0; i < count; i++) {
                if (books[i].getBookId() == id) {
                    books[i].returnBook();
                    break;
                }
            }
            break;

        case 5:
            cin.ignore();
            cout << "Enter Title to Search: ";
            getline(cin, searchText);

            for (int i = 0; i < count; i++) {
                if (books[i].getTitle() == searchText) {
                    books[i].displayBook();
                }
            }
            break;

        case 6:
            cin.ignore();
            cout << "Enter Author to Search: ";
            getline(cin, searchText);

            for (int i = 0; i < count; i++) {
                if (books[i].getAuthor() == searchText) {
                    books[i].displayBook();
                }
            }
            break;

        case 7:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Book
{
    int bookID;
    string title;
    string author;
    bool issued;

public:
    Book(int id = 0, string t = "", string a = "", bool i = false)
    {
        bookID = id;
        title = t;
        author = a;
        issued = i;
    }

    int getBookID() const
    {
        return bookID;
    }
    string getTitle() const
    {
        return title;
    }
    string getAuthor() const
    {
        return author;
    }
    bool isIssued() const
    {
        return issued;
    }

    void issueBook()
    {
        issued = true;
    }
    void returnBook()
    {
        issued = false;
    }

    void saveToFile(ofstream &out) const
    {
        out.write((char *)this, sizeof(Book));
    }

    void loadFromFile(ifstream &in)
    {
        in.read((char *)this, sizeof(Book));
    }
};

class Library
{
    vector<Book> books;
    const string fileName = "library.dat";

public:
    Library()
    {
        loadBooksFromFile();
    }

    void addBook(int id, string title, string author)
    {
        Book book(id, title, author, false);
        books.push_back(book);

        ofstream file(fileName, ios::binary | ios::app);
        if (file.is_open())
        {
            book.saveToFile(file);
            file.close();
        }
        else
        {
            cout << "Error: Unable to open file for writing!" << endl;
        }
    }

    void showBooks() const
    {
        cout << "\n<<<<< Library Books >>>>>\n";
        for (const auto &book : books)
        {
            cout << "ID: " << book.getBookID() << " | Title: " << book.getTitle()
                 << " | Author: " << book.getAuthor()
                 << " | Status: " << (book.isIssued() ? "Issued" : "Available") << endl;
        }
    }

    void issueBook()
    {

    }

    void returnBook()
    {

    }

    void modifyBook()
    {

    }

    void deleteBook()
    {

    }

private:
    void loadBooksFromFile()
    {
        ifstream file(fileName, ios::binary);
        if (file.is_open())
        {
            Book book;
            while (file.read((char *)&book, sizeof(Book)))
            {
                books.push_back(book);
            }
            file.close();
        }
    }

    void saveBooksToFile()
    {
        ofstream file(fileName, ios::binary | ios::trunc);
        if (file.is_open())
        {
            for (const auto &book : books)
            {
                book.saveToFile(file);
            }
            file.close();
        }
        else
        {
            cout << "Error: Unable to save books to file!" << endl;
        }
    }
};

int main()
{
    Library library;

    char choice;
    do
    {
        cout << "\n<<<<< Library Management System >>>>>\n";
        cout << "1. Show Books\n";
        cout << "2. Add New Book\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Modify Book\n";
        cout << "6. Delete Book\n";
        cout << "7. Exit\n";
        cout << "Select your option (1-7): ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            library.showBooks();
            break;
        case '2':
        {
            int id;
            string title, author;
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            library.addBook(id, title, author);
            break;
        }
        case '3':
            library.issueBook();
            break;
        case '4':
            library.returnBook();
            break;
        case '5':
            library.modifyBook();
            break;
        case '6':
            library.deleteBook();
            break;
        case '7':
            cout << "Exiting the system. Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
    while (choice != '7');

    return 0;
}

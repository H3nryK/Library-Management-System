#include <iostream>
#include <string>
#include <iomanip>

const int MAX_BOOKS =15;

class Book
{
public:
    std::string author;
    double price;
    std::string title;
    std::string publisher;
    int accountNumber;
    int numCopies;

    void display() const
    {
        std::cout<<std::setw(20)<<std::left<< " Title: "<<title<<"\n";
        std::cout<<std::setw(20)<<std::left<< " Author: "<<author<<"\n";
        std::cout<<std::setw(20)<<std::left<< " Price: Ksh."<<std::fixed<<std::setprecision(2)<<price<<"\n";
        std::cout<<std::setw(20)<<std::left<< " Publisher: "<<publisher<<"\n";
        std::cout<<std::setw(20)<<std::left<< " Account Number: "<<accountNumber<<"\n";
        std::cout<<std::setw(20)<<std::left<< " Number of Copies: "<<numCopies<<"\n\n";
    }
};

class Books
{
private:
    Book database[MAX_BOOKS];
    int numBooks;

public:
    Books() : numBooks(0){}

    void insertBook(const Book& book)
    {
        if (numBooks < MAX_BOOKS)
        {
            database[numBooks++] = book;
            std::cout<< " Book inserted successfully.\n\n";
        }else{
            std::cout<< " Database is full. Cannot insert more books.\n\n";
        }
    }

    void displayBooks()
    {
        if (numBooks ==  0)
        {
            std::cout<< " The database is empty.\n";

        }else{
            std::cout<< " List of all "<<numBooks<<" books in the database: \n\n";
            for (int i=0; i<numBooks; ++i)
            {
                database[i].display();
            }
        }
    }
};

int main()
{
    std::cout<<"\n**********************************************************************\n";
    std::cout<<"                          Library Management System\n";
    std::cout<<"**********************************************************************\n\n";

    Books library;

    // Test inserting a new book
    Book newBook;
    newBook.author="Kimani";
    newBook.price=1500;
    newBook.title="Wonders of my world";
    newBook.publisher="JKF";
    newBook.accountNumber=12233;
    newBook.numCopies=22;

    Book neBook;
    neBook.author="Henry";
    newBook.price=1780;
    newBook.title="Buddy";
    neBook.publisher="JKF";
    neBook.accountNumber=77833;
    neBook.numCopies=7;

    library.insertBook(newBook);
    library.insertBook(neBook);

    //  Test displaying all books
    library.displayBooks();

    return 0;
}

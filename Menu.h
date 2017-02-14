#ifndef MENU_H
#define MENU_H


class Menu
{
    public:
        Menu() {}
        virtual ~Menu() {}


#include "Member.h"
#include "Library.h"
#include <iostream>

using namespace std;
class Menu
{
public:
    Menu() {}
    virtual ~Menu() {}

    void menuMain()
    {
        bool condition = true;
        Library lib;
        do
        {

            int option;
            cout << "Enter your option: " << endl;
            cout << "1 for adding a new member" << endl;
            cout << "2 for searching a member" << endl;
            cout << "3 for adding books" << endl;
            cout << "4 for searching a book by title" << endl;
            cout << "5 for searching a book by author" << endl;
            cout << "6 for searching a book by bookId" << endl;
            cout << "7 for issuing a book" << endl;
            cout << "8 to print all books" << endl;
            cout << "9 to print all members: " << endl;
            cout << "10 to exit" << endl;
            cin >> option;
            cin.sync();


                if(option == 1)
                {
                    lib.addMembers();
                }
                if(option == 2)
                {
                    string memname;
                    cout << "Enter the Member's name to search: " << endl;
                    cin >> memname;
                    lib.printAMember(memname);

                }
                if(option == 3)
                {
                    lib.addBooks();

                }
                if(option == 4)
                {
                    string bookname;
                    cout << "Enter the book name: " << endl;
                    lib.searchBookByTitle(bookname);

                }
                if(option == 5)
                {
                    string bookAuthor;
                    cout << "Enter the book author: " << endl;
                    lib.searchBookByAuthor(bookAuthor);

                }
                if(option == 6)
                {
                    string bookId;
                    cout << "Enter the book Id: " << endl;
                    lib.searchBookById(bookId);

                }
                if(option == 7)
                {
                    //Issue
                    string memName, bookTitle;
                    cout << "Enter the member name: "<< endl;
                    cin >> memName;
                    cout << "Enter the book title: " << endl;
                    cin >> bookTitle;
                    lib.issueBookHere(memName, bookTitle);


                }
                 if(option == 8)
                {
                    lib.printAllBooks();

                }
                if(option == 9)
                {
                    lib.printAllMembersInfo();

                }
                if(option == 10)
                {
                    condition = false;

                }


        }while(condition == true);
    }





protected:

private:
};
#endif // MENU_H

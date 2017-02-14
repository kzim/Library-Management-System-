#ifndef LIBRARY_H
#define LIBRARY_H
#include <Books.h>
#include <Member.h>
#include <Student.h>
#include <Faculty.h>
static int sId, fId;
class Library
{
    public:
        Library() {}
        virtual ~Library() {}

        //Adds Members
        void addMembers()
        {
            Student student; Faculty faculty;
            string input; int inputNo;
            char option;

            cout << endl;
            cout << "To register a Student, press 1. To register a Faculty member, press 2." << endl;
            cout << endl;
            cin >> option;
            cin.sync();

            if(option == '1')
            {
                cout << endl;
                cout << "Enter your complete name below: " << endl;
                cout << endl;
                getline(cin, input);
                student.setName(input);

                cout << endl;
                cout << "Enter your complete address: " << endl;
                cout << endl;
                getline(cin, input);
                student.setAddress(input);

                cout << endl;
                cout << "Enter your phone number (excluding the starting 0): " << endl;
                cout << endl;
                cin >> inputNo;
                student.setPhoneNo(inputNo);

                sId++;
                student.setStudentId(sId);
                cout << endl;
                cout << "Your Member Id is: " << sId << endl;
                cout << endl;

                listOfMembers.push_back(student);

                cout << endl;
                cout << "Member Added Successfully." << endl;
                cout << endl;
                cout << endl;
            }

            if(option == '2')
            {
                cout << endl;
                cout << "Enter your complete name below: " << endl;
                getline(cin, input);
                faculty.setName(input);

                cout << endl;
                cout << "Enter your complete address: " << endl;
                getline(cin, input);
                faculty.setAddress(input);

                cout << endl;
                cout << "Enter your 11-digit phone number (excluding the starting 0): " << endl;
                cin >> inputNo;
                faculty.setPhoneNo(inputNo);

                fId++;
                faculty.setFacultyId(fId);
                cout << endl;
                cout << "Your Member Id is: " << fId << endl;
                cout << endl;

               listOfMembers.push_back(faculty);

               cout << "Done Adding the member" << endl;
            }

        }

        //Searches the member, given a name
        int findMember(string memName)
        {
            for(int i = 0; i < listOfMembers.size(); i++)
               {
                    if(listOfMembers.at(i).getName() == memName)
                        {
                            return i;

                        }
                    i++;
                }
            return -1;
        }


        //Prints all the Members with their information
        void printAllMembersInfo()
        {
            for(int i = 0; i < listOfMembers.size(); i++)
            {
                cout << "Member Name: " << listOfMembers.at(i).getName() << endl;
                cout << "Member Contact-No: " << listOfMembers.at(i).getPhoneNo() << endl;
                cout << "Member Address: " << listOfMembers.at(i).getAddress() << endl;
            }
        }

        //prints a particular member information, given the name
        void printAMember(string memname)
        {
            int index = findMember(memname);
            if(index != -1)
            {
                cout << "Member Name: " << listOfMembers.at(index).getName() << endl;
                cout << "Member Contact-No: " << listOfMembers.at(index).getPhoneNo() << endl;
                cout << "Member Address: " << listOfMembers.at(index).getAddress() << endl;

            }
            else
            {
                cout<<"Member not found"<<endl;
            }
        }

        //Adds Books
        void addBooks()
        {

            Books book;
            cout << "Enter the book title: " << endl; string input;
            getline(cin, input);
            book.setBookTitle(input);

            cout << "Enter the book author: " << endl;
            getline(cin, input);
            book.setAuthor(input);

            cout << "Enter the book edition: " << endl;
            getline(cin, input);
            book.setBookEdition(input);

            cout << "Enter the book ID: " << endl;
            cin >> input;
            book.setBookId(input);

            listOfBooks.push_back(book);

            cout<<"Book Added to Library"<<endl;
        }

        // Search the book by title
        int searchBookByTitle(string bookname)
        {
          for(int i = 0; i < listOfBooks.size(); i++)
           {
                if(listOfBooks.at(i).getBookTitle() == bookname)
                    {
                        cout << "Information of the book with the mentioned title: " << endl;
                        cout << endl;
                        cout << "Title: " << listOfBooks.at(i).getBookTitle() << endl;
                        cout << "Author: " << listOfBooks.at(i).getBookAuthor() << endl;
                        cout << "Edition: " << listOfBooks.at(i).getBookEdition() << endl;
                        return i;
                    }
                i++;
            }
            return -1;
        }

         // Search the book by author
        int searchBookByAuthor(string author)
        {
           for(int i = 0; i < listOfBooks.size(); i++)
           {
                if(listOfBooks.at(i).getBookAuthor() == author)
                    {
                        cout << "Information of the book with the mentioned author: " << endl;
                        cout << endl;
                        cout << "Title: " << listOfBooks.at(i).getBookTitle() << endl;
                        cout << "Author: " << listOfBooks.at(i).getBookAuthor() << endl;
                        cout << "Edition: " << listOfBooks.at(i).getBookEdition() << endl;

                        return i;
                    }
                i++;
            }
            return -1;
        }

         // Search the book by Id
        int searchBookById(string id)
        {
           for(int i = 0; i < listOfBooks.size(); i++)
           {
                if(listOfBooks.at(i).getBookId() == id)
                    {
                        cout << "Information of the book with the mentioned Id: " << endl;
                        cout << endl;
                        cout << "Title: " << listOfBooks.at(i).getBookTitle() << endl;
                        cout << "Author: " << listOfBooks.at(i).getBookAuthor() << endl;
                        cout << "Edition: " << listOfBooks.at(i).getBookEdition() << endl;
                        return i;
                    }
                i++;
            }
            return -1;
        }

        //Print all the books
        void printAllBooks()
        {
            for(int i = 0; i < listOfBooks.size(); i++)
            {
                cout << listOfBooks.at(i).getBookTitle() << endl;
                cout << listOfBooks.at(i).getBookAuthor() << endl;
                cout << listOfBooks.at(i).getBookEdition() << endl;
                cout << listOfBooks.at(i).getBookId() << endl;

            }
        }

        //Issues the book
        void issueBookHere(string memName, string bookTitle)
        {
          int bookindex = searchBookByTitle(bookTitle);
          int memindex = findMember(memName);

          if(bookindex != (-1))
             {
                 if(listOfBooks.at(bookindex).getAvailable() == true)
                 {
                     if(memindex != (-1))
                     {
                         Member* tempmemptr = &listOfMembers.at(memindex);
                         listOfBooks.at(bookindex).setMPointer(tempmemptr);
                         cout << "The Book: " << listOfBooks.at(bookindex).getBookTitle() << ", has been issued successfully to: " << listOfMembers.at(memindex).getName() << endl;
                     }
                     else
                     {
                         addMembers();
                         memindex = listOfMembers.size()-1;
                         Member* tempmemptr = &listOfMembers.at(memindex);
                         listOfBooks.at(bookindex).setMPointer(tempmemptr);
                         cout << "The Book: " << listOfBooks.at(bookindex).getBookTitle() << ", has been issued successfully to: " << listOfMembers.at(memindex).getName() << endl;
                     }
                 }
                 else
                 {
                     cout << "The book is not in stock." << endl;
                 }
             }
             else
             {
                cout << "This book is not in the library." << endl;
             }
        }



    protected:

    private:
        vector<Books> listOfBooks;
        vector<Member> listOfMembers;


};

#endif // LIBRARY_H

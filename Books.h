#ifndef BOOKS_H
#define BOOKS_H
#include <string>
#include <Member.h>

using namespace std;

class Books
{
    public:
        Books() {}
        virtual ~Books() {}

        //Setters
        void setBookTitle(string bkname){bookTitle = bkname;}
        void setAuthor(string authr){author = authr;}
        void setBookEdition(string bkEdition){bookEdition = bkEdition;}
        void setBookId(string bkId){bookId = bkId;}
        void setAvailable(bool avail){available = avail;}
        void setMPointer(Member* mptr){mPointer = mptr;}

        //Getters
        string getBookTitle(){return bookTitle;}
        string getBookAuthor(){return author;}
        string getBookEdition(){return bookEdition;}
        string getBookId(){return bookId;}
        bool getAvailable(){return available;}
        Member* getmPointer(){return mPointer;}




    protected:

    private:

        string bookTitle;
        string author;
        string bookEdition;
        string bookId;
        bool available = false;
        Member* mPointer;


    };

#endif // BOOKS_H

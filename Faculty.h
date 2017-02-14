#ifndef FACULTY_H
#define FACULTY_H

#include <Member.h>


class Faculty : public Member
{
    public:
        Faculty() {}
        virtual ~Faculty() {}

        //Setter
        void setFacultyId(int fId){facultyId = fId;}

        //Getters
        int getFacultyId(){return facultyId;}
        char getIdentifier(){return identifier;}

    protected:

    private:
        int facultyId;
        char identifier = 'F';
};

#endif // FACULTY_H

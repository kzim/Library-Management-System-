#ifndef STUDENT_H
#define STUDENT_H

#include <Member.h>


class Student : public Member
{
    public:
        Student() {}
        virtual ~Student() {}

        //Setter
        void setStudentId(int sId){studentId = sId;}

        //Getters
        int getStudentId(){return studentId;}
        char getIdentifier(){return identifier;}

    protected:

    private:
        int studentId;
        char identifier ='S';
};

#endif // STUDENT_H

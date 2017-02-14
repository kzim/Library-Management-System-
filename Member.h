#ifndef MEMBER_H
#define MEMBER_H
#include <string>

#include<Books.h>

using namespace std;


class Member
{
    public:
        Member()
        {}
        virtual ~Member() {}

        //Setters
        void setName(string name){memberName = name;}
        void setAddress(string addressMem){address = addressMem;}
        void setPhoneNo(int phone){phoneNo = phone;}
        void setMemId(int id){memId = id;}

        //Getters
        string getName(){return memberName;}
        string getAddress(){return address;}
        int getPhoneNo(){return phoneNo;}
        int getMemId(){return memId;}



    protected:
        string memberName;
        string address;
        int phoneNo;
        int memId;


    private:




};

#endif // MEMBER_H

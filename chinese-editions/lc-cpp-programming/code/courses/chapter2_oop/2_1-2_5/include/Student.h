#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H
#include "myDate.h"
#include<string>
using namespace std;

class Student
{
    public:
        void setStudent(string,myDate);
        void setName(string);
        string getName();
        void setBirthday(myDate);
        myDate getBirthday();
        void printStudent() const;
    private:
        string name;
        myDate birthday;
};

#endif //UNTITLED_STUDENT_H

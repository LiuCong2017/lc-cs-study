#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H
#include "../include/myDate.h"
#include <string>
using namespace std;

class Student{
public:
    Student();
    Student(string);
    Student(const Student& s);//自定义拷贝构造函数
    void setStudent(string,myDate);
    void setStudent(string);
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

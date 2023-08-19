#include "../include/myDate.h"
#include "../include/Student.h"
#include<iostream>
#include<string>
using namespace std;

int main()
{
    Student ss;
    int y,m,d;
    string name_;

    Student* sp = &ss;

    Student& sy = ss;

    cout<<"input name, birthday(y m d):";
    cin>>name_>>y>>m>>d;

//    访问对象成员
//    ss.setStudent(name_,myDate(y,m,d));
//    ss.printStudent();

//    指针方式
    sp->setStudent(name_,myDate(y,m,d));
    sp->printStudent();

//    引用方式
    sy.setStudent(name_,myDate(y,m,d));
    sy.printStudent();

    return 0;
}

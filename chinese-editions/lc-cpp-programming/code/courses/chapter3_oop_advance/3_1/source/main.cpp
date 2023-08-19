#include "../include/myDate.h"
#include "../include/Student.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
//    Student stu;
//    Student ss[2];
//
//    int y,m,d,i;
//    string name_;
//
//    stu.printStudent();
//
//    for (i = 0;  i<2 ; i++)
//        ss[i].printStudent();
//
//    for (i = 0; i < 2; ++i){
//        cout<<"input name birthday(y m d):";
//        cin>>name_>>y>>m>>d;
//        ss[i].setStudent(name_,myDate(y,m,d));
//    }
//
//    for (i = 0; i < 2; ++i) {
//        ss[i].printStudent();
//    }

//    Student student;
//    student.printStudent();
//
//    student.setName("Alissa");
//    student.printStudent();
//
//    Student* stuPointerArr[2] = {new Student(),&student};
//    Student sy[2] = {Student(),student};
//
//    for (int i = 0; i < 2; ++i) {
//        stuPointerArr[i]->printStudent();
//    }
//
//    for (int i = 0; i < 2; ++i) {
//        sy[i].printStudent();
//    }
//
//    cout<<"--------------";
//
//    student.setName("Orange");
//    for (int i = 0; i < 2; ++i) {
//        stuPointerArr[i]->printStudent();
//    }
//
//    stuPointerArr[0]->setName("Apple1");
//    stuPointerArr[1]->setName("Apple2");
//    for (int i = 0; i < 2; ++i) {
//        stuPointerArr[i]->printStudent();
//    }
//
//    student.printStudent();
//    for (int i = 0; i < 2; ++i) {
//        stuPointerArr[i]->printStudent();
//    }

    Student stucp;
    Student ss[2] = {stucp,Student()};
    stucp.printStudent();

    stucp.setName("Banana");
    ss[0] = Student(stucp); //调用拷贝构造函数
    ss[1] = Student();
    stucp.printStudent();

    ss[0].printStudent();
    ss[1].printStudent();

    return 0;
}
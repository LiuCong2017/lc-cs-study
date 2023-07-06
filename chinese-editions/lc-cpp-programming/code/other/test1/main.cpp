#include <iostream>
#include "include/student.h"
using namespace std;

int main()
{
    Student *stu = new Student;
    stu->name = "Kavin";
    stu->age = 20;
    stu->score = 80;
    stu->say();

    delete stu;
    return 0;
}
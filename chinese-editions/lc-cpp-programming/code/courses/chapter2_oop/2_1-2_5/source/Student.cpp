#include "../include/Student.h"
#include<string>
#include <iostream>
using namespace std;

void Student::setStudent(string s,myDate d)
{
    name = s;
    birthday.setDate(d);
    return;
}

void Student::setName(string n)
{
    name = n;
    return;
}

string Student::getName()
{
    return name;
}

void Student::setBirthday(myDate d)
{
    birthday.setDate(d);
    return;
}

myDate Student::getBirthday()
{
    return birthday;
}

void Student::printStudent() const
{

    cout<<name;
    birthday.printDate();
}

#include "../include/Student.h"
#include<string>
#include <iostream>
using namespace std;

Student::Student():name("Noname"),birthday(myDate()){}

Student::Student(string n):name(n),birthday(myDate()){}

Student::Student(const Student &s) {
    name="COPY" + s.name;
    birthday = s.birthday;
}

void Student::setStudent(string s,myDate d)
{
    name = s;
    birthday.setDate(d);
    return;
}

void Student::setStudent(string s) {
    name = s;
    myDate d;
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
    cout<<name<<"\t";
    birthday.printDate();
}

#include <iostream>
#include <string>
using namespace std;

class myDate
{
public:
  myDate();
  myDate(int);
  myDate(int,int);
  myDate(int,int,int);
  myDate(const myDate& d);
  ~myDate();
  void setDate(int,int,int);
  void setDate(myDate);
  myDate getDate();
  void setYear(int);
  int getMonth();
  void printDate() const;
private:
  int year,month,day;
};

myDate::myDate():year(1970),month(1),day(1)
{
  cout<<"myDate: defualt constructor"<<endl;
}

myDate::myDate(int y):year(y),month(1),day(1)
{
  cout<<"myDate: 1 params constructor"<<endl;
}

myDate::myDate(int y,int m):year(y),month(m),day(1)
{
  cout<<"myDate: 2 params constructor"<<endl;
}

myDate::myDate(int y,int m,int d):year(y),month(m),day(d)
{
  cout<<"myDate: 3 params constructor"<<endl;
}

myDate::myDate(const myDate& d)
{
  year = d.year;
  month = d.month;
  day = d.day;
  cout<<"myDate: copy constructor"<<endl;
}

myDate::~myDate()
{
  cout<<"myDate: destructor"<<endl;
}

void myDate::setDate(int y,int m,int d)
{
  year = y;
  month = m;
  day = d;
  return;
}

void myDate::setDate(myDate d)
{
  year = d.year;
  month = d.month;
  day = d.day;
  return;
}

myDate myDate::getDate()
{
  myDate d;
  d.year = year;
  d.month = month;
  d.day = day;
  return d;
}

void myDate::setYear(int y)
{
  year = y;
  return;
}

int myDate::getMonth()
{
  return month;
}

void myDate::printDate() const
{
  cout<<year<<"/"<<month<<"/"<<day;
  return;
}

class CStudent
{
public:
  CStudent();
  CStudent(string, myDate);
  ~CStudent();
  void setStudent(string,myDate);
  void setName(string);
  string getName();
  void setBirthday(myDate);
  myDate getBirthday();
  void printInfo() const;
private:
  string name;
  myDate birthday;
};

CStudent::CStudent():name("Cody"),birthday(myDate())
{
  cout<<"CStudent: default constructor"<<endl;
}

CStudent::CStudent(string str,myDate d):name(str),birthday(d)
{
  cout<<"Cstudent: params constructor"<<endl;
}

CStudent::~CStudent()
{
  cout<<"CStudent: destructor"<<endl;
}

void CStudent::setStudent(string s,myDate d)
{
  name = s;
  birthday.setDate(d);
  return;
}

void CStudent::setName(string n)
{
  name = n;
  return;
}

string CStudent::getName()
{
  return name;
}

void CStudent::setBirthday(myDate d)
{
  birthday.setDate(d);
  return;
}

myDate CStudent::getBirthday()
{
  return birthday;
}

//-------------------------------
void CStudent::printInfo() const
{
  cout<<"name: "<<this->name<<"\tbirthday: ";
  this->birthday.printDate();
  cout<<endl;
}

class CUndergraduateStudent:public CStudent
{
private:
  string department;
public:
  CUndergraduateStudent();
  CUndergraduateStudent(string,myDate);
  ~CUndergraduateStudent();
  void setDep(string);
  void printInfo();
};

CUndergraduateStudent::CUndergraduateStudent()
{
  cout<<"CUndergraduateStudent: default constructor"<<endl;
}

CUndergraduateStudent::CUndergraduateStudent(string str,myDate d):CStudent(str,d)
{
  cout<<"CUndergraduateStudent: params constructor"<<endl;
}

CUndergraduateStudent::~CUndergraduateStudent()
{
  cout<<"CUndergraduateStudent: destructor"<<endl;
}

void CUndergraduateStudent::setDep(string dep)
{
  department = dep;
}

void CUndergraduateStudent::printInfo()
{
  CStudent::printInfo();
  cout<<"department:\t"<<department<<endl;
}

int main()
{
    CUndergraduateStudent s2("Alissa",myDate());

  return 0;
}
























/**
* Author Kavin Liu
* Date 29,Jul 2023
*/

#include <iostream>
#include <string>
using namespace std;

class Student
{
  string name;
  int year,month,day;
public:
  Student() : year(), month(), day(){};
  Student(const string&,int,int,int);
  void setName(const string&);
  void setMyDate(int,int,int);
  void print();
};

Student::Student(const string& n,int y,int m,int d)
{
  this->name = n;
  this->year = y;
  this->month = m;
  this->day = d;
}

void Student::setName(const string& name)
{
  this->name = name;
}

void Student::setMyDate(int y,int m,int d)
{
  this->year = y;
  this->month = m;
  this->day = d;
}

void Student::print()
{
  cout<<name<<"-"<<year<<"/"<<month<<"/"<<day<<endl;
}

int main()
{
  int y,m,d;
  string n;
  Student ss;
  cout<<"input n,y,m,d:"<<endl;
  cin>>n>>y>>m>>d;
  ss = Student(n,y,m,d);
  ss.print();

  cout<<"input y,m,d:"<<endl;
  cin>>y>>m>>d;
  ss.setMyDate(y,m,d);
  ss.print();

  cout<<"input n:"<<endl;
  cin>>n;
  ss.setName(n);
  ss.print();


  return 0;
}

#include<iostream>
#include<string>

using namespace std;

class employee
{
  short age;
  float salary;
protected:
  string name;
public:
  employee(short age,float salary,const string& name)
  {
    this->age = age;
    this->salary = salary;
    this->name = name;
  }
  void print()
  {
    cout<<name<<":\t";
    cout<<age<<":\t";
    cout<<salary;
  }
  ~employee(){}
};

class manager:public employee
{
  int level;
public:
  manager(short age_,float salary_,const string& name_,int level_):employee(age_,salary_,name_)
  {
    level = level_;
  }
  void print()
  {
    employee::print();
    cout<<"\tlevel:"<<level;
  }
};

class engineer:public employee
{
  char speciality,degree;
public:
  engineer(short age_,float salary_,const string& name_,char speciality_,char degree_):employee(age_,salary_,name_)
  {
    speciality = speciality_;
    degree = degree_;
  }
  void print()
  {
    employee::print();
    cout<<"\tspeciality:"<<speciality;
    cout<<"\tdegree:"<<degree;
  }
};

enum title{PS,GM,VPS,VGM};

class director:public manager
{
  title post;
public:
  director(short age_,float salary_,const string& name_,int level_,title post_):manager(age_,salary_,name_,level_){
    post = post_;
  }
  void print()
  {
    manager::print();
    cout<<"\tpost:"<<post<<endl;
  }
};

int main()
{
  employee emp1(23,5000,"Kavin"), emp2(35,8500,"Cody");
  manager man1(45,25000,"Alissa",11), man2(40,15000,"Audrey",7);
  engineer eng(25,5500,"Jeromy",'E','M');
  director dir(38,18000,"Kurt",36,VPS);
  emp1.print();
  emp2.print();
  man1.print();
  man2.employee::print();
  eng.print();
  dir.print();

  return 0;
}










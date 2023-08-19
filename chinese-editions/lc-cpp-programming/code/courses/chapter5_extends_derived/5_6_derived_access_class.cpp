#include<iostream>
#include<string>
using namespace std;

class CStudent
{
private:
  string name;
  string id;
  char gender;
  int age;
public:
  void PrintInfo();
  void SetInfo(const string&, const string&, int, char);
  void SetName(string);
  string GetName();
  void SetId(string);
  string GetId();
};

void CStudent::PrintInfo()
{
  cout<<"name:"<<name<<endl;
  cout<<"id:"<<id<<endl;
  cout<<"age:"<<age<<endl;
  cout<<"gender:"<<gender<<endl;
}

void CStudent::SetInfo(const string& name_, const string& id_,int age_,char gender_)
{
  name = name_;
  id = id_;
  age = age_;
  gender = gender_;
}

void CStudent::SetName(string name)
{
  this->name = name;
}

string CStudent::GetName()
{
  return name;
}

void CStudent::SetId(string id)
{
  this->id = id;
}

string CStudent::GetId()
{
  return id;
}

class CUndergraduateStudent:public CStudent
{
private:
  string department;
public:
  void PrintInfo();
  void SetInfo(const string&, const string&, int, char, const string&);
};

void CUndergraduateStudent::PrintInfo()
{
  CStudent::PrintInfo();
  cout<<"department:"<<department<<endl;
}

void CUndergraduateStudent::SetInfo(const string& name_,const string& id_,int age_,char gender_,const string& department_)
{
  CStudent::SetInfo(name_,id_,age_,gender_);
  department = department_;
}

class CGraduatedStudent:public CStudent
{
private:
  string department;
  string advisor;
public:
  static int a;
  void PrintInfo();
  void SetInfo(const string& name_,const string& id_,int age_,char gender_,const string& department_,const string& advisor_);
};

int CGraduatedStudent::a = 10;

void CGraduatedStudent::PrintInfo()
{
  CStudent::PrintInfo();
  cout<<"department:"<<department<<endl;
  cout<<"advisor:"<<advisor<<endl;
}

void CGraduatedStudent::SetInfo(const string& name_,const string& id_,int age_,char gender_,const string& department_,const string& advisor_)
{
  CStudent::SetInfo(name_,id_,age_,gender_);
  department = department_;
  advisor = advisor_;
}

int main()
{
  CStudent s1;
  CUndergraduateStudent s2;
  CGraduatedStudent s3;
  
  s2.SetInfo("Kavin","2018-6-7-12",19,'M',"Math");
  s3.SetInfo("Cody","M2017-9",23,'M',"CS","Mrs.Grace");
  
  s2.PrintInfo();
  s3.PrintInfo();

  cout<<s3.a<<endl;

  cout<<s2.GetName()<<endl;
  s2.SetName("Alissa");
  s2.PrintInfo();
  cout<<s2.GetName()<<","<<s2.GetId()<<endl;

  return 0;
}


















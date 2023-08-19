#include <iostream>
#include <string>
using namespace std;

class A
{
public:
  void put_name(string s)
  {
    name = s;
  }
  virtual void print_name() const
  {
    cout<<"A::"<<name<<"\n";
  }
  string name;
};

class B:public A
{
public:
  void put_name(string s)
  {
    put_name(s);
  }
  virtual void print_name() const
  {
    cout<<"B::"<<name<<","<<A::name<<"\n";
  }
  void put_phone(string num)
  {
    phone_num = num;
  }
  void print_phone() const
  {
    cout<<phone_num<<"\n";
  }
  string phone_num;
};

int main()
{
  A *A_p;
  A A_obj;
  B B_obj;

  A_p = &A_obj;
  A_p->put_name("polymorphic_name");
  
  cout<<"A_p->put_name content:\t";
  A_p->print_name();
  
  cout<<"A_obj.print_name content:\t";
  A_obj.print_name();

  A_p = &B_obj;
  A_p->put_name("another name");
  
  cout<<"A_p->put_name content:\t";
  A_p->print_name();
  
  cout<<"B_obj.print_name content:\t";
  B_obj.print_name();
  
  B_obj.put_phone("TEL.911");
  cout<<"((B*)A_p)->print_phone content:\t";
  ((B*)A_p)->print_phone();

  cout<<"B_obj.print_phone content:\t";
  B_obj.print_phone();

  return 0;
}











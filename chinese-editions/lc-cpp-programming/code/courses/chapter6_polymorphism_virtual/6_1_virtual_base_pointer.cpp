#include <iostream>
using namespace std;

class A
{
public:
  virtual void Print()
  {
    cout<<"A::Print"<<endl;
  }
};

class B:public A
{
public:
  virtual void Print()
  {
    cout<<"B::Print"<<endl;
  }
};

class D:public A
{
public:
  virtual void Print()
  {
    cout<<"D::Print"<<endl;
  }
};

class E:public B
{
public:
  virtual void Print()
  {
    cout<<"E::Print"<<endl;
  }
};

int main()
{
  A a;
  B b;
  D d;
  E e;

  A *pa = &a;
  B *pb = &b;
  
  pa->Print();

  pa = pb;
  pa->Print();

  pa = &d;
  pa->Print();

  pa = &e;
  pa->Print();  

  return 0;
}

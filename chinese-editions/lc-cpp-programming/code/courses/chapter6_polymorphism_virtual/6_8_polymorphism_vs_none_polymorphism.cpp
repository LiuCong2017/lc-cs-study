#include <iostream>
using namespace std;

class A
{
public:
  void func1()
  {
    cout<<"A::func1"<<endl;
  }
  virtual void func2()
  {
    cout<<"A::func2"<<endl;
  }
};

class B:public A
{
public:
  virtual void func1()
  {
    cout<<"B::func1"<<endl;
  }
  void func2()
  {
    cout<<"B::func2"<<endl;
  }
};

class C:public B
{
public:
  void func1()
  {
    cout<<"C::func1"<<endl;
  }
  void func2()
  {
    cout<<"C::func2"<<endl;
  }
};

int main()
{
  C obj;
  A *pa = &obj;
  B *pb = &obj;
  
  pa->func2();
  pa->func1();
  pb->func1();  

  return 0;
}

#include <iostream>
using namespace std;

class A
{
private:
  int a;
public:
  virtual void print()=0;
  void func1()
  {
    cout<<"func1"<<endl;
  }
};

class B:public A
{
public:
  void print();
  void func1()
  {
    cout<<"B func1"<<endl;
  }
};

void B::print()
{
  cout<<"B print"<<endl;
}

int main()
{
  A *pa;
  A *pb = new B;
  pb->print();
  
  B b;
  A *pc = &b;
  pc->func1();

  return 0;
}

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

void PrintInfo(A &r)
{
  r.Print();
}

int main()
{
  A a;
  B b;
  PrintInfo(a);
  PrintInfo(b);

  return 0;
}

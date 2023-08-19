#include <iostream>
using namespace std;

class A
{
  int an;
public:
  A(){}
  A(int n)
  {
    an = n;
  }
  void print()
  {
    cout<<"A's obj: "<<"an: "<<an;
  }
  void print(int k)
  {
    cout<<"an: "<<an;
  }
};

class B:public A
{
  int bn;
public:
  B(int n):A(2*n)
  {
    bn = n;
  }
  void print()
  {
    cout<<" B's Obj: ";
    A::print(1);
    cout<<", bn="<<bn<<endl;
  }
};

int main()
{
  A a(10);
  B b(20);
  a.print();
  b.print();
  a = b;
  a.print();
  b.print();

  A& r = b;
  
  A* pa = &b;
  
  B* pb = &b;
  pa = pb;

  return 0;
}

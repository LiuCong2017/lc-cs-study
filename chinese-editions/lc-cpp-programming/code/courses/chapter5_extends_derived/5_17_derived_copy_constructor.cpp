#include <iostream>
using namespace std;

class A
{
public:
  A()
  {
    i=100;
    cout<<"A's default constructor"<<endl;
  }
  A(const A& s)
  {
    i = s.i;
    cout<<"A's copy constructor"<<endl;
  }
  int getValue();
  void setValue(int);
private:
  int i;
};

int A::getValue()
{
  return i;
}

void A::setValue(int k)
{
  i=k;
}

class B:public A
{
private:
  float f;
public:
  B()
  {
    f = 20.1;
    cout<<"B's default constructor"<<endl;
  }
  B(const B& v):A::A(v),f(v.f)
  {
    cout<<"B's copy constructor"<<endl;
  }
  float getValue();
  int getValue1()
  {
    return A::getValue();
  }
};

float B::getValue()
{
  return f;
}

int main()
{
  A a;
  B b;
  B bb(b);

  return 0;
}


#include <iostream>
using namespace std;

class BaseClass
{
protected:
  int v1,v2;
public:
  BaseClass();
  BaseClass(int,int);
  ~BaseClass();
};

BaseClass::BaseClass()
{
  cout<<"Base: none params constructor"<<endl;
}

BaseClass::BaseClass(int v1,int v2)
{
  this->v1 = v1;
  this->v2 = v2;
  cout<<"Base: two params constructor"<<endl;
}

BaseClass::~BaseClass()
{
  cout<<"Base: destructor"<<endl;
}

class DerivedClass:public BaseClass
{
  int v3;
public:
  DerivedClass();
  DerivedClass(int);
  DerivedClass(int,int,int);
  ~DerivedClass();
};

DerivedClass::DerivedClass()
{
  cout<<"Derived: none params constructor"<<endl;
}
DerivedClass::DerivedClass(int n):v3(n)
{
  cout<<"Derived: 1 params constructor"<<endl;
}
DerivedClass::DerivedClass(int k,int m,int n):BaseClass(k,m),v3(n)
{
  cout<<"Derived: 3 params constructor"<<endl;
}
DerivedClass::~DerivedClass()
{
  cout<<"Derived: deConstructor"<<endl;
}

int main()
{
  cout<<"------none params' obj create:"<<endl;
  BaseClass bc;
  DerivedClass dc;

  cout<<"------with params' obj create:"<<endl;
  BaseClass bc1(10,20);
  DerivedClass dc1(30);
    

  return 0;
}

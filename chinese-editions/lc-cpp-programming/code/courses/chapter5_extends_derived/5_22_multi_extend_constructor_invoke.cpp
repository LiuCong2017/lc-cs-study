#include <iostream>
using namespace std;

class BaseClass1
{
protected:
  int v1,v2;
public:
  BaseClass1();
  BaseClass1(int,int);
  ~BaseClass1();
};

BaseClass1::BaseClass1()
{
  cout<<"BaseClass1's none params constructor"<<endl;
}

BaseClass1::BaseClass1(int m,int n):v1(m),v2(n)
{
  cout<<"BaseClass1's 2 params constructor"<<endl;
}

BaseClass1::~BaseClass1()
{
  cout<<"BaseClass1's destructor"<<endl;
}

class BaseClass2:public BaseClass1
{
protected:
  int v3;
public:
  BaseClass2();
  BaseClass2(int);
  BaseClass2(int,int,int);
  ~BaseClass2();
};

BaseClass2::BaseClass2()
{
  cout<<"BaseClass2's none params constructor"<<endl;
}

BaseClass2::BaseClass2(int m):v3(m)
{
  cout<<"BaseClass2's 1 params constructor"<<endl;
}

BaseClass2::BaseClass2(int m,int n,int k):BaseClass1(m,n),v3(k)
{
  cout<<"BaseClass2's 3 params constructor"<<endl;
}

BaseClass2::~BaseClass2()
{
  cout<<"BaseClass2's destructor"<<endl;
}

class DerivedClass:public BaseClass2
{
public:
  int v4;
public:
  DerivedClass();
  DerivedClass(int);
  DerivedClass(int,int,int,int);
  ~DerivedClass();
};

DerivedClass::DerivedClass()
{
  cout<<"DerivedClass none params constructor"<<endl;
}

DerivedClass::DerivedClass(int k):v4(k)
{
  cout<<"DerivedClass 1 params constructor"<<endl;
}

DerivedClass::DerivedClass(int m,int n,int k,int t):BaseClass2(m,n,k),v4(t)
{
  cout<<"DerivedClass 4 params constructor"<<endl;
}

DerivedClass::~DerivedClass()
{
  cout<<"DerivedClass destructor"<<endl;
}

int main()
{
  cout<<"none params object created:"<<endl;
  DerivedClass derivedCla;

  cout<<"with params object created:"<<endl;
  DerivedClass derivedCla1(100,200,300,400);

  return 0;
}



















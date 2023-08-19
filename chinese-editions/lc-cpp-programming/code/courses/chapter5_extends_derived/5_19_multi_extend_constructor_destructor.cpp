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
  void SetValue(int,int);
  void PrintValue();
};

BaseClass1::BaseClass1():v1(0),v2(0)
{
  cout<<"BaseClass1: none params constructor"<<endl;
}

BaseClass1::BaseClass1(int m,int n)
{
  v1 = m;
  v2 = n;
  cout<<"BaseClass1: two params constructor"<<endl;
}

BaseClass1::~BaseClass1()
{
  cout<<"BaseClass1: destructor"<<endl;
}

void BaseClass1::SetValue(int m,int n)
{
  v1 = m;
  v2 = n;
}

void BaseClass1::PrintValue()
{
  cout<<"v1="<<v1<<"\tv2="<<v2;
}

class BaseClass2
{
protected:
  int v1,v4;
public:
  BaseClass2();
  BaseClass2(int,int);
  ~BaseClass2();
  void SetValue(int,int);
  void PrintValue();
};

BaseClass2::BaseClass2():v1(1),v4(1)
{
  cout<<"BaseClass2: none params constructor"<<endl;
}

BaseClass2::BaseClass2(int m,int n):v1(m),v4(n)
{
  cout<<"BaseClass2: two params constructor"<<endl;
}

BaseClass2::~BaseClass2()
{
  cout<<"BaseClass2: destructor"<<endl;
}

void BaseClass2::SetValue(int m,int n)
{
  v1 = m;
  v4 = n;
}

void BaseClass2::PrintValue()
{
  cout<<"v1="<<v1<<"\tv4="<<v4<<endl;
}

class DerivedClass:public BaseClass1,public BaseClass2
{
public:
  int v3;
public:
  DerivedClass();
  DerivedClass(int);
  DerivedClass(int,int,int,int);
  ~DerivedClass();
  void SetValue(int m,int n,int k,int h)
  {
    BaseClass1::SetValue(m,n);
    BaseClass2::SetValue(2*m,h);
    v3 = k;
  }
  void SetValue(int m,int n,int k)
  {
    BaseClass1::SetValue(m,n);
    BaseClass2::SetValue(2*m,2*n);
    v3 = k;
  }
  void SetValue(int m,int n)
  {
    BaseClass1::SetValue(m,n);
    BaseClass2::SetValue(-1,-1);
    v3 = -1;
  }
  void PrintValue();
};

DerivedClass::DerivedClass():BaseClass1(0,0),BaseClass2(0,0),v3(0)
{
  cout<<"DerivedClass: none params constructor"<<endl;
}

DerivedClass::DerivedClass(int k)
{
  v3 = k;
  cout<<"DerivedClass: 1 params constructor"<<endl;
}

DerivedClass::DerivedClass(int m,int n,int k,int t):BaseClass1(m,n),BaseClass2(m,t),v3(k)
{
  cout<<"DerivedClass: 4 params constructor"<<endl;
}

DerivedClass::~DerivedClass()
{
  cout<<"DerivedClass: destructor"<<endl;
}

void DerivedClass::PrintValue()
{
  BaseClass1::PrintValue();
  cout<<"\tv3="<<v3<<endl;
  BaseClass2::PrintValue();
  cout<<endl;
}

int main()
{
  cout<<"with params obj create:"<<endl;
  DerivedClass dc(10,20,30,40);
  dc.PrintValue();

  return 0;
}

























































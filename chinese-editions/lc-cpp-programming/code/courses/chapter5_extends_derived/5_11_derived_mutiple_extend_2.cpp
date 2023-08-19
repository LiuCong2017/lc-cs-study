#include<iostream>
using namespace std;

class BaseClass1
{
public:
  int v1,v2;
  BaseClass1();
  BaseClass1(int,int);
  ~BaseClass1();
};

BaseClass1::BaseClass1()
{
  cout<<"BaseClass1 none params constructor"<<endl;
}

BaseClass1::BaseClass1(int a,int b):v1(a),v2(b)
{
  cout<<"BaseClass1 with params constructor"<<endl;
}

BaseClass1::~BaseClass1()
{
  cout<<"BaseClass1 deConstructor"<<endl;
}

class BaseClass2
{
public:
  int v1,v4;
  BaseClass2();
  BaseClass2(int,int);
  ~BaseClass2();
};

BaseClass2::BaseClass2()
{
  cout<<"BaseClass2 none params construtor"<<endl;
}

BaseClass2::BaseClass2(int a,int b):v1(a),v4(b)
{
  cout<<"BaseClass2 with params construtor"<<endl;
}

BaseClass2::~BaseClass2()
{
  cout<<"BaseClass2 deConstructor"<<endl;
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
};

DerivedClass::DerivedClass()
{
  cout<<"DerivedClass none params constructor"<<endl;
}

DerivedClass::DerivedClass(int a):v3(a)
{
  cout<<"DerivedClass one params constructor"<<endl;
}

DerivedClass::DerivedClass(int a,int b,int c,int d):BaseClass1(a,b),BaseClass2(a,d),v3(c)
{
  cout<<"DerivedClass four params constructor"<<endl;
}

DerivedClass::~DerivedClass()
{
  cout<<"DerivedClass deConstructor"<<endl;
}

int main()
{
  cout<<"create the object with params"<<endl;
  DerivedClass dc(100,200,300,400);
  cout<<"v1="<<dc.BaseClass1::v1<<endl;
  cout<<"v2="<<dc.v2<<endl;
  cout<<"v1="<<dc.BaseClass2::v1<<endl;
  cout<<"v4="<<dc.v4<<endl;
  cout<<"v3="<<dc.v3<<endl;


  return 0;
}










































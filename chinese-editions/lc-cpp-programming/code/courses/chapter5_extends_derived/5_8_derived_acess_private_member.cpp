#include<iostream>
using namespace std;

class BaseClass
{
  int v1,v2;
public:
  void SetValue(int m,int n)
  {
    v1 = m;
    v2 = n;
  }
  void PrintValue();
};

void BaseClass::PrintValue()
{
  cout<<"v1="<<v1<<"\tv2="<<v2<<endl;
}

class DerivedClass:public BaseClass
{
  int v3;
public:
  void SetValue(int m,int n,int k)
  {
    BaseClass::SetValue(m,n);
    v3 = k;
  }
  void PrintValue();
};

void DerivedClass::PrintValue()
{
  cout<<endl;
  BaseClass::PrintValue();
  cout<<"\tv3="<<v3<<endl;
}

int main()
{
  BaseClass bc;
  DerivedClass dc;
  cout<<"initial value:"<<endl;
  bc.PrintValue();
  dc.PrintValue();
  cout<<"after BaseClass' value been changed:"<<endl;
  bc.SetValue(10,20);
  bc.PrintValue();
  dc.PrintValue();
  cout<<"modify DerivedClas' value which is extends from BaseClass and self's value:"<<endl;
  dc.SetValue(100,200,300);
  bc.PrintValue();
  dc.PrintValue();

  return 0;
}

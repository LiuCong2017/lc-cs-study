#include<iostream>
using namespace std;

class BaseClass
{
protected:
  int v1,v2;
public: 
  void SetValue(int m,int n)
  {
    this->v1 = m;
    this->v2 = n;
  }

  void printValue();
};

void BaseClass::printValue()
{
  cout<<"v1="<<v1<<"\tv2="<<v2<<endl;
}

class DerivedClass:public BaseClass
{
  int v3;
public:
  void setValue(int m,int n,int k)
  {
    this->v1 = m;
    this->v2 = n;
    this->v3 = k;
  }
  void setValue(int m,int n)
  {
    this->v1 = m;
    this->v2 = n;
  }
  void printValue();
};

void DerivedClass::printValue()
{
    cout<<endl;
    BaseClass::printValue();
  cout<<"v3="<<v3<<endl;
}

int main()
{
  BaseClass bc;
  DerivedClass dc;
  cout<<"initial value:"<<endl;
  bc.printValue();
  dc.printValue();

  cout<<"derived value:"<<endl;
  dc.setValue(10,20);
  bc.printValue();
  dc.printValue();

  cout<<"extends value:"<<endl;
  dc.setValue(100,200,300);
  bc.printValue();
  dc.printValue();

  return 0;
}

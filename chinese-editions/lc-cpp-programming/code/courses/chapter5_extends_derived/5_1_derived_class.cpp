#include<iostream>
using namespace std;

class BaseClass
{
public:
  int v1,v2;
  BaseClass():v1(1),v2(1){}

  int temp1(){ return 0; }
};

class DerivedClass:public BaseClass
{
  int v1;
  int temp1(){ return 0; }
public:
  DerivedClass():v1(10){}
  void printv()
  {
    cout<<"v1="<<v1<<endl;
    cout<<"Base.v1="<<BaseClass::v1<<endl;
  }
};

int main()
{ 
  BaseClass bc;
  DerivedClass dc;
  dc.printv();

  return 0;
}

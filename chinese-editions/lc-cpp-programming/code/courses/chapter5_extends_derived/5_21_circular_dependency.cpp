#include <iostream>
#include <string>
using namespace std;

class B;

class A
{
public:
  int aInt;
  B *bPoint = NULL;
  void SetValue(int v)
  {
    aInt = v;
  }
};

class B
{
public:
  A aCla;
  int bInt;
  void SetValue(int v)
  {
    bInt = v;
  }
};

int main()
{
  A ca;
  B cb;
  ca.bPoint = &cb;
  
  cout<<"ca.bPoint="<<ca.bPoint<<endl;
  cout<<"cb addr="<<&cb<<endl;
  cout<<"ca.aInt="<<ca.aInt<<endl;
  cout<<"cb.aCla.aInt="<<cb.aCla.aInt<<endl;
  cout<<"cb.bInt="<<cb.bInt<<endl;

  cout<<"-------------"<<endl;
  ca.SetValue(10);
  cb.SetValue(20);
  cb.aCla = ca;
  
  cout<<"ca.bPoint="<<ca.bPoint<<endl;
  cout<<"ca.aInt="<<ca.aInt<<endl;
  cout<<"cb.aCla.aInt="<<cb.aCla.aInt<<endl;
  cout<<"cb.bInt="<<cb.bInt<<endl;

  return 0;
}

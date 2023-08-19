#include <iostream>
using namespace std;

class CBase
{
protected:
  int n;
public:
  CBase(int i):n(i){}
  void Print()
  {
    cout<<"CBase:n="<<n<<endl;
  }
};

class CDerived:public CBase
{
public:
  int v;
  CDerived(int i):CBase(i),v(2*i){}
  void Func(){}
  void Print()
  {
    cout<<"CDerived:n="<<n<<endl;
    cout<<"CDerived:v="<<v<<endl;
  }
};

int main()
{
  CDerived objDerived(3);
  CBase objBase(5);
  CBase *pBase = &objDerived;

  CDerived *pDerived;
  pDerived = &objDerived;
  cout<<"use derived pointer invoke func"<<endl;
  pDerived->Print();
  pBase = pDerived;
  
  cout<<"use base pointer invoke func"<<endl;
  pBase->Print();
  
  pDerived = (CDerived*)pBase;
  cout<<"use derived pointer invoke func"<<endl;
  pDerived->Print();

  return 0;
}

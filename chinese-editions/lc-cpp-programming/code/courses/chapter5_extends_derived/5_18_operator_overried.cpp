#include <iostream>
using namespace std;

class CBase
{
public:
  CBase(){};
  CBase(CBase& c)
  {
    cout<<"CBase: copy constructor"<<endl;
  }
  CBase& operator=(const CBase& b)
  {
    cout<<"CBase: operator="<<endl;
    return *this;
  }
};

class CDerived:public CBase
{
public:
  CDerived()
  {
    cout<<"CDerived: copy constructor"<<endl;
  }
};

int main()
{
  CDerived d1,d2;
  CDerived d3(d1);
  d2 = d1;

  return 0;
}

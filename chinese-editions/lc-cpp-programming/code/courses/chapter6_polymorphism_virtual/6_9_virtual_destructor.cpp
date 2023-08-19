#include <iostream>
using namespace std;

class ABase
{
public:
  ABase()
  {
    cout<<"ABase constructor"<<endl;
  }
  virtual ~ABase()
  {
    cout<<"ABase destructor"<<endl;
  }
};

class Derived:public ABase
{
public:
  int w,h;
  Derived()
  {
    cout<<"Derived constructor"<<endl;
    w = 4;
    h = 7;
  }
  ~Derived()
  {
    cout<<"Derived destructor"<<endl;
  }
};

int main()
{
  ABase *p = new Derived();
  delete p;

  return 0;
}

#include <iostream>
using namespace std;

class TBase
{
  int k;
public:
  void print()
  {
    cout<<"TBase::"<<k<<endl;
  }
};

template<class T>
class TDerived:public TBase
{
  T data;
public:
  void setData(T x)
  {
    data = x;
  }
  void print()
  {
    TBase::print();
    cout<<"TDerived::"<<data<<endl;
  }
};

int main()
{
  TDerived<string> d;
  d.setData("2019");
  d.print();

  return 0;
}

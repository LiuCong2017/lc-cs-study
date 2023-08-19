#include <iostream>
using namespace std;

template<class T>
class TBase
{
  T data1;
public:
  void print()
  {
    cout<<"TBase::"<<data1<<endl;
  }
};

template <class T2>
class TDerived:public TBase<int>
{
  T2 data2;
public:
  void print()
  {
    TBase<int>::print();
    cout<<"TDerived::"<<data2<<endl;
  }
};

int main()
{
  TDerived<int> d;
  d.print();

  TDerived<string> d2;
  d2.print();
  
  return 0;
}

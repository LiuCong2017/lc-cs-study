#include <iostream>
using namespace std;

class A
{
public:
  int i;
  virtual void func(){}
  virtual void func2(){}
};

class B:public A
{
  int j;
  void func(){}
};

int main()
{
  cout<<sizeof(A)<<","<<sizeof(B);
  return 0;
}

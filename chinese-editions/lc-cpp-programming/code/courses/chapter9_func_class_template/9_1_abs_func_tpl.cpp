#include <iostream>
using namespace std;

template <typename T>
T abs(T x)
{
  return x<0 ? -x : x;
}

int main()
{
  int n = -5;
  int m = 10;
  double d = -.5;
  float f = 3.2;
  
  cout<<n<<"'s abs:"<<abs(n)<<endl;
  cout<<m<<"'s abs:"<<abs(m)<<endl;
  cout<<d<<"'s abs:"<<abs(d)<<endl;
  cout<<f<<"'s abs:"<<abs(f)<<endl;

  return 0;
}

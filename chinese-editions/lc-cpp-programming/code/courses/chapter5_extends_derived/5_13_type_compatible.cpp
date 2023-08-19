#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class A
{
  int an;
public:
  A(){};
  A(int n)
  {
    an = n;
  }
  int getAn(){
    return an;
  }
};

class B:public A
{
  int bn;
public:
  B(int n):A(2*n)
  {
    bn = n;
  }
};

int main()
{
  A a(10);
  B b(20);
  a = b;
  cout<<a.getAn()<<endl;
  return 0;
}

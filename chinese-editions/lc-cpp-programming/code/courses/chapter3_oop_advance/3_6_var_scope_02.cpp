#include <iostream>
using namespace std;

int x = 11;
char ch = '1';

void fun1(int ipara1);

void fun2()
{
  int i = 2222;
  double ch = 202.2;
  
  cout<<"insde fun2(), x="<<x<<endl; 
  cout<<"insde fun2(), ch="<<ch<<endl;
  cout<<"insde fun2(), i="<<i<<endl;
}

int main()
{
  cout<<"insde main(), x="<<x<<endl;
  cout<<"insde main(), ch="<<ch<<endl;
  fun1(x);
  fun2();

  return 0;
}

void fun1(int ii)
{
  int i = 1111;
  int x = 1101;
  cout<<"insde fun1(), ii="<<ii<<endl;
  cout<<"insde fun1(), x="<<x<<endl; 
  cout<<"insde fun1(), ch="<<ch<<endl;
  cout<<"insde fun1(), i="<<i<<endl;
}

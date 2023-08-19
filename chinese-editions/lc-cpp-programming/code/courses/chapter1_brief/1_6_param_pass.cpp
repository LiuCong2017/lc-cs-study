#include<iostream>
using namespace std;

void SwapValue(int a,int b)
{
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
  cout<<"SwapValue: a="<<a<<",b="<<b<<endl;
  return;
}

void SwapRef(int& a,int& b)
{
  int tmp;
  tmp = a;
  a = b;
  b = tmp;  
  cout<<"SwapRef: a="<<a<<",b="<<b<<endl;
  return;
}

int main()
{
  int a=10, b=20;
  SwapValue(a,b);
  cout<<"main sv: a="<<a<<",b="<<b<<endl;
  
  SwapRef(a,b);   
  cout<<"main sr: a="<<a<<",b="<<b<<endl;

  return 0;
}

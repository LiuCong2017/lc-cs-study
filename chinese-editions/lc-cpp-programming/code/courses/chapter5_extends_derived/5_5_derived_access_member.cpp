#include<iostream>
using namespace std;

class CB
{
public:
  int a;
  CB(int x)
  {
    a = x;
  }
  void showa()
  {
    cout<<"Class CB -- a = "<<a<<endl;
  }
};

class CD:public CB
{
public:
  int a;
  CD(int x,int y):CB(x)
  {
    a = y;
  }
  void showa()
  {
    cout<<"Class CD -- a= "<<a<<endl;
  }
  void print2a()
  {
    cout<<"a="<<a<<endl;
    cout<<"CB::a="<<CB::a<<endl;
  }
};

int main()
{
  CB CBobj(12);
  CBobj.showa();

  CD CDobj(877,12);
  CDobj.showa();
  CDobj.CB::showa(); //invoke the base class's function
  cout<<"CDobj.a="<<CDobj.a<<endl;
  cout<<"CDobj.CB::a="<<CDobj.CB::a<<endl;

  return 0;
}

#include<iostream>
using namespace std;

class CB1
{
public:
  int a;
  CB1(int a)
  {
    this->a = a;
  }
  void showa()
  {
    cout<<"CB1 a:"<<a<<endl;
  }
};

class CB2
{
public:
  int a;
  CB2(int a)
  {
    this->a = a;
  }

  void showa()
  {
    cout<<"CB2 a:"<<a<<endl;
  }
};

class CD:public CB1,public CB2
{
public:
  int a;
  CD(int x,int y,int z):CB1(x),CB2(y)
  {
    this->a = z;
  }

  void showa()
  {
    cout<<"CD a:"<<a<<endl;
  }

  void print3a()
  {
    cout<<"a="<<a<<endl;
    cout<<"CB1 a="<<CB1::a<<endl;
    cout<<"CB2 a="<<CB2::a<<endl;
  }
};

int main()
{
  CB1 cb(11);
  cb.showa();
  
  CD cd(101,202,303);
  cd.showa();

  cd.CB1::showa();

  cout<<"cd.a="<<cd.a<<endl;
  cout<<"cd.CB2.a="<<cd.CB2::a<<endl;

  return 0;
}



















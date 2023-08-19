#include <iostream>
#include <string>
using namespace std;

class Demo
{
  int id;
  string position;

public:
  Demo(int i, string pos)
  {
    id = i;
    position = pos;
    cout<<"Obj:"<<this<<endl;
    cout<<"id="<<id<<endl;
    cout<<"position="<<position<<endl;
  }

  Demo(int i):position("temp")
  {
    id = i;
    cout<<"Obj:"<<this<<endl;
    cout<<"id="<<id<<endl;
    cout<<"position="<<position<<endl;
  }
  
  ~Demo()
  {
    cout<<"Destructor Obj:"<<this<<endl;
    cout<<"id="<<id<<endl;
    cout<<"position="<<position<<endl;
  }

};

Demo d1(1,"Global");

void Func()
{
  cout<<"enter Func():"<<endl;
  static Demo d2(2, "inside Func(), static");
  
  Demo d3(3, "inside Func()");
  cout<<"exit Func()"<<endl;
}

int main()
{
  cout<<"enter main():"<<endl;
  Demo d4(4, "inside main()");
  
  d4 = 7;
  
  cout<<"enter block{}:"<<endl;
  {
    Demo d5(5,"inside main()");
  }
  cout<<"exit block{}"<<endl;

  static Demo d6(6, "inside main(), static");

  Func();

  cout<<"main() ends"<<endl;
  return 0;
}

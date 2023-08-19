#include<iostream>
using namespace std;

class another;

class Base
{
private:
  float x;
public:
  void print(const another& K);
};

class Derived:public Base
{
private:
  float y;
};

class Derived2:public Base{
public:
  void print(const another&);
};

class another
{
private:
  int aaa;
public:
  another()
  {
    aaa = 100;
  }
  friend void Base::print(const another &K);
  friend void Derived2::print(const another& K);
};

void Base::print(const another& K)
{
  cout<<"Base:"<<K.aaa<<endl;
}

void Derived2::print(const another& K)
{
  cout<<"Derived2:"<<K.aaa<<endl;
}

int main()
{
  Base a;
  Derived d;
  Derived2 d2;
  another ano;
  a.print(ano);
  d.print(ano);
  d2.print(ano);

  return 0;
}

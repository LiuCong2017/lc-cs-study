#include <iostream>
using namespace std;

class myComplex
{
private:
  double real, imag;
public:
  myComplex();
  myComplex(double r,double i);
  friend class oper;
};

myComplex::myComplex()
{
  real = 0;
  imag = 0;
}

myComplex::myComplex(double r,double i)
{
  real = r;
  imag = i;
}

class oper
{
public:
  myComplex addCom(myComplex c1,myComplex c2);
  void outCom(myComplex c);
};

myComplex oper::addCom(myComplex c1,myComplex c2)
{
  return myComplex(c1.real+c2.real, c1.imag+c2.imag);
}

void oper::outCom(myComplex c)
{
  cout<<"("<<c.real<<","<<c.imag<<")";
}

int main()
{
  myComplex c1(1,2),c2(3,4),res;
  oper o;
  res = o.addCom(c1,c2);
  
  o.outCom(c1);
  cout<<"+";
  o.outCom(c2);
  cout<<"=";
  o.outCom(res);
  cout<<endl;

  return 0;
}

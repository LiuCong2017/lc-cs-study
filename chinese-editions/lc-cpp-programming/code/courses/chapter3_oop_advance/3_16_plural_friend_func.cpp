#include <iostream>
using namespace std;

class myComplex
{
private:
  double real, imag;

public:
  myComplex();
  myComplex(double r,double i);
  friend myComplex addCom(myComplex c1, myComplex c2);
  friend void outCom(myComplex c);
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

myComplex addCom(myComplex c1,myComplex c2)
{
  return myComplex(c1.real+c2.real,c1.imag+c2.imag);
}

void outCom(myComplex c)
{
  cout<<"("<<c.real<<","<<c.imag<<")";
}

int main()
{
  myComplex c1(1,2), c2(3,4), res;
  res = addCom(c1,c2);

  outCom(c1);
  cout<<"+";
  outCom(c2);
  cout<<"=";
  outCom(res);
  cout<<endl;
  
  return 0;
}

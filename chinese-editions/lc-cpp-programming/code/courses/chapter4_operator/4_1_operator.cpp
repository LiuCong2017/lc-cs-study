#include <iostream>
using namespace std;

class myComplex
{
private:
  double real,imag;

public:
  myComplex();
  myComplex(double,double);
  void outCom();
  myComplex operator-(const myComplex &c);
  friend myComplex operator+(const myComplex &c1, const myComplex &c2);
};

myComplex::myComplex()
{
  real = 0;
  imag = 0;
}

myComplex::myComplex(double real,double imag)
{
  this->real = real;
  this->imag = imag;
}

void myComplex::outCom()
{
  cout<<"("<<real<<","<<imag<<")";
}

myComplex myComplex::operator-(const myComplex &c)
{
  return myComplex(this->real - c.real, this->imag - c.imag);
}

myComplex operator+(const myComplex &c1, const myComplex &c2)
{
  return myComplex(c1.real+c2.real, c1.imag+c2.imag);
}

int main()
{
  myComplex c1(1,2),c2(3,4),res;
  
  c1.outCom();
  cout<<"operator+";
  c2.outCom();
  cout<<"=";
  res = c1+c2;
  res.outCom();
  cout<<endl;
 
  cout<<"-------"<<endl;

  c1.outCom();
  cout<<"operator-";
  c2.outCom();
  cout<<"=";
  res = c1 - c2;
  res.outCom();
  cout<<endl;

  return 0;
}

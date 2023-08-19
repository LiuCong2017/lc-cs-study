#include <iostream>
#include <string>
using namespace std;

class myComplex
{
private:
  double real,imag;

public:
  myComplex();
  myComplex(double r,double i);
  ~myComplex(){}
  
  myComplex addCom(myComplex c1);
  void outCom();
  void outCom(string s);
  void changeReal(double r);
  
  friend myComplex operator+(const myComplex &c1, const myComplex &c2);
  friend myComplex operator+(const myComplex &c1, double r);
  friend myComplex operator+(double r,const myComplex &c1);

  friend myComplex operator-(const myComplex &c1, const myComplex &c2);
  friend myComplex operator-(const myComplex &c1, double r);
  friend myComplex operator-(double r, const myComplex &c1);

  myComplex &operator=(const myComplex &c);
  myComplex &operator=(double);  
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

myComplex myComplex::addCom(myComplex c1)
{
  return myComplex(this->real+c1.real,this->imag+c1.imag);
}

void myComplex::outCom()
{
  cout<<"("<<real<<","<<imag<<")";
}

void myComplex::outCom(string s)
{
  cout<<s<<"=("<<real<<","<<imag<<")"<<endl;
}

void myComplex::changeReal(double r)
{
  this->real = r;
}

myComplex operator+(const myComplex &c1,const myComplex &c2)
{
  return myComplex(c1.real+c2.real, c1.imag+c2.imag);
}

myComplex operator+(const myComplex &c1,double r)
{
  return myComplex(c1.real+r,c1.imag);
}

myComplex operator+(double r, const myComplex &c1)
{
  return myComplex(r+c1.real,c1.imag); 
}

myComplex operator-(const myComplex &c1, const myComplex &c2)
{
  return myComplex(c1.real-c2.real, c1.imag-c2.imag);
}

myComplex operator-(const myComplex &c1,double r)
{
  return myComplex(c1.real-r,c1.imag);
}

myComplex operator-(double r,const myComplex &c1)
{
  return myComplex(r-c1.real,-c1.imag);
}

myComplex &myComplex::operator=(const myComplex &c1)
{
  this->real = c1.real;
  this->imag = c1.imag;
  return *this;
}

myComplex &myComplex::operator=(double r)
{
  this->real = r;
  this->imag = 0;
  return *this;
}

int main()
{
  myComplex c1(1,2),c2(2,3),res;
  c1.outCom("c1");
  c2.outCom("c2");
  res = c1+c2;
  res.outCom("res=c1+c2:");
  
  res = c1.addCom(c2);
  res.outCom("res=c1.addCom(c2):");
  
  res = c1+5;
  res.outCom("res=c1+5:");
  
  res = 5+c1;
  res.outCom("res=5+c1:");

  res = c1;
  c1.outCom("c1");
  res.outCom("res=c1:");

  c1.changeReal(-3);
  c1.outCom("c1.changeReal(-3):");
  res.outCom("res:");
  
  res = c1;
  res.outCom("res:");
  
  res = 7;
  res.outCom("res=7:");
  
  res = 7+8;
  res.outCom("res=7+8:");
  
  res = c1 = c2;
  c1.outCom("c1");
  c2.outCom("c2");
  res.outCom("res=c1=c2:"); 

  return 0;
}













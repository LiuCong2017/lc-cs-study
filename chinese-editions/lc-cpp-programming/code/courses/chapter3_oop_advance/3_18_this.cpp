#include <iostream>
using namespace std;

class myComplex
{
public:
  double real,imag;
  myComplex():real(0),imag(0){};
  myComplex(double,double);
  myComplex AddRealOne();
  myComplex AddImagOne();
  void outCom();
};

myComplex::myComplex(double real,double imag)
{
  this->real = real;
  this->imag = imag;
}

void myComplex::outCom()
{
  cout<<"("<<real<<","<<imag<<")";
}

myComplex myComplex::AddRealOne()
{
  this->real++;
  return *this;
}

myComplex myComplex::AddImagOne()
{
  this->imag++;
  return *this;
}

int main()
{
  myComplex c1(1,1),c2,c3;
  c1.outCom();
  c2.outCom();
  c3.outCom();

  cout<<"---------"<<endl;
  
  c2 = c1.AddRealOne();
  c1.outCom();

  c3 = c1.AddImagOne();
  c2.outCom();
  c3.outCom();

  cout<<endl;

  return 0;
}

#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class myComplex
{
private:
  double real, imag;

public:
  myComplex():real(0),imag(0){}
  myComplex(double r,double i):real(r),imag(i){}
  friend ostream& operator<<(ostream& os, const myComplex& c);
  friend istream& operator>>(istream& is, myComplex& c);
};

ostream& operator<<(ostream& os, const myComplex& c)
{
  if(c.imag>=0)
    os<<c.real<<"+"<<c.imag<<"i";
  else
    os<<c.real<<"-"<<(-c.imag)<<"i";
  
  return os;
}

istream& operator>>(istream& is, myComplex& c)
{
  string s;
  is>>s;
  int pos = s.find("+",0);
  if(pos == -1) pos = s.find("-",1);
  string sReal = s.substr(0,pos);
  c.real = atof(sReal.c_str());
  sReal = s.substr(pos,s.length()-pos-1);
  c.imag = atof(sReal.c_str());
  
  return is;
}

int main()
{
  myComplex c, c1;
  int n;
  cout<<"input two number([-]a+-bi) and a int number, split with space"<<endl;
  cin>>c>>c1>>n;
  cout<<c<<","<<n<<","<<c1;

  return 0;
}

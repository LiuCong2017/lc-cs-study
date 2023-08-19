#include<iostream>
using namespace std;

class Base
{
public:
  int pub;
protected:
  int pro;
private:
  int pri;
public:
  Base();
  void setProValue(int,int);
  void setPriValue(int); 
  int getProValue();
  int getPriValue();
};

Base::Base():pub(10),pro(20),pri(30){}

void Base::setProValue(int a,int b)
{
  this->pro=a;
  this->pri=b;
}

void Base::setPriValue(int a)
{
  this->pri = a;
}

int Base::getProValue()
{
  return this->pro;
}

int Base::getPriValue()
{
  return this->pri;
}

class Derived:public Base
{
public:
  int dPub,pub;
protected:
  int dPro;
private:
  int dPri;
public:
  Derived();
  void setProValue(int,int);
  void setPriValue(int);
  int getProValue();
  int getPriValue();
  void printValue();
};

Derived::Derived():dPub(100),dPro(200),dPri(300),pub(15){}

void Derived::setProValue(int a,int b)
{
  this->dPro = a;
  this->dPri = b;
  Base::pro = 2*a;
}

void Derived::setPriValue(int a)
{
  this->dPri = a;
}

int Derived::getProValue()
{
  return this->dPro;
}

int Derived::getPriValue()
{
  return this->dPri;
}

void Derived::printValue()
{
  cout<<"acess Base in Derived"<<endl;
  cout<<"Base's pub:"<<pub<<endl;
  cout<<"Base's pro:"<<pro<<endl;
  cout<<"Base's pri:"<<Base::getPriValue()<<endl;
  
  cout<<"access Derived in Derived"<<endl;
  cout<<"Derived's pub:"<<dPub<<endl;
  cout<<"Derived's pro:"<<dPro<<endl;
  cout<<"Derived's pri:"<<dPri<<endl;

  cout<<"extends from Base's pub:"<<Base::pub<<endl;
  cout<<"extends from Base's pro:"<<Base::pro<<endl;
//  cout<<"extends from Base's pri:"<<Base::pri<<endl;
}

int main()
{
  Base b;
  Derived d;
  
  cout<<"access Base inside main()"<<endl;
  cout<<"pub:"<<b.pub<<endl;
//  cout<<"pro:"<<b.pro<<endl;
  cout<<"pro:"<<b.getProValue()<<endl;
  cout<<"pri:"<<b.getPriValue()<<endl;

  cout<<"access Derived inside main()"<<endl;
  cout<<"dPub:"<<d.dPub<<endl;
//  cout<<"dPro:"<<d.dPro<<endl;
  cout<<"dPro:"<<d.getProValue()<<endl;
  cout<<"dPri:"<<d.getPriValue()<<endl;
  
  cout<<"d.pub"<<d.pub<<endl;
  cout<<"d.Base::pub"<<d.Base::pub<<endl;
  d.printValue();

  return 0;
}

























#include <iostream>
using namespace std;

class pointer
{
public:
  int a;
  int* p;
  pointer()
  {
    a = 100;
    p = new int(10);
  }
  pointer(const pointer& tempp)
  {
    if(this != &tempp)
    {
      a = tempp.a;
      p = new int();
      *p = *tempp.p;
    }
  }
  ~pointer()
  {
    if(p!=NULL) delete p;
  }
  pointer& operator=(const pointer& c)
  {
    if(this == &c) return *this;
    delete this->p;
    this->p = new int(*c.p);
    return *this;
  }
};

int main()
{
  pointer p1;
  pointer p2(p1);
  pointer p3;
  
  p1 = p1;
  p3 = p1;

  cout<<"After inital, every object's value and memory address:"<<endl;
  cout<<"p1:"<<&p1<<","<<p1.a<<","<<p1.p<<","<<*p1.p<<","<<&p1.p<<endl;
  cout<<"p2:"<<&p2<<","<<p2.a<<","<<p2.p<<","<<*p2.p<<","<<&p2.p<<endl;
  cout<<"p3:"<<&p3<<","<<p3.a<<","<<p3.p<<","<<*p3.p<<","<<&p3.p<<endl;

  *p1.p = 20;
  p2.a = 300;
  cout<<"After modify, every object's value and memory address:"<<endl;
  cout<<"p1:"<<&p1<<","<<p1.a<<","<<p1.p<<","<<*p1.p<<","<<&p1.p<<endl;
  cout<<"p2:"<<&p2<<","<<p2.a<<","<<p2.p<<","<<*p2.p<<","<<&p2.p<<endl;
  cout<<"p3:"<<&p3<<","<<p3.a<<","<<p3.p<<","<<*p3.p<<","<<&p3.p<<endl;

  return 0;
}

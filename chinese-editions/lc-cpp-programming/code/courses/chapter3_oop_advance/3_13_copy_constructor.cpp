#include <iostream>
using namespace std;

class A
{
public:
  A()
  {
    cout<<"default constructor"<<endl;
  }
  A(A &a)
  {
    cout<<"copy constructor"<<endl;
  }
};

class B
{  
  A a;
};

int main()
{
  B b1, b2(b1);
  return 0;
}

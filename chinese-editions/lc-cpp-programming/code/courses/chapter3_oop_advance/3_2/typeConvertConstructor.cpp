#include <iostream>
using namespace std;

class Demo
{
  int id;

public:
  Demo(int i)
  {
    id=i;
    cout<<"constructor"<<endl;
  }

  void printDemo();

  ~Demo()
  {
    cout<<"destructor"<<endl;
  }
};

void Demo::printDemo()
{
  cout<<"id="<<id<<endl;
}

int main()
{
  Demo d4(4);
  d4.printDemo();
  d4 = 6;
  d4.printDemo();
  return 0;
}

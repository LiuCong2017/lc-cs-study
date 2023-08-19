#include <iostream>
using namespace std;

int fvalue = 10;
class CDemo
{
public:
  const int num;
  const int& ref;
  int value;
public:
  CDemo(int n):num(n),ref(value),value(4){} 
};

int main()
{
  cout<<sizeof(CDemo)<<endl;
  CDemo f(100);
  
  //f.ref = f.value;  

  cout<<"f.num="<<f.num<<endl;
  cout<<"f.ref="<<f.ref<<endl;
  cout<<"f.value="<<f.value<<endl;

  return 0;
}

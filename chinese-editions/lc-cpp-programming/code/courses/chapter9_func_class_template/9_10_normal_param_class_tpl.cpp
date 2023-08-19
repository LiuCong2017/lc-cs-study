#include <iostream>
using namespace std;

template<int i>
class TestClass
{
public:
  int buffer[i];
  int getData(int j);
};

template<int i>
int TestClass<i>::getData(int j)
{
  return *(buffer+j);
}

int main()
{
  TestClass<6> ClassInstF;
  int i;
  double fArr[6] = {32.5,23.9,12,24.02,12.19,23.9};
  for(i=0;i<6;i++)
    ClassInstF.buffer[i] = fArr[i] - 10;
  for(i=0;i<6;i++)
  {
    double res = ClassInstF.getData(i);
    cout<<res<<" ";
  }
  cout<<endl;

  return 0;
}

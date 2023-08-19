#include <iostream>
using namespace std;

template <class T>
class TestClass
{
public:
  T buffer[10];
  T getData(int j);
};

template <class T>
T TestClass<T>::getData(int j)
{
  return *(buffer+j);
}

int main()
{
  TestClass<char> ClassInstA;
  int i;
  char cArr[6] = "abcde";
  for(i=0;i<5;i++)
    ClassInstA.buffer[i] = cArr[i];
  for(i=0;i<5;i++)
  {
    char res = ClassInstA.getData(i);
    cout<<res<<" ";
  }  
  cout<<endl;

  TestClass<double> ClassInstF;
  double fArr[6] = {12.1,23.1,23,56.6,78.4,23.02};
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


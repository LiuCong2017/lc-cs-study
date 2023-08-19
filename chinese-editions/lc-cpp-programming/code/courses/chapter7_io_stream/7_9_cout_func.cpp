#include <iostream>
using namespace std;

int main()
{
  double values[] = {1.24,3.24,28.21,10.24,400.243532,199992.123545};
  cout.fill('*');
  for(int i=0;i<sizeof(values)/sizeof(double);i++)
  {
    cout<<"values["<<i<<"]=(";
    cout.width(10);
    cout<<values[i]<<")"<<endl;
  }
  cout.fill(' ');
  for(int i=0;i<sizeof(values)/sizeof(double);i++)
  {
    cout<<"values["<<i<<"]=(";
    cout.width(10);
    cout.precision(i+3);
    cout<<values[i]<<")"<<endl;
  }

  return 0;
}

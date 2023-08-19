#include <iostream>
using namespace std;

int main()
{
  int x,count,sum=0;
  freopen("input.dat","r",stdin);
  for(count=0;count<10;count++)
  {
    cin>>x;
    sum += x;
  }
  cout<<"10 int average value="<<1.0*sum/10<<endl;

  return 0;
}

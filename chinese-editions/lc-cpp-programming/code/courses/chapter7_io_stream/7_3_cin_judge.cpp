#include <iostream>
using namespace std;

int main()
{
  int x,count,sum=0;
  freopen("input.dat","r",stdin);
  for(count=0;count<10;count++)
  {
    cin>>x;
    if(cin.eof()) break;
    else sum += x;
  }  
  cout<<"the "<<count<<" int average value="<<1.0*sum/count<<endl;

  return 0;
}

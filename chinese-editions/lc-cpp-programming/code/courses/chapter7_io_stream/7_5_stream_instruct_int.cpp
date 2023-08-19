#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int n=65535,m=20;
  cout<<"1)"<<n<<"="<<hex<<n<<"="<<oct<<n<<endl;
  cout<<"2)"<<setbase(10)<<m<<"="<<setbase(16)<<m<<"="<<setbase(8)<<m<<endl;
  cout<<"3)"<<showbase;
  cout<<setbase(10)<<m<<"="<<setbase(16)<<m<<"="<<setbase(8)<<m<<endl;
  
  return 0;
}


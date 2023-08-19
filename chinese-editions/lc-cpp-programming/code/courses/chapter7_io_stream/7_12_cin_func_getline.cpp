#include <iostream>
using namespace std;

int main()
{
  char buf[10];
  int i = 0;
  while(cin.getline(buf,10))
    cout<<++i<<":"<<buf<<endl;
  cout<<"last:"<<buf<<endl;

  return 0;
}

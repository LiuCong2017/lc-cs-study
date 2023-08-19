#include<iostream>
using namespace std;
int main()
{
  int q1 = 1;
  int& ref = q1;
  const int& refc = q1;
  
  ref = 2;
  
  cout<<"q1="<<q1<<","<<"ref="<<ref<<endl;
  cout<<"refc="<<refc<<endl;
  
  q1 = 3;
  cout<<"ref="<<ref<<endl;
  cout<<"refc="<<refc<<endl;
  
  int& ref2 = ref;
  cout<<"ref2="<<ref2<<endl;

  return 0;
}

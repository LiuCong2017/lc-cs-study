#include <iostream>
using namespace std;

static int glos = 100;

void f()
{
  int a = 1;
  static int fs = 1;
  
  cout<<"inside f()"<<endl;
  cout<<"a="<<a<<endl;
  cout<<"fs="<<fs<<endl;
  cout<<"glos="<<glos<<endl;

  a += 2;
  fs += 2;
  glos += 10;
  
  cout<<"inside f()"<<endl;
  cout<<"a="<<a<<endl;
  cout<<"fs="<<fs<<endl;
  cout<<"glos="<<glos<<endl;

  cout<<"------------"<<endl;

}

int main()
{
  static int ms = 10;
  for(int i=1;i<=3;i++){
    f();
  }

  cout<<"ms="<<ms<<endl;
  cout<<"glos="<<glos<<endl;

  return 0;

}

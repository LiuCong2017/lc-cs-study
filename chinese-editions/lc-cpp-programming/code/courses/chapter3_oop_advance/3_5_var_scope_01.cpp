#include <iostream>
using namespace std;

int main()
{
  int i =10;
  char ch = '1';
  cout<<"inside main(), i="<<i<<endl;
  cout<<"inside main(), ch="<<ch<<endl;
  
  {
    int i = 20;
    char ch = '2';
    cout<<"inside outdoor block, i="<<i<<endl; 
    cout<<"inside outdoor block, ch="<<ch<<endl;
   
    if(i>0)
    {
      double i = 30.3;
      int ch = 33;
      cout<<"inside indoor block, i="<<i<<endl; 
      cout<<"inside indoor block, ch="<<ch<<endl; 
    }
 
    cout<<"inside outdoor block, i="<<i<<endl; 
    cout<<"inside outdoor block, ch="<<ch<<endl; 
    
  }

  cout<<"inside main(), i="<<i<<endl;
  cout<<"inside main(), ch="<<ch<<endl;

  return 0;
}

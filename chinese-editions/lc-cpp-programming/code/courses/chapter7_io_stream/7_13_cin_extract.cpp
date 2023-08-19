#include <iostream>
using namespace std;

int main()
{
  char str[30];
  while(!cin.eof())
  {
    cin.ignore(10,':');
    if(!cin.eof())
    {
      cin>>str;
      cout<<str<<endl;
    }
  }

  return 0;
}

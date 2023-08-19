#include <iostream>
#include <string>
using namespace std;

int main()
{
  char ch;
  int sum=0, count=0, x;
  cout<<"input int (press Ctrl+D exit):"<<endl;
  do{
    while(cin>>x)
    {
      sum += x;
      count++;
    }
    cout<<"comfirm exit? press Q";
    cin.clear();
    cin>>ch;
  }while (toupper(ch) != 'Q');
  cout<<"sum="<<sum<<",count="<<count<<endl;

  return 0;
}

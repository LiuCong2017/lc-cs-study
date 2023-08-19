#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
  char ch,filename[20];
  int count = 0;
  bool newline = true;
  cout<<"input file name:"<<endl;
  cin>>filename;
  
  ifstream inFile(filename,ios::in);
  if(!inFile){
    cout<<"failed"<<endl;
    return 0;
  }

  while((ch=inFile.get())!=EOF)
  {
    if(newline)
    {
      cout<<setw(4)<<++count<<':';
      newline = false;
    }
    if(ch == '\n')
       newline = true;
    cout<<ch;
  }
  inFile.close();

  return 0;
}

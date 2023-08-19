#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream inFile("test.txt",ios::in);
  if(inFile)
  {
    cout<<"open"<<endl;
    inFile.close();
  }else{
    cout<<"error"<<endl;
  }
  
  ofstream outFile("test.txt",ios::out);
  if(!outFile){
    cout<<"error"<<endl;
  }else{
    cout<<"open"<<endl;
    outFile.close();
  }

  fstream fsFile("test.txt",ios::out|ios::in);
  if(fsFile){
    cout<<"open"<<endl;
    fsFile.close();
  }else{
    cout<<"error"<<endl;
  }

  return 0;
}

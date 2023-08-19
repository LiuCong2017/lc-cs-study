#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream inFile;
  inFile.open("test.txt",ios::in);
  if(inFile)
  {
    cout<<"sucess open file: test.txt\n";
    inFile.close();
  }else{
    cout<<"open file failed: test.txt\n";
  }
  
  ofstream outFile;
  outFile.open("test.txt",ios::out);
  if(!outFile){
    cout<<"error"<<endl;
  }else{
    cout<<"success open file:\n";
    outFile.close();
  }

  outFile.open("text.txt",ios::out|ios::in);
  if(outFile)
  {
    cout<<"success open file:";
    outFile.close();
  }else{
    cout<<"error"<<endl;
  }

  fstream ioFile;
  ioFile.open("test.txt",ios::out|ios::in|ios::trunc);
  if(!ioFile){
    cout<<"error"<<endl;
  }else{
    cout<<"success open file:"<<endl;
    ioFile.close();
  }
 

  return 0;
}

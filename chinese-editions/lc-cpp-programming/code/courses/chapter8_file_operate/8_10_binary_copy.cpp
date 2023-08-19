#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
  if(argc != 3)  //判断main的参数
  {
    cout<<"error, format: mycopy [srcFile] [destFile]"<<endl;
    return 0;
  }
  
  ifstream inFile(argv[1], ios::binary|ios::in);
  if(!inFile)
  {
    cout<<"srcFile open error."<<endl;
    return 0;
  }

  ofstream outFile(argv[2],ios::binary|ios::out);
  if(!outFile)
  {
    cout<<"destFile open error."<<endl;
    inFile.close();
    return 0;
  }

  char c;
  while(inFile.get(c))
    outFile.put(c);

  outFile.close();
  inFile.close();

  return 0;
}

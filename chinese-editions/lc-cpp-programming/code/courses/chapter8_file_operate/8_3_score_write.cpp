#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  char id[11], name[21];
  int score;
  ofstream outFile;
  outFile.open("score.txt",ios::out);
  if(!outFile){
    cout<<"failed"<<endl;
    return 0;
  }
  
  cout<<"input id,name,score:(end with ctrl+D)"<<endl;
  while(cin>>id>>name>>score)
    outFile<<id<<"-"<<name<<"-"<<score<<endl;
  outFile.close();

  return 0;
}

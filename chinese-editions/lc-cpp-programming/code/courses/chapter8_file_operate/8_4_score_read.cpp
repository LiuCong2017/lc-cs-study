#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
  char id[11],name[21];
  int score;
  ifstream inFile;
  inFile.open("score.txt",ios::in);
  if(!inFile){
    cout<<"failed"<<endl;
    return 0;
  }

  cout<<"id - name - score:"<<endl;
  while(inFile>>id>>name>>score)
    cout<<left<<setw(10)<<id<<"-"<<setw(20)<<name<<"-"<<setw(3)<<right<<score<<endl;
  inFile.close();

  return 0;
}

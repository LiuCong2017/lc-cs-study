#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class CStudent
{
public:
  char id[11];
  char name[21];
  int score;
};

int main()
{
  CStudent stu;
  int count=0,nbyte=0;
  ifstream inFile("students.dat",ios::in|ios::binary);
  if(!inFile)
  {
    cout<<"create file failed"<<endl;
    return 0;
  }
  cout<<"id name score\n";
  while(inFile.read((char*)&stu, sizeof(stu)))
  {
    cout<<left<<setw(10)<<stu.id<<" "<<setw(20)<<stu.name<<" "<<setw(3)<<right<<stu.score<<endl;
    count++;
    nbyte += inFile.gcount();
  }
  cout<<"records:"<<count<<", bytes:"<<nbyte<<endl;
  inFile.close();

  return 0;
}

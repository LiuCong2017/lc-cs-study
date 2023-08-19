#include <iostream>
#include <fstream>
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
  ofstream outFile("students.dat",ios::out|ios::binary);
  if(!outFile)
  {
    cout<<"create file failed"<<endl;
    return 0;
  }
  
  cout<<"input: id name score\n";
  while(cin>>stu.id>>stu.name>>stu.score)
    outFile.write((char*)&stu, sizeof(stu));
  outFile.close();

  return 0;
}

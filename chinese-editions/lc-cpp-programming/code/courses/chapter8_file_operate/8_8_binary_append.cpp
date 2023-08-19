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
  char ch;
  cout<<"comfirm append? (Y/N)";
  cin>>ch;
  if(ch=='Y' || ch=='y')
  {
    CStudent stu;
    ofstream outFile("students.dat", ios::app|ios::binary);
    if(!outFile)
    {
      cout<<"open failed"<<endl;
      return 0;
    }
    cout<<"input: id name score\n";
    while(cin>>stu.id>>stu.name>>stu.score)
      outFile.write((char*)&stu,sizeof(stu));
    outFile.close();
  }

  return 0;
}

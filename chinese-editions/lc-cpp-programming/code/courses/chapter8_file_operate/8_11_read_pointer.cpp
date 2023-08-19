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
  }else{
    cout<<"the pointer location when open file:"<<inFile.tellg()<<endl;
    cout<<"every records' size:"<<sizeof(CStudent)<<endl;
  }

  cout<<"id name score pointer\n";
  while(inFile.read((char*)&stu,sizeof(CStudent)))
  {
    cout<<left<<setw(10)<<stu.id<<" "<<setw(20)<<stu.name<<" "<<setw(3)<<right<<stu.score<<"\t"<<inFile.tellg()<<endl;
    count++;
    nbyte+=inFile.gcount();
  }
  
  cout<<"the pointer location when end read file:"<<inFile.tellg()<<endl;
  cout<<"total records:"<<count<<", byte size:"<<nbyte<<endl;

  inFile.clear();
  inFile.seekg(0);
  cout<<"current location of pointer:"<<inFile.tellg()<<endl;
  inFile.read((char*)&stu,sizeof(stu));
  cout<<left<<setw(10)<<stu.id<<" "<<setw(20)<<stu.name<<" "<<setw(3)<<right<<stu.score<<endl;
  inFile.seekg(0,ios::end);
  cout<<"the pointer location:"<<inFile.tellg()<<endl;
  inFile.close();

  return 0;
};

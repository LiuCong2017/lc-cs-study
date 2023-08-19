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
  int count=0, maxScore, minScore, maxNo, minNo;
  maxScore = INT_MIN;
  minScore = INT_MAX;
  maxNo = minNo = 0;
  
  ifstream inFile("students.dat",ios::in|ios::binary);
  if(!inFile)
  {
    cout<<"create file failed"<<endl;
    return 0;
  }
  
  while(inFile.read((char*)&stu,sizeof(CStudent)))
  {
    if(stu.score>maxScore)
    {
      maxScore = stu.score;
      maxNo = count;
    }else if(stu.score<minScore){
      minScore = stu.score;
      minNo = count;
    }
    count++;
  }
  
  inFile.clear();
  inFile.seekg(sizeof(CStudent)*maxNo,ios::beg);
  inFile.read((char*)&stu, sizeof(CStudent));
  cout<<"minScore record:"<<minNo<<":"<<stu.id<<","<<stu.name<<","<<stu.score<<endl;
  inFile.close();

  return 0;
}

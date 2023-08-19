#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int MAX_NUM = 1000;

class CStudent
{
public:
  char id[11];
  char name[21];
  int score;
} stu[MAX_NUM];

int MyCompare(const void* e1,const void* e2)
{
  return (*(CStudent*)e1).score - (*(CStudent*)e2).score;
}

int main()
{
  ifstream srcFile("score.txt",ios::in);
  if(!srcFile){
    cout<<"src error"<<endl;
    return 0;
  }
  
  ofstream destFile("out.txt",ios::out);
  if(!destFile){
    srcFile.close();
    cout<<"dest error"<<endl;
    return 0;
  }

  int n=0;
  cout<<"before sort:"<<endl;
  while(srcFile>>stu[n].id>>stu[n].name>>stu[n].score)
  {
    cout<<stu[n].id<<" "<<stu[n].name<<" "<<stu[n].score<<endl;
    n++;
  }

  qsort(stu,n,sizeof(CStudent),MyCompare);

  cout<<"after sort:"<<endl;
  for(int i=0;i<n;i++){
    cout<<stu[i].id<<" "<<stu[i].name<<" "<<stu[i].score<<endl;
    destFile<<stu[i].id<<" "<<stu[i].name<<" "<<stu[i].score<<endl;
  }
  destFile.close();
  srcFile.close();

  return 0;
}

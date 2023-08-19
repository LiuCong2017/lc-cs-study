#include<iostream>
using namespace std;
int main()
{
  const int cInt = 30;
  int oneInt = 50;
  int& ref = oneInt; //T& <- T
  const int& rc1 = cInt; //CT& <- CT
  const int& rc2 = oneInt; //CT& <- T
  const int& rc3 = ref; //CT& <- T&
  
  int dInt = ref; //T <- T&
  int eInt = cInt; //T <- CT
  int fInt = rc1; //T <- CT&
  
  const int gInt = oneInt; //CT <- T
  int& ref1 = ref; //T& <- T&
  
  const int hInt = ref; //CT <- T&
  const int jInt = cInt; //CT <- CT
  const int& mInt = rc1; //CT& <- CT&
  const int nInt = rc2; //CT <- CT&
  
  cout<<"------"<<endl;

  int& r2 = (int&) rc1; //T& <- CT&
  int& r3 = (int&) cInt; //T& <- CT

  return 0;
}

#include<iostream>
#include<string>
using namespace std;
int main(){
  int int1, int2;
  char strArr[20];
  string str;
  double db1;
  char char1='a';

  cout<<"input 2 int, 1 char, 1 string, 1 double:"<<endl;
  cin>>int1>>int2>>char1>>strArr>>db1;
  
  str = strArr;
  cout<<"input data type: 1 string-"<<str<<" 2int:"<<int1<<"_"<<int2<<" 1 char:"<<char1<<" 1 double:"<<db1<<endl;

  return 0;
}

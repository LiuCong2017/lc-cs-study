#include<iostream>
using namespace std;

void func(int a=11,int b=22,int c=33){
  cout<<"a="<<a<<",b="<<b<<",c="<<c<<endl;
}

int main(){
  func();
  func(55);
  func(66,77);
  func(88,99,00);
  return 0;
}

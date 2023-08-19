#include<iostream>
using namespace std;

int main(){
  int a = 10;
  const int* p = &a;

  const int ca = 30;
  int* q;
  
  cout<<"a's address: "<<&a<<"\t a's value: "<<a<<endl;
  cout<<"p point to: "<<p<<"\t p's value: "<<*p<<endl;
  
  cout<<"--------"<<endl;

  q = const_cast<int*>(p); //convert const pointer to none const pointer but still point to original address
  *q = 20;
  
  cout<<"a's address: "<<&a<<"\t a's value: "<<a<<endl; 
  cout<<"p point to: "<<p<<"\t p's value: "<<*p<<endl; 
  cout<<"q point to: "<<q<<"\t q's value: "<<*q<<endl;
  
  cout<<"--------"<<endl;
  
  p = &ca;
  q = const_cast<int*>(p);
  *q = 40;

   
  cout<<"ca's address: "<<&ca<<"\t ca's value: "<<ca<<endl; 
  cout<<"p point to: "<<p<<"\t p's value: "<<*p<<endl; 
  cout<<"q point to: "<<q<<"\t q's value: "<<*q<<endl;

  return 0;
}

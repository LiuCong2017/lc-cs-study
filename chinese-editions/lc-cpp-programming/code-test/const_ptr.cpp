#include <iostream>
using namespace std;

void func(const int* no, const string* str){
    cout<<*no<<"-"<<*str<<endl;
}

void func(string n,void* p){
    cout<<n<<"-addr-"<<p<<endl;
    cout<<n<<"-val-"<<*(char*)p<<endl;
}

int main()
{
    int a=3,b=9;
    const int* cp = &a; //常量指针
    a = 13;
    cout<<"a="<<a<<",*cp="<<*cp<<endl;
    cp = &b;
    cout<<"b="<<b<<",*cp="<<*cp<<endl;

    int* const pc = &a; //指针常量
    *pc = 19;
    cout<<"a="<<a<<",*pc="<<*pc<<endl;

    const int* const cpc = &a; //常指针常量
//    *cpc = 20;
//    cpc = &b;

    char y = 'Y';
    func("x",&y);

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int func1(int b){
    return b;
}
bool func2(int n,int m){
    return n>m;
}

void pr(int a)
{
    cout<<"a="<<a<<endl;
}

void show(void (*pf)(int),int b)
{
    pf(b);
}

int main()
{
    string (*str)(int,string);
    int (*p1)(int) = func1;
    bool (*p2)(int,int) = func2;

    int res1 = (*p1)(2);
    bool res2 = p2(3,5);

    show(pr,8);

    return 0;
}
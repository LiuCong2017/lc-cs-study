#include <iostream>
using namespace std;

void func(int **pp)
{
    *pp = new int(3);
    cout<<"pp="<<pp<<",*pp="<<*pp<<endl;
}

int main()
{
    int ii = 8;
    int* pii = &ii;
    cout<<"pii="<<pii<<",pii addr: "<<&pii<<",*pii="<<*pii<<endl;

    int** ppii = &pii;
    cout<<"ppii="<<ppii<<",ppii addr:"<<&ppii<<",*ppii="<<*ppii<<endl;
    cout<<"**ppii="<<**ppii<<endl;

    int* p = 0;
    func(&p);
    int ** pp = &p;
    *pp = new int(3);
    cout<<"pp="<<pp<<",*pp="<<*pp<<endl;
    cout<<"p="<<p<<",*p="<<*p<<endl;

    return 0;
}
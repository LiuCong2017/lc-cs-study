#include <iostream>
using namespace std;

int main()
{
    int* p = new int(5);
    cout<<"*p="<<*p<<endl;
    *p = 8;
    cout<<"*p="<<*p<<endl;
    delete p;

    return 0;
}
#include <iostream>
using namespace std;

int main(){
    const int n = 100;
    int *p = const_cast<int*>(&n);
    *p = 234;
    cout<<"n="<<n<<endl;
    cout<<"*p="<<*p<<endl;

    return 0;
}
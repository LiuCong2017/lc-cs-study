#include <iostream>
using namespace std;

template <typename X>
X func(X a,X b){
    return a;
}

int main()
{
    cout<<func(15,8)<<endl;
    cout<<func('p','q')<<endl;
    cout<<func(7.5,9.2)<<endl;

    return 0;
}
#include <iostream>
using  namespace  std;

class A
{
public:
    bool isTrue;
    int num;

    inline A();
};

int main()
{
    A a;
    if(a.isTrue) cout<<a.num;

    return 0;
}
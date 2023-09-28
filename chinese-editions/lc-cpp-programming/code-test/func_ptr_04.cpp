#include <iostream>
using namespace std;

class A{
public:
    void fl(int);
};

void A::fl(int value) {
    cout<<value<<endl;
}

int main()
{
    A a;
    void (A::*p)(int) = &A::fl;

    (a.*p)(43);

    return 0;
}
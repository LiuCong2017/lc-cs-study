//
// Created by kavin on 2023/7/30.
//
#include <iostream>
using namespace std;

class A{
    int a;
public:
    A(int param)
    {
        a = param;
    }
    int geta() const
    {
        return a;
    }
};

int main(){
    A cb(1);
    const A ca(2);
    int b = ca.geta();
    cb.geta();

    return 0;
}
#include <iostream>
using namespace std;

class A{
public:
    A(int a=0,int b=0):m_a(a),m_b(b){}
private:
    int m_a;
    int m_b;
};

int main()
{
    char str[] = "test";
    float *p1 = reinterpret_cast<float*>(str); //char* -> float*
    cout<<*p1<<endl;

    int *p = reinterpret_cast<int*>(100); //int -> int*
    p = reinterpret_cast<int*>(new A(25,96)); //A* -> int*
    cout<<*p<<endl;

}
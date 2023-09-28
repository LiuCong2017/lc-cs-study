#include <iostream>
using namespace std;

int main()
{
    char a;      cout << "sizeof(char)=" << sizeof(char) << endl;            // 1字节
    short b;    cout << "sizeof(short)=" << sizeof(short) << endl;         // 2字节
    int c;         cout << "sizeof(int)=" << sizeof(int) << endl;                  // 4字节
    double d; cout << "sizeof(double)=" << sizeof(double) << endl;   // 8字节

    cout <<"a addr is:" << (void *)& a << endl;
    cout <<"a addr +1 is:" << (void*)( & a + 1) << endl;

    cout <<"b addr is:" << (void*)&b << endl;
    cout <<"b addr +1 is:" << (void*)(&b + 1) << endl;

    cout <<"c addr is:" << (void*)&c << endl;
    cout <<"c addr +1 is:" << (void*)(&c + 1) << endl;

    cout <<"d addr is:" << (void*)&d << endl;
    cout <<"d addr +1 is:" << (void*)(&d + 1) << endl;

    return 0;
}
#include <iostream>
using namespace std;

void arrSample1()
{
    double a[5];
    cout << "a's value is:" << (long long) a << endl;
    cout << "&a's value is:" << (long long)&a << endl;

    cout << "a[0]'s addr is:" << (long long) &a[0] << endl;
    cout << "a[1]'s addr is:" << (long long) &a[1] << endl;
    cout << "a[2]'s addr is:" << (long long) &a[2] << endl;
    cout << "a[3]'s addr is:" << (long long) &a[3] << endl;
    cout << "a[4]'s addr is:" << (long long) &a[4] << endl;

    double* p = a;
    cout << "p's value is: " << (long long)p << endl;
    cout << "p+0's value is: " << (long long)(p+  0) << endl;
    cout << "p+1's value is: " << (long long)(p + 1) << endl;
    cout << "p+2's value is: " << (long long)(p + 2) << endl;
    cout << "p+3's value is: " << (long long)(p + 3) << endl;
    cout << "p+4's value is: " << (long long)(p + 4) << endl;
}

void arrSample2()
{
    int a[5] = {3,6,5,8,9};

    // 用数组表示法操作数组。
    cout << "a[0]'s value is: " << a[0] << endl;
    cout << "a[1]'s value is: " << a[1] << endl;
    cout << "a[2]'s value is: " << a[2] << endl;
    cout << "a[3]'s value is: " << a[3] << endl;
    cout << "a[4]'s value is: " << a[4] << endl;

    // 用指针表示法操作数组。
    int* p = a;
    cout << "*(p+0)'s value is: " << *(p+  0) << endl;
    cout << "*(p+1)'s value is: " << *(p + 1) << endl;
    cout << "*(p+2)'s value is: " << *(p + 2) << endl;
    cout << "*(p+3)'s value is: " << *(p + 3) << endl;
    cout << "*(p+4)'s value is: " << *(p + 4) << endl;

}

int main()
{
    arrSample1();
    arrSample2();

    return 0;
}
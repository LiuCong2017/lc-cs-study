#include <iostream>         // 包含头文件。
using namespace std;        // 指定缺省的命名空间。

int main()
{
    // 声明 / 创建引用的语法：数据类型 & 引用名 = 原变量名;
    int a = 3;          // 声明普通的整型变量。
    int& ra = a;      // 创建引用ra，ra是a的别名。

    cout << " a's addr is: "<< &a  << ", a's value is: "<<  a  << endl;
    cout << "ra's addr is: "<< &ra << ", ra's value is: " << ra << endl;

    ra = 5;

    cout << " a's addr is: " << &a << ", a's value is: " << a << endl;
    cout << "ra's addr is: " << &ra << ", ra's value is: " << ra << endl;
}
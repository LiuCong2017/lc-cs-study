#include <iostream>
using namespace std;

void func1(int no,string str)
{
    no = 8;
    str = "Test str";
}

void func2(const int* no, const string* str)
{
    cout<<no<<"-"<<str<<endl;
}

void func3(const int& no, const string& str)
{
}

void func4(int no,string str="str", string msg="test"){}

int main()
{
    int b = 3;
    string msg = "Test str";

    func1(b,msg);
    func2(&b,&msg);
    func3(b,msg);
    func4(8,"hey");

    return 0;
}
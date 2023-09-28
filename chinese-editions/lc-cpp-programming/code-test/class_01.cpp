#include <iostream>
#include <string>
using namespace std;

class CBoy
{
public:
    string m_name;
    CBoy(){
        m_name.clear();
    }
    CBoy(const string& name){
        m_name = name;
    }
    CBoy(const CBoy& b){
        m_name = b.m_name;
    }
};

class CGirl
{
public:
    string m_name;
    int m_age;
    CBoy& m_boy;

    CGirl(const string& name, int age, CBoy &b) : m_boy(b) {
        m_name = name;
        m_age = age;
    }

    void show() const{
        cout<<m_name<<"-"<<m_age<<"-"<<m_boy.m_name<<endl;
    }
};


int main()
{
    CBoy boy("Cody");
    CGirl girl1("Alissa",28,boy);
    CGirl girl2 = girl1; //调用默认拷贝构造函数

    girl2.show();
    return 0;
}
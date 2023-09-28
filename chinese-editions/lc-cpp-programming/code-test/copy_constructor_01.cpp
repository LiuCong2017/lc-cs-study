#include <iostream>
#include <string>
using namespace std;

class CBoy{

};

class CGirl
{
public:
    string m_name;
    int m_age;

    CGirl(CBoy &mBoy) {
        m_name.clear();
        m_age = 0;
    }

    CGirl(const CGirl& g){
        m_name = g.m_name;
        m_age = g.m_age;
    }

    CGirl(const CGirl& g,int i){
        m_name=g.m_name;
        m_age=i;
    }

    ~CGirl(){}

    void show(){}
};

int main()
{
    CBoy boy;
    CGirl girl(boy);
    CGirl g1 = CGirl(girl);

    CGirl* g2 = new CGirl(girl,9);

    delete g2;

    return 0;
}
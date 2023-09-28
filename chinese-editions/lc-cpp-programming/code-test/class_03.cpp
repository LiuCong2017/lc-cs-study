#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

class G{
public:
    char m_name[3];
    int m_bh;
    static int m_age;

    G(){
        memset(m_name,0,sizeof(m_name));
        m_age = 0;
    }
    ~G(){}
    void showname(){
        if (this==NULL) return;
        cout<<this->m_name<<endl;
    }
    void showage(){
        cout<<m_age<<endl;
    }
};

int G::m_age;
int a;
void func(){}

int main()
{
    G g;
    cout << "g mem size:" << sizeof(g) << endl;
    cout << "g addr:" << (void*)&g << endl;
    cout << "m_bh addr:" << (void*)&g.m_bh << endl;
    cout << "m_name addr:" << (void*)&g.m_name << endl;
    cout << "m_age addr:" << (void *)&g.m_age << endl;
    cout << "global var a addr:" << (void*)&a << endl;
    printf("showname() addr: %p\n", &G::showname);
    printf("showage() addr: %p\n", &G::showage);
    printf("func() addr: %p\n", func);

    G* g1 = NULL;
    g1->showname();

    return 0;
}
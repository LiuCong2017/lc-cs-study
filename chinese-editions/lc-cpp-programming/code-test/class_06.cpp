#include <iostream>
#include <string>
using namespace std;

class G;

class B{
public:
    static void func1(const G& g);
    static void func2(const G& g);
};

class G{
    int m_bust;
    void showBust() const{
        cout<<m_bust<<endl;
    }
    friend void B::func1(const G &g);//友元成员函数
    friend void B::func2(const G &g);
public:
    string m_name;
    G(){
        m_name="Alissa";
        m_bust=87;
    }
    void showName() const{
        cout<<m_name<<endl;
    }
};

//友元成员函数
void B::func1(const G &g) {
    cout<<g.m_bust<<endl;
}
void B::func2(const G &g) {
    cout<<g.m_bust<<"-"<<g.m_name<<endl;
}

int main()
{
    G g;
    B b;
    b.func2(g);
    b.func1(g);

    return 0;
}
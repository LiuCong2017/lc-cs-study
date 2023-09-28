#include <iostream>
#include <string>
using namespace std;

class G{
    string m_name;
    static int m_age;
    int aesthetic;
public:
    G(const string& name,int age,int aesthetic) : aesthetic(aesthetic){
        m_age = age;
        m_name = name;
    }
    G(G& g){ //自定义拷贝构造函数
        m_name = g.m_name;
        m_age = G::m_age;
        aesthetic = g.aesthetic;
    }
    void show() const;
    const G& pk(const G& g) const;
    static void showAge();
};
void G::show() const{
    cout<<this->m_name<<"-"<<G::m_age<<endl;
};
const G& G::pk(const G& g) const {
    if (g.aesthetic > aesthetic) return g;
    return *this;
}
void G::showAge() {
    cout<<m_age<<endl;
}

int G::m_age = 8;

int main()
{
    G g1("Alissa",15,6),g2("Audrey",16,8),g3("Nika", 16, 9);
    const G& g_compare = g1.pk(g2).pk(g3);
    g_compare.show();

    G::showAge();

//    cout<<G::m_age<<endl;
    G gc("Cathy",32,8);
    G gcopy(gc);
    gcopy.show();

    return 0;
}
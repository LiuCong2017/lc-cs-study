#include <iostream>
#include <string>
using namespace std;

class G
{
    int m_bust;
    void showBust() const{
        cout<<m_bust<<endl;
    }
public:
    string m_name;
    G(){
        m_name = "Audrey";
        m_bust = 87;
    }
    void showName()
    {
        cout<<m_name<<endl;
    }

    friend class B; //declare friend class;
};

//友元类
class B
{
public:
    void func(const G& g)
    {
        /**
         * Therefore could access G's all member
         */
        cout<<g.m_name<<"-"<<g.m_bust<<endl;
        g.showBust();
    }
};

int main()
{
    G g;
    B b;
    b.func(g);

    return 0;
}
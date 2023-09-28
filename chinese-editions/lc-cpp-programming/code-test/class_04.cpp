#include <iostream>
using namespace std;

class G{
//    friend int main();
    friend void func(); //declare func as the friend
private:
    int m_bust;
    void showBust() const
    {
        cout<<m_bust<<endl;
    }
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

//友元全局函数
void func()
{
    G g;
    g.showName();
    g.showBust(); //thus can access private showBust();
}

int main()
{
    func();
    return 1;
}
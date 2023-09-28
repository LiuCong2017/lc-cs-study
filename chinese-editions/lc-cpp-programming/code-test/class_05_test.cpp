#include <iostream>
#include <string>
using namespace std;

class B{
    static string b_name ;
    int b_age;
    void show() const;
    friend void func();
public:
    B():b_age(32){
        b_name = "Cody";
    };
    ~B(){};
    friend class G;
};
void B::show() const
{
    cout<<B::b_name<<"-"<<this->b_age<<endl;
}

string B::b_name = "Michale";

class G{
    string g_name;
    int g_age;
public:
    G():g_name("Alissa"),g_age(28){}
    void showB(B& b){
        cout<<b.b_name<<"-"<<b.b_age<<endl;
    }
};

void func(){
    B b;
    b.show();
}

int main()
{
    B b;
    func();

    G g;
    g.showB(b);

    return 0;
}
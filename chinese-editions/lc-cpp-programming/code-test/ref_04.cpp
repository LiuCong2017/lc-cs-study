#include <iostream>
#include <string>
using namespace std;

class G{
private:
    int no;
    string str;
public:
    G() : no(0),str(){};
    G(int,const string&);
    ~G();
    int getNo() const;
    void setNo(int);
    string getStr();
    void setStr(const string&);
    static void printG(const G&);
};

G::G(int n,const string& s) {
    no = n;
    str = s;
}
G::~G(){}
int G::getNo() const{
  return no;
}
void G::setNo(int n) {
    no = n;
}
string G::getStr() {
    return str;
}
void G::setStr(const string& s){
    str = s;
}
void G::printG(const G& g){
    cout<<g.no<<"-"<<g.str<<endl;
}

void func1(G g){
    g.setNo(8);
    g.setStr("Test str");
}
void func2(G *g){
    g->setNo(8);
    g->setStr("Test str");
}
void func3(G& g){
    g.setNo(8);
    g.setStr("Test str");
}

int main()
{
    G g(9,"hello");
    func1(g);
    func2(&g);
    func3(g);
    G::printG(g);

    return 0;
}
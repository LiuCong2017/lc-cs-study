#include <iostream>
using namespace std;

class Demo{
    int x;
public:
    Demo(int v=0){
        x = v;
    }
    void set_data(int);
    int get_data() const;
};

void Demo::set_data(int a){x=a;}
int Demo::get_data() const {return x;}


int main()
{
    Demo d(20);
//    d.set_data(10);
    const Demo e;
//    e.set_data(20); //const obj can't call non-const func
    e.get_data();

    cout<<d.get_data()<<endl;
    return 0;
}
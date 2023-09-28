#include <iostream>
#include <string>
using namespace std;

//class G{
//    friend G& operator+(G& g,int score);
//    friend G& operator+(int score,G& g)
//
//};

class NotOp{
private:
    int a;
    bool b;

public:
    NotOp():a(0),b(true){}
    void in(){
        cout << "Enter the first number : ";
        cin >> a;
        cout<< "Enter true or false : ";
        cin >> b;
    }
    void operator ! (){
        a= !a;
        b= !b;
    }
    void out() {
        cout<<"Output: "<<endl<< a<<endl<<b;
    }
};


int main()
{
    NotOp obj;
    !obj;
    obj.out();

    return 0;
}
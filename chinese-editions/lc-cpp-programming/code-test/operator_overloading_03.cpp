#include <iostream>
using namespace std;

class OverLoad{
private:
    int a;
    int b;

public:
    OverLoad():a(0),b(0){}
    void in(){
        cout << "Enter the first number : ";
        cin >> a;
        cout<< "Enter the second number : ";
        cin >> b;
    }

    // Overload the prefix decrement operator
    void operator-- (){
        a = --a;
        b = --b;
    }

    void out() const{
        cout<<"The decremented elements of the object are:  "<<endl<< a<<" and " <<b;
    }

};

int main()
{
    const char* str = "Test";
    char *buf = "Test2";
    printf_s("%s\n",str);

    const char *sptr = str;
    printf_s("%s\n",sptr);

    int a1 = 100;
    int& c1 = a1;
    int&& b1 = 200;

//    static_cast();
//    dynamic_cast();
//    const_cast();
//    reinterpret_cast();

    return 0;
}
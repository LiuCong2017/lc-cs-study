#include <iostream>
using namespace std;

class Frac{
private:
    int a; //numerator
    int b; //denominator

public:
    Frac():a(0),b(0){}
    void in(){
        cout<<"Enter the numerator:";
        cin>>a;
        cout<<"Enter the denominator:";
        cin>>b;
    }

    Frac operator*(const Frac& obj) const{
        Frac temp;
        temp.a = a * obj.a;
        temp.b = b * obj.b;

        return temp;
    }

    void out() const{
        cout<<"The fraction is "<<a<<"/"<<b<<endl;
    }
};

int main(){
    Frac F1, F2, result;
    cout << "Enter the first fraction:\n";
    F1.in();

    cout << "Enter the second fraction:\n";
    F2.in();

    result = F1 * F2;
    result.out();

    int res = 3*2;
    cout<<res<<endl;

    return 0;
}
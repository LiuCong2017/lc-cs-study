#include <iostream>
using namespace std;

template <class T>
class Calculator
{
private:
    T n1,n2;

public:
    Calculator(T num1,T num2){
        n1 = num1;
        n2 = num2;
    }
    void show(){
        cout << "Addition is: " << n1 << "+" << n2 << "=" << add() << endl;
        cout << "Subtraction is: " <<n1 << "-" << n2 << "=" << sub() << endl;
        cout << "Multiply is: " << n1 << "*" << n2 << "=" << multiply() << endl;
        cout << "Division is: " << n1 << "/" << n2 << "=" << division() << endl;
    }
    T add(){return (n1+n2);}
    T sub(){return (n1-n2);}
    T multiply(){return n1*n2;}
    T division(){return n1/n2;}
};

int main()
{
    Calculator<int> Calc1(25,12);
    Calculator<float> Calc2(13.6,5.9);

    Calc1.show();
    Calc2.show();

    return 0;
}
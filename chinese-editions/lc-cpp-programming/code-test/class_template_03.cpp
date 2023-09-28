#include <iostream>
using namespace std;

template<class T1,class T2>
class Sample
{
    T1 l;
    T2 m;
public:
    Sample(T1 a,T2 b){
        l = 1;
        m = b;
    }
    void display()
    {
        cout << "The inputs are: " <<l << " and " << m << endl;
    }
};

int main()
{
    Sample<int,char> ob1(24,'A');
    Sample<int,float> ob2(22,34.9);
    ob1.display();
    ob2.display();

    return 0;
}
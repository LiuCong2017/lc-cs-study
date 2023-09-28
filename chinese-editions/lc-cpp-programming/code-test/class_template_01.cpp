#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

template<class T> class B{
public:
    T operator+(T);
};

template<class T> T B<T>::operator+(T x){
    return x;
}

int main(){
    B<char> ob1;
    B<int> ob2;
    cout<<ob1+'p'<<endl;
    cout<<ob2+10;

    return 0;
}
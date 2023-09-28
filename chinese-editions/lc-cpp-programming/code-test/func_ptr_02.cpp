#include <iostream>
using namespace std;

int operate(int a,int b,int (*opt)(int,int)){
    return opt(a,b);
}

int multiply(int x,int y){
    return x*y;
}

int main(){
    int result = operate(3,4,multiply);
    cout<<result<<endl;
    return 0;
}
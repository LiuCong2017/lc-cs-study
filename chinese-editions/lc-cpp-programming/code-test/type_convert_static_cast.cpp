#include <iostream>
#include <cstdlib>
using namespace std;

class Complex{
public:
    Complex(double real=0.0,double imag=0.0):m_real(real),m_imag(imag){}
public:
    operator double() const {return m_real;} //类型转换函数
private:
    double m_real;
    double m_imag;
};

int main(){
    int m = 100;
    Complex c(12.5,23.8);
    long n = static_cast<long>(n);
    char ch = static_cast<char>(m);
    int* p1 = static_cast<int*>(malloc(10*sizeof(int)));

    void* p2 = static_cast<void*>(p1);
    double real = static_cast<double>(c);

//    float *p3 =  static_cast<float*>(p1);
//    float *p3 = static_cast<float*>(OX2DF9);

}


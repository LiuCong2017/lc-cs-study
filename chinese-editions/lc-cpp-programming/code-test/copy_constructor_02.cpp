#include <iostream>
#include <cstdlib>
using namespace std;

class Array{
private:
    int len;
    int *p;
public:
    Array(int _len);
    Array(const Array& arr);
    ~Array();
public:
    int operator[](int i) const{return p[i];}
    int& operator[](int i){return p[i];}
    int length() const{return len;}
};

Array::Array(int _len):len(_len) {
    p = (int*) calloc(len,sizeof(int));
}

Array::Array(const Array& arr) {
    this->len = arr.len;
    this->p = (int*) calloc(this->len,sizeof(int));
    memcpy(this->p,arr.p,len*sizeof(int));
}

Array::~Array() { free(p);}

void printArray(const Array& arr){
    int len = arr.length();
    for (int i = 0; i < len; ++i) {
        if (i==len-1){
            cout<<arr[i]<<endl;
        } else{
            cout<<arr[i]<<", ";
        }
    }
}

int main(){
    Array arr1(10);
    for (int i = 0; i < 10; ++i) {
        arr1[i] = i;
    }

    Array arr2 = arr1;
    arr2[5] = 100;
    arr2[3] = 29;

    printArray(arr1);
    printArray(arr2);

    const int size = 20;
    int *p = (int*) malloc(size*sizeof(int));
    int *pp = (int*) calloc(size,sizeof(int));
    int *ppp = (int*) realloc(p,size*sizeof(int));

    return 0;
}
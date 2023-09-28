#include <iostream>
using namespace std;

void func(int arr[],int len)
{
    for (int i = 0; i < len; ++i) {
        cout<<arr[i]<<endl;
        cout<<*(arr+i)<<endl;
    }

}


int main()
{
    char a[20];
    int* p = (int*)a;
    for (int i = 0; i < 6; ++i) {
        p[i] = i+300;
    }

    for (int i = 0; i < 6; ++i) {
        cout<<*(p+i)<<endl;
    }

    int b[] = {2,8,4,6,7,1,9};
    func(b,sizeof(b)/sizeof(int));

    int* arr = new int[8];
    for (int i = 0; i < 8; ++i) {
        arr[i] = 100+i;
        cout<<*(arr+i)<<endl;
        cout<<&arr[i]<<endl;
    }
    delete [] arr;

    return 0;
}
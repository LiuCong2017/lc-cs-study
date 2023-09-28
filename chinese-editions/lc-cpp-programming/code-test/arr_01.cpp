#include <iostream>
#include <string>
using namespace std;

int main()
{
//    cout<<sizeof("a+b=12\n\t")<<endl;
//
//    int a=3,b=4,c=5;
//    bool res = (a+b)>c;
//    bool res2 = res&&b;
//    bool res3 = res2==c;
//    cout<<res3<<endl;

    int arr[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = i;
    }

//    cout<<arr[1]<<endl;
//    cout<<sizeof(arr)<<endl;

    int arrInit1[3] = {3,5,9};
    int arrInit2[] = {34,56,12};
    int arrInit3[3] = {0};
    int arrInit4[4] = {};

    int bh[] = {3,5,1,5,12,89,10};
    string name[3];

    int bh1[sizeof(bh)/sizeof(int)];

    memcpy(bh1,bh,sizeof(bh));
    for(int i=0;i<sizeof(bh1)/sizeof(int);i++)
    {
        cout<<bh1[i]<<endl;
    }


    return 0;
}
#include <iostream>
#include <string>
using namespace std;

void func(int* no,string* str)
{
    cout<<*no<<"-"<<*str<<endl;
    *no = 8;
    *str = "Cody";
}

void func1(int a,int b,int c,int* max,int* min){
    *max = a>b?a:b;
    *min = a<b?a:b;
    *max = *max>c?*max:c;
    *min = *min<c?*min:c;
}

int main()
{
    int bh = 3;
    string msg = "Hello";
    func(&bh,&msg);
    cout<<bh<<"-"<<msg<<endl;

    int a=180,b=170,c=175,m,n;
    func1(a,b,c,&m,&n);
    cout<<"m="<<m<<",n="<<n<<endl;

    return 0;
}
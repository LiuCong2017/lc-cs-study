#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int a = 0;

int main()
{
    int b;
    char s[] = "abc";
    char *p1;
    char *p2 = "123435";
    static int c = 0;

    p1 = (char *)malloc(10);
    strcpy(p1, "12345");

    cout<<p1<<endl;
    return 0;
}
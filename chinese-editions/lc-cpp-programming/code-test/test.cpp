#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    char str1[] = "Megadeth";
    char str2[] = "Metallica";
    int result = strcmp(str1,str2);
    result = strcmp(str2,str1);
    result = strcmp(str1, str1);
    cout<<result<<endl;

}
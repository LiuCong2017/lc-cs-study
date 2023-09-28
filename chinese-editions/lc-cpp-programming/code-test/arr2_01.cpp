#include <iostream>
#include <string>
using namespace std;

int main()
{
    int arr[2][3] = {{1,2,3},{3,4,5}};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
//    arr[1][2];

//    char array[20][10] = {};
//    for (int i = 0; i < 20; ++i) {
//        for (int j = 0; j < 10; ++j) {
//            array[i][j] = (char)i+(char)j;
//        }
//    }
//
//    for (int i = 0; i < 20; ++i) {
//        for (int j = 0; j < 10; ++j) {
//            cout<<array[i][j]<<"\t";
//        }
//        cout<<endl;
//    }

    return 0;
}
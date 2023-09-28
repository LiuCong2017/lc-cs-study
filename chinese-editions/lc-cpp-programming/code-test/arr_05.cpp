#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

/** 二分查找 */
int search(int arr[],int len,int key)
{
    int low=0, high = len-1, mid;

    while(low<=high)
    {
        mid = (low+high) / 2;
        if (arr[mid]==key) return mid;
        else if (arr[mid]>key) high = mid - 1;
        else low = mid + 1;
    }

    return -1;
}

int compare_asc(const void* p1,const void* p2)
{
    return *((int*)p1) - *((int*)p2);
}
int compare_desc(const void* p1,const void* p2)
{
    return *((int*)p2) - *((int*)p1);
}

int main()
{
    int a[8] = { 4,2,7,5,8,6,1,3 };


    qsort(a,8,sizeof(int),compare_desc);
    for (int i = 0; i < 8; ++i) {
        cout<<a[i]<<"\t";
    }

    cout<<"\n"<<endl;

    //排序
    qsort(a,sizeof(a)/sizeof(int),sizeof(int),compare_asc);

    for (int i = 0; i < 8; ++i) {
        cout<<a[i]<<"\t";
    }
    cout<<"\n"<<endl;

    if (search(a,8,7)>=0) cout<<"find successful"<<endl;
    else cout<<"find failed"<<endl;

    char str[20] = "HelloTest";
    cout<<strlen(str)<<endl;

    char strcp[30];
    strcpy(strcp,str);
    cout<<"strcp: "<<strcp<<endl;

    return 0;
}

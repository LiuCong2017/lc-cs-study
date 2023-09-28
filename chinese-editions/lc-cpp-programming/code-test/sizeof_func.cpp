#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

char* getStr1()
{
    //首先在栈上分配一个内存空间，命名为p1，然后在全局区存放字符串abc，
    //将全局区的abc字符串首地址赋给p1，也就是说p1指向全局区变量的首地址;
    char* p1 = "abc";
    //返回指针的首地址
    return p1;
//该函数在main函数调用的时候分配内存空间，调用结束后讲内存空间自动释放。
}
char* getStr2()
{
    //p2同样指向之前getStr1函数中全局区存放的字符串常量的首地址。
    char* p2 = "abc";
    return p2;
}

char* getNUm(int num)
{
    char* p1 = NULL;
    p1 = (char*)malloc(sizeof(char) * num);
    if (p1 == NULL)
    {
        return NULL;
    }
    return p1;
}

int main()
{
//    cout << sizeof(char) << endl;
//    cout << sizeof(int) << endl;
//    cout << sizeof(unsigned int) << endl;
//    cout << sizeof(long) << endl;
//    cout << sizeof(unsigned long) << endl;
//    cout << sizeof(float) << endl;
//    cout << sizeof(double) << endl;
//    cout << sizeof(void *) << endl;

    int* ip = new int;
    char s[] = "abcd";
    char* p = "abcd";

//    cout<<ip<<endl;
//    cout<<*ip<<endl;
//    cout<<&ip<<endl;

//    cout << s <<endl;//果然这句话输出的是abcd！
//    cout << *s <<endl;//但这句输出的是a！
//    cout << &s <<endl;
//    cout << (s+1) <<endl;
//    cout << *(s+1) <<endl;
//    cout << &s[1] <<endl;

//    cout << p <<endl;
//    cout << *p <<endl;
//    cout << &p <<endl;
//    cout << (p+1) <<endl;
//    cout << *(p+1) <<endl;
//    cout << &p[1] <<endl;

//    char a[] = "hello";
//    int b[] = {1, 2, 3, 4, 5};
//
//    printf("a: %d\n", sizeof(a));
//    printf("b memory size: %d bytes\n", sizeof(b));
//    printf("b elements: %d\n", sizeof(b)/sizeof(int));

//    char* pt1 = NULL;
//    pt1 = getStr1();
//    char* pt2 = getStr2();
//    cout<<pt1<<"-"<<pt2<<endl;

//    char* temp = NULL;
//    temp = getNUm(10);
//    if (temp==NULL){
//        return 0;
//    }
//    strcpy(temp,"abc");
//    cout<<temp;


    return 0;
}
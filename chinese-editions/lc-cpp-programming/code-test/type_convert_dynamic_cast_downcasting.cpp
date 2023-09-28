#include <iostream>
using namespace std;

class A{
public:
    virtual void func() const {cout<<"Class A"<<endl;}
private:
    int m_a;
};

class B:public A{
public:
    virtual void func() const {cout<<"Class B"<<endl;}
private:
    int m_b;
};

class C:public B{
public:
    virtual void func() const {cout<<"Class C"<<endl;}

private:
    int m_c;
};

class D:public C{
public:
    virtual void func() const {cout<<"Class D"<<endl;}
private:
    int m_d;
};

int main(){
    A *pa = new A();
    B *pb;
    C *pc;

    //dynamic_cast 只允许向上转型，因为它只会向上遍历继承链
    pb = dynamic_cast<B*>(pa);
    if(pb == NULL){
        cout<<"Downcasting failed: A* to B*"<<endl;
    }else{
        cout<<"Downcasting successfully: A* to B*"<<endl;
        pb -> func();
    }

    pc = dynamic_cast<C*>(pa);
    if(pc == NULL){
        cout<<"Downcasting failed: A* to C*"<<endl;
    }else{
        cout<<"Downcasting successfully: A* to C*"<<endl;
        pc -> func();
    }

    cout<<"-------------------------"<<endl;

    // 当 pa 指向 D 类型的对象时，向下转型成功，pa 可以转换为B*或C*类型
    pa = new D();
    pb = dynamic_cast<B*>(pa);
    if(pb == NULL){
        cout<<"Downcasting failed: A* to B*"<<endl;
    }else{
        cout<<"Downcasting successfully: A* to B*"<<endl;
        pb -> func();
    }

    pc = dynamic_cast<C*>(pa);
    if(pc == NULL){
        cout<<"Downcasting failed: A* to C*"<<endl;
    }else{
        cout<<"Downcasting successfully: A* to C*"<<endl;
        pc -> func();
    }

    return 0;
}
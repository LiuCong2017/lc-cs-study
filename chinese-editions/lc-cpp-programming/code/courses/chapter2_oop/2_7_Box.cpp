#include<iostream>
using namespace std;

class Box
{
    public:
        double length;
        void setWidth(double wid);
        double getWidth();
    private:
        double width;

};

double Box::getWidth()
{
    return width;
}

void Box::setWidth(double wid)
{
    width = wid;
}

int main()
{
    Box box;    
    box.length = 10.0;
    cout<<box.length<<endl;
    box.setWidth(10.0);
    cout<<box.getWidth()<<endl;

    return 0;
}

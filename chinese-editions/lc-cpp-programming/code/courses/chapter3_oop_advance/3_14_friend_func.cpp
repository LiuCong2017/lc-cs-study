#include <iostream>
#include <cmath>
using namespace std;

class Pixel;

class Test
{
public:
  void printX(Pixel p);
};

class Pixel
{
private:
  int x,y;
public:
  Pixel(int x0, int y0)
  {
    x = x0;
    y = y0;
  }
  void printXY()
  {
    cout<<"pixel:("<<x<<","<<y<<")"<<endl;
  }
  
  friend double getDist(Pixel p1, Pixel p2);
  friend void Test::printX(Pixel p);
};

void Test::printX(Pixel p)
{
  cout<<"x="<<p.x<<endl;
  cout<<"y="<<p.y<<endl;  
  return;
}

double getDist(Pixel p1,Pixel p2)
{
  double xd = double(p1.x - p2.x);
  double yd = double(p1.y - p2.y);
  return sqrt(xd*xd + yd*yd);
}

int main()
{
  Pixel p1(0,0),p2(10,10);
  p1.printXY();
  p2.printXY();
  cout<<"(p1,p2) distance: "<<getDist(p1,p2)<<endl;

  Test t;
  cout<<"from friends func output ---"<<endl;
  t.printX(p1);
  t.printX(p2);  

  return 0;
}


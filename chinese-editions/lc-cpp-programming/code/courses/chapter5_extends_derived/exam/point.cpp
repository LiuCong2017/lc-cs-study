#include <iostream>
#include <cmath>
using namespace std;

class Point{
  double x,y;
public:
  Point();
  Point(double,double);
  double getX();
  void setX(double);
  double getY();
  void setY(double);
  double distance(Point p);
  ~Point(){};
};

Point::Point():x(0),y(0){}

Point::Point(double x,double y)
{
  this->x = x;
  this->y = y;
}

double Point::getX()
{
  return this->x;
}

void Point::setX(double x)
{
  this->x = x;
}

double Point::getY()
{
  return this->y;
}

void Point::setY(double y)
{
  this->y = y;
}

double Point::distance(Point p)
{
  return sqrt((this->x - p.x)*(this->x - p.x) + (this->y - p.y)*(this->y - p.y));
}

int main()
{
  Point p1,p2;
  double x1,y1,x2,y2;
  cout<<"input p1(x1,y1), p2(x2,y2):"<<endl;
  cin>>x1>>y1>>x2>>y2;
  p1 = Point(x1,y1);
  p2 = Point(x2,y2);
  cout<<"distance:"<<p1.distance(p2)<<endl;

  return 0;
}

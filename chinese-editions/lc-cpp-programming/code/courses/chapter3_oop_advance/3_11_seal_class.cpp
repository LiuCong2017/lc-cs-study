#include <iostream>
using namespace std;

class CTyre
{
private:
  int radius;
  int width;

public:
  CTyre():radius(16),width(185){}
  CTyre(int r,int w):radius(r),width(w){}
  int getRadius()
  {
    return radius;
  }
  int getWidth()
  {
    return width;
  }
};

class CCar
{
private:
  int price;
  CTyre tyre;

public:
  CCar();
  CCar(int p, int tr, int tw);
  
  int getPrice()
  {
    return price;
  }
  CTyre getCTyre()
  {
    return tyre;
  }
};

CCar::CCar()
{
  price = 202307;
  CTyre();
};

CCar::CCar(int p,int tr,int tw):price(p),tyre(tr,tw){};

int main()
{
  CCar car(202209,17,225);
  cout<<"price="<<car.getPrice()<<endl;
  cout<<"CTyre.radius="<<car.getCTyre().getRadius()<<endl;
  cout<<"CTyre.width="<<car.getCTyre().getWidth()<<endl;
  
  CCar car1;
  cout<<"price="<<car1.getPrice()<<endl;
  cout<<"CTyre.radius="<<car1.getCTyre().getRadius()<<endl;
  cout<<"CTyre.width="<<car1.getCTyre().getWidth()<<endl;
  
  return 0;
}

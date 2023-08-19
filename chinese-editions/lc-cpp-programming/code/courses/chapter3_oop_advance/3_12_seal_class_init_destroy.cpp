#include <iostream>
using namespace std;

class CTyre
{
private:
  int radius;
  int width;

public:
  CTyre():radius(16),width(185)
  {
    cout<<radius<<" CTyre() constructor"<<endl;
  }
  CTyre(int r,int w):radius(r),width(w)
  { 
    cout<<radius<<" CTyre() constructor"<<endl;
  }
  ~CTyre()
  {
    cout<<radius<<" CTyre() deConstructor"<<endl;
  }
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
  CCar(int p,int tr,int tw);
  ~CCar();
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
  price=50010;
  CTyre();
  cout<<price<<" CCar constructor"<<endl;
}

CCar::CCar(int p,int tr,int tw):price(p),tyre(tr,tw)
{
  cout<<price<<" CCar constructor"<<endl;
}

CCar::~CCar()
{
  cout<<price<<" CCar deConstructor"<<endl;
}

int main()
{
  CCar car(202307,17,258);
  cout<<"price="<<car.getPrice()<<endl;
  cout<<"radius="<<car.getCTyre().getRadius()<<endl;
  cout<<"width="<<car.getCTyre().getWidth()<<endl;

  cout<<"----------"<<endl;  

  CCar car1;
  cout<<"price="<<car1.getPrice()<<endl;
  cout<<"radius="<<car1.getCTyre().getRadius()<<endl;
  cout<<"width="<<car1.getCTyre().getWidth()<<endl;
   
 
  return 0;
}










#include <iostream>
#include <cmath>
using namespace std;

class CShape
{
protected:
  double acreage;
public:
  CShape(){};
  virtual ~CShape(){};
  virtual double CalAcr()
  {
    return 0;
  };
  virtual void setAcreage(double acre){};
  virtual void PrintInfo(){};
};

class CRectangle:public CShape
{
  double width,high;
public:
  CRectangle(double w,double h)
  {
    width = w;
    high = h;
  };
  CRectangle()
  {
    width = 0;
    high = 0;
  };
  ~CRectangle(){};
  virtual double CalAcr();
  virtual void PrintInfo();
  virtual void setAcreage(double);
};

class CCircle:public CShape
{
  double radius;
public:
  CCircle(double r)
  {
    radius = r;
  };
  CCircle()
  {
    radius = 0;
  };
  ~CCircle(){};
  virtual double CalAcr();
  virtual void PrintInfo();
  virtual void setAcreage(double);
};

class CTriangle:public CShape
{
  double a,b,c;
public:
  CTriangle(double a,double b,double c)
  {
    this->a = a;
    this->b = b;
    this->c = c;
  }
  CTriangle()
  {
    a=0;
    b=0;
    c=0;
  }
  ~CTriangle(){};
  virtual double CalAcr();
  virtual void PrintInfo();
  virtual void setAcreage(double);
};

double CRectangle::CalAcr()
{
  return width*high;
}

void CRectangle::PrintInfo()
{
  cout<<"CRectangle: width="<<this->width<<",high="<<this->high<<", area="<<this->acreage<<endl;
}

void CRectangle::setAcreage(double acre)
{
  acreage = acre;
}

double CCircle::CalAcr()
{
  return 3.14*radius*radius;
}

void CCircle::PrintInfo()
{
  cout<<"CCircle: radius="<<this->radius<<", area="<<this->acreage<<endl;
}

void CCircle::setAcreage(double acre)
{
  acreage=acre;
}

double CTriangle::CalAcr()
{
  double p = (a+b+c)/2.0;
  return sqrt(p*(p-a)*(p-b)*(p-c));
}

void CTriangle::PrintInfo()
{
  cout<<"CTriangle: three edges:"<<this->a<<this->b<<this->c<<", area="<<this->acreage<<endl;
}

void CTriangle::setAcreage(double acre)
{
  acreage = acre;
}

CShape *pShapes[100];

int main()
{
  int i,n;
  double temp1,temp2,temp3;
  CRectangle *pr;
  CCircle *pc;
  CTriangle *pt;
  cin>>n;
  for(i=0;i<n;++i)
  {
    char c;
    cin>>c;
    switch(c)
    {
      case 'R':case 'r':
        cin>>temp1>>temp2;
        pr = new CRectangle(temp1,temp2);
        pr->setAcreage(pr->CalAcr());
        pShapes[i] = pr;
        break;
      case 'C':case 'c':
        cin>>temp1;
        pc = new CCircle(temp1);
        pc->setAcreage(pc->CalAcr());
        pShapes[i] = pc;
        break;
      case 'T':case 't':
        cin>>temp1>>temp2>>temp3;
        pt = new CTriangle(temp1,temp2,temp3);
        pt->setAcreage(pt->CalAcr());
        pShapes[i] = pt;
        break;
    }
  }

  if(n==1) cout<<"total "<<n<<" type shapes, they are: "<<endl;
  else cout<<"total "<<n<<" type shapes, they are: "<<endl;
  for(i=0;i<n;++i)
  {
    pShapes[i]->PrintInfo();
    delete pShapes[i];
  }

  return 0;
}






























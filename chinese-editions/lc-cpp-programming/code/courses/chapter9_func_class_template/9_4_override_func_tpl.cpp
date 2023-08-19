#include <iostream>
using namespace std;

class myDate
{
public:
  myDate();
  myDate(int,int,int);
  friend ostream& operator<<(ostream& os, const myDate& c);
private:
  int year,month,day;
};

myDate::myDate()
{
  year = 1970;
  month = 1;
  day = 1;
}

myDate::myDate(int y,int m,int d)
{
  year = y;
  month = m;
  day = d;
}

ostream& operator<<(ostream& os, const myDate& c)
{
  os<<c.year<<"/"<<c.month<<"/"<<c.day;
  return os;
}

template <class T1, class T2>
void print(T1 arg1, T2 arg2)
{
  cout<<arg1<<", "<<arg2<<endl;
}

template <class T>
void print(T arg1, T arg2)
{
  cout<<arg1<<", "<<arg2<<endl;
}

int main()
{
  int n=1,m=2;
  print(n,m);
  myDate d1, d2(2000,1,1);
  print(d1,d2);

  print(n,d1);
  
  return 0;
}

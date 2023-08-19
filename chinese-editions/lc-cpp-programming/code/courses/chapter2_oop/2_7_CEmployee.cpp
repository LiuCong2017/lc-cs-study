#include<iostream>
#include<string>
using namespace std;

class CEmployee
{
  private:
    string szName;
    int salary;
  public:
    void setName(string);
    string getName();
    void setSalary(int);
    int getSalary();
    int avgSalary(CEmployee);
};

void CEmployee::setName(string name)
{
  szName = name;
}

string CEmployee::getName()
{
  return szName;
}

void CEmployee::setSalary(int money)
{
  salary = money;
}

int CEmployee::getSalary()
{
  return salary;
}

int CEmployee::avgSalary(CEmployee ce)
{
  return (salary + ce.getSalary())/2;
}

int main()
{
  CEmployee eX, eY;
  eX.setName("Kavin");
  eX.setSalary(5000);
  cout<<eX.getName()<<"-"<<eX.getSalary()<<endl;

  eY.setName("Cody");
  eY.setSalary(6000);
  cout<<eY.getName()<<"-"<<eY.getSalary()<<endl;

  cout<<"avarage="<<eX.avgSalary(eY)<<endl;

  return 0;
}

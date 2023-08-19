#include <iostream>
using namespace std;

class Sample
{
public:
  Sample();
  void getValue() const;
  void getValue();
  void priValue();
  void priVcon() const;  
};

Sample::Sample(){}

void Sample::getValue() const
{
  cout<<"const member func"<<endl; 
}

void Sample::getValue()
{
  cout<<"normal member func"<<endl;
}

void Sample::priValue()
{
  cout<<"normal member func"<<endl;
}

void Sample::priVcon() const
{
  cout<<"const member func"<<endl;
}

int main()
{
  const Sample cono;
  Sample o;
  
  cout<<"conno:";
  cono.getValue();

  cout<<"o:";
  o.getValue();
  
  cout<<"o:";
  o.priValue();

  cout<<"o:";
  o.priVcon();

  return 0;
}

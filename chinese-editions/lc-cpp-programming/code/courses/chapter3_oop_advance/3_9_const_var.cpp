#include <iostream>
using namespace std;

class constClass
{
  const int conMbr;
  int Mbr;
public:
  constClass():conMbr(0),Mbr(100){}
  constClass(int i):conMbr(i)
  {
    Mbr = 200;
  }
  void printConst()
  {
    cout<<"conMbr="<<conMbr<<endl;
    cout<<"Mbr="<<Mbr<<endl;
  }
  int getConst()
  {
    cout<<"invoke none const func"<<endl;
    return conMbr;
  }
  int getConst() const
  {
    cout<<"invoke const func"<<endl;
    return conMbr;
  }
  
  int getValue()
  {
    return Mbr;
  }

  void processConst()
  {
    cout<<"inside processConst(), none const:"<<endl;
    int x = 2*conMbr + 1;
//    conMbr++;
    cout<<x<<endl;
    Mbr++;
    cout<<"Mbr="<<Mbr<<endl;
  }
  void processConst() const
  {
    cout<<"inside processConst(), const:"<<endl;
    int x = conMbr + 1;
    cout<<x<<endl;
//    Mbr++;
    cout<<"Mbr="<<Mbr<<endl;  
  }

};

int main()
{
  constClass ob1(123), ob2;
  ob1.printConst();
  cout<<"ob2.getConst()="<<ob2.getConst()<<endl;
  ob2.processConst();

  const constClass ob3(20);
  cout<<"ob3.getConst()="<<ob3.getConst()<<endl;
  ob3.processConst();
  
  return 0;
}

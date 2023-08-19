#include <iostream>
using namespace std;

template <typename T>
class Test
{
public:
  Test(T num)
  {
    k += num;
  }
  Test()
  {
    k += 1;
  }
  static void incrementK()
  {
    k += 1;
  }
  static T k;
};

template <typename T>
T Test<T>::k=0;

int main()
{
  Test<int> a;
  Test<double> b(4);
  cout<<"int k:"<<a.k<<endl;
  cout<<"double k:"<<b.k<<endl;

  Test<int> v;
  Test<double> m;
  cout<<"int k:"<<Test<int>::k<<endl;
  cout<<"double k:"<<Test<double>::k<<endl;

  Test<int>::incrementK();
  cout<<"incrementK: "<<Test<int>::k<<endl;  
  Test<double>::incrementK();
  cout<<"incrementK: "<<Test<double>::k<<endl; 

  return 0;
}

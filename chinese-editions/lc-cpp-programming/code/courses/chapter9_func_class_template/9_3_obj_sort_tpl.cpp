#include <iostream>
#include <string>
using namespace std;

template <typename T>
int myCompare(const T& left, const T& right)
{
  if(left<right)
  {
    return -1;
  }else if(right<left){
    return 1;
  }else{
    return 0;
  }
}

template <class T>
void Swap(T& x, T& y)
{
  T tmp = x;
  x = y;
  y = tmp;
}

int main()
{
  string arr[10] = {"b","c","a","t","m","q","z","w","r","u"};
  int j;
  string temp;
  for(int i=1;i<10;i++)
  {
    j=i;
    while(j>0 && myCompare<string>(arr[j-1],arr[j]) > 0)
    {
      swap(arr[j], arr[j-1]);
      j--;
    }
  }
  for(int i=0;i<10;i++)
    cout<<arr[i]<<",";

  return 0;
}

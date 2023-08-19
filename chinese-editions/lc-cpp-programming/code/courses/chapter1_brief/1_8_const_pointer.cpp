#include<iostream>
using namespace std;
int main()
{
  int a1 = 3;
  const int a2 = a1;
  
  int* a3 = &a1;
  const int* a4 = &a1;
  int* const a5 = &a1;
  int const* const a6 = &a1;
  const int* const a7 = &a1;

  return 0;
}

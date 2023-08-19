#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  double x = 1234567.89, y = 1.23456789;
  cout<<"无格式控制: \t 1)x=("<<x<<"),y=("<<y<<")\n";
  cout<<"保留5位有效数字: \t 2)x=("<<setprecision(5)<<x<<"),y=("<<y<<")\n";
  cout<<"保留小数点后5位: \t 3)x=("<<fixed<<setprecision(5)<<x<<"),y=("<<y<<")\n";
  cout<<"科学计数法且保留小数点后5位: 4)x=("<<scientific<<setprecision(5)<<x<<"),y=("<<y<<")\n";
  cout<<"5)"<<showpos<<fixed<<setw(12)<<setfill('*')<<y<<endl;
  cout<<"6)"<<noshowpos<<setw(12)<<left<<y<<endl;
  cout<<"7)"<<setw(12)<<right<<y<<endl;
  cout<<"8)"<<setw(12)<<internal<<-y<<endl;

  return 0;
}

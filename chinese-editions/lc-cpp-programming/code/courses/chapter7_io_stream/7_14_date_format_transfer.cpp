#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string Months[13] = {"","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

int main()
{
  char ch;
  int year,month,day;
  while((ch=cin.peek())!=EOF){
    if(ch>'A'&&ch<'Z'){
      string sMonth;
      cin>>sMonth>>day>>year;
      for(month=0;month<12 && sMonth!=Months[month];++month);
    }else{
      cin>>year;
      cin.ignore()>>month;
      cin.ignore()>>day;
    }
    cin.ignore();
    cout<<setfill('0')<<setw(2)<<month;
    cout<<"-"<<setw(2)<<day<<"-"<<setw(4)<<"-"<<year<<endl;
  }

  return 0;
}

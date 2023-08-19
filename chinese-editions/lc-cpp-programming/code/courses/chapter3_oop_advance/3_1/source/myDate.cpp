#include "../include/myDate.h"
#include<iostream>

myDate::myDate()
{
    year=1970,month=1,day=1;
}

myDate::myDate(int y,int m,int d)
{
    year = y;
    month = m;
    day = d;
}

void myDate::setDate(int y,int m, int d)
{
    year=y;month=m;day=d;
    return;
}

void myDate::setDate(myDate oneD)
{
    year=oneD.year;
    month=oneD.month;
    day=oneD.day;
    return;
}

myDate myDate::getDate()
{
    return *this;
}

void myDate::setYear(int y)
{
    year=y;
    return;
}

int myDate::getMonth()
{
  return month;
}

void myDate::printDate() const
{
    std::cout<<year<<"-"<<month<<"-"<<day<<"\t";
    return;
}


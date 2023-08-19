#ifndef UNTITLED_MYDATE_H
#define UNTITLED_MYDATE_H


class myDate
{
public:
    myDate();
    myDate(int,int,int);
    void setDate(int,int,int);
    void setDate(myDate);
    myDate getDate();
    void setYear(int);
    int getMonth();
    void printDate() const;

private:
    int year,month,day;
};


#endif //UNTITLED_MYDATE_H

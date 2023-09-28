#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

class book {
private:
    char *author,*title,*publisher;
    float *price;
    int *stock;
public:
    book(){
        author = new char[20];
        title=new char[20];
        publisher=new char[20];
        price = new float;
        stock = new int;
    }
    void fetchData();
    void editData();
    void showData();
    int search(char[],char[]);
    void buyBook();
};

void book::fetchData() {
    cin.ignore();
    cout<<"\nEnter Author Name: ";      cin.getline(author,20);
    cout<<"Enter Title Name: ";       cin.getline(title,20);
    cout<<"Enter Publisher Name: ";   cin.getline(publisher,20);
    cout<<"Enter Price: ";            cin>>*price;
    cout<<"Enter Stock Position: ";   cin>>*stock;

}

void book::editData() {
    cout<<"\nEnter Author Name: ";      cin.getline(author,20);
    cout<<"Enter Title Name: ";       cin.getline(title,20);
    cout<<"Enter Publisher Name: ";   cin.getline(publisher,20);
    cout<<"Enter Price: ";            cin>>*price;
    cout<<"Enter Stock Position: ";   cin>>*stock;
}

void book::showData()	{
    cout<<"\nAuthor Name: "<<author;
    cout<<"\nTitle Name: "<<title;
    cout<<"\nPublisher Name: "<<publisher;
    cout<<"\nPrice: "<<*price;
    cout<<"\nStock Position: "<<*stock;

}

int book::search(char tBuy[20], char aBuy[20]) {
    if (strcmp(tBuy,title)==0 && strcmp(aBuy,author)==0) return 1;
    else return 0;
}

void book::buyBook() {
    int count;
    cout<<"\nEnter Number Of Books to buy: ";
    cin>>count;
    if (count <= *stock){
        *stock=*stock-count;
        cout<<"\nBooks Bought Sucessfully";
        cout<<"\nAmount: Rs. "<<(*price)*count;
    } else{
        cout<<"\nRequired Copies not in Stock";
    }
}

int main(){
    book *B[20];
    int i=0,r,j,choice;
    char titleBuy[20],authorBuy[20];
    while (1){
        cout<<"\n\n\t\tMENU"
            <<"\n1. Entry of New Book"
            <<"\n2. Buy Book"
            <<"\n3. Search For Book"
            <<"\n4. Edit Details Of Book"
            <<"\n5. Exit"
            <<"\n\nEnter your Choice: ";
        cin>>choice;

        switch (choice) {
            case 1: B[i] = new book;
                    B[i]->fetchData();
                    i++;
                break;

            case 2: cin.ignore();
                    cout<<"\nEnter Title Of Book: "; cin.getline(titleBuy,20);
                    cout<<"Enter Author Of Book: ";  cin.getline(authorBuy,20);
                    for (j = 0; j < i; ++j) {
                        if(B[j]->search(titleBuy,authorBuy))	{
                            B[j]->buyBook();
                            break;
                        }
                    }
                    if(j==1)
                    cout<<"\nThis Book is Not in Stock";
                break;

            case 3: cin.ignore();
                    cout<<"\nEnter Title Of Book: "; cin.getline(titleBuy,20);
                    cout<<"Enter Author Of Book: ";  cin.getline(authorBuy,20);
                    for(j=0;j<i;j++)	{
                        if(B[j]->search(titleBuy,authorBuy))	{
                            cout<<"\nBook Found Successfully";
                            B[j]->showData();
                            break;
                        }
                    }
                    if(j==i) cout<<"\nThis Book is Not in Stock";
                break;

            case 4: cin.ignore();
                    cout<<"\nEnter Title Of Book: "; cin.getline(titleBuy,20);
                    cout<<"Enter Author Of Book: ";  cin.getline(authorBuy,20);
                    for(j=0;j<i;j++)	{
                        if(B[j]->search(titleBuy,authorBuy))	{
                            cout<<"\nBook Found Successfully";
                            B[j]->editData();
                            break;
                        }
                    }
                    if(j==i)
                        cout<<"\nThis Book is Not in Stock";
                    break;

            case 5: exit(0);
            default: cout<<"\nInvalid Choice Entered";
        }

    }

    return 0;
}
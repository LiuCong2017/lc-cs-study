#include <iostream>
#include <string>
using namespace std;

class Pet{
protected:
  string type;
  int number;
public:
  Pet(){};
  Pet(string,int);
  string getType();
  void setType(string &);
  int getNumber();
  void setNumber(int);
  void print();
  ~Pet(){};
};

Pet::Pet(string type,int number){
  this->type = type;
  this->number = number;
}

string Pet::getType(){
  return this->type;
}
void Pet::setType(string &type){
  this->type=type;
}
int Pet::getNumber(){
  return this->number;
}
void Pet::setNumber(int number){
  this->number = number;
}
void Pet::print(){
  cout<<"Pet_:"<<"type:"<<type<<"-"<<"number:"<<number<<endl;
}

class Cat:public Pet{
private:
  string name;
  string food;
public:
  Cat(){};
  Cat(string &,int,string &,string &);
  void setName(string &);
  string getName();
  void setFood(string &);
  string getFood();
  void print();
  ~Cat(){};
};
Cat::Cat(string &type,int number,string &name,string &food):Pet(type,number){
  this->name = name;
  this->food = food;
}
void Cat::setName(string &name){
  this->name = name;
}
string Cat::getName(){
  return this->name;
}
void Cat::setFood(string &food){
  this->food = food;
}
string Cat::getFood(){
  return this->food;
}
void Cat::print(){
  Pet::print();
  cout<<"Cat_:"<<"name:"<<this->getName()<<"-"<<"food"<<this->food<<endl;
}

class Dog:public Pet{
private:
  string name;
  int size;
public:
  Dog(){};
  Dog(string &,int,string &,int);
  void setName(string &);
  string getName();
  void setSize(int);
  int getSize();
  string getStrSizeByIntParam(int);
  void print();
  ~Dog(){};
};

Dog::Dog(string &type,int number,string &name,int size):Pet(type,number){
  this->name = name;
  this->size = size;
}
void Dog::setName(string &name){
  this->name=name;
}
string Dog::getName(){
  return this->name;
}
void Dog::setSize(int size){
  this->size = size;
}
int Dog::getSize(){
  return this->size;
}
string Dog::getStrSizeByIntParam(int size){
  switch(size){
    case 1:
      return "small";
    case 2:
      return "medium";
    case 3:
      return "big";
    default:
      return NULL;
  }
}
void Dog::print(){
  Pet::print();
  cout<<"Dog_:"<<"name:"<<this->getName()<<"-"<<"size:"<<getStrSizeByIntParam(this->getSize())<<endl;
}

int main(){
  int t;
  cout<<"input the quantity of Pet:"<<endl;
  cin>>t;
  for(int i=0;i<t;i++){
    char type;
    cout<<"input the number "<<t<<" type(C or D):"<<endl;
    cin>>type;
    if(type == 'C'){
      string type,name,food;
      int number;
      cout<<"input the type,number,name,food:"<<endl;
      cin>>type>>number>>name>>food;
      Cat *cat = new Cat(type,number,name,food);
      cat->print();
      delete cat;
    }else if(type == 'D'){
      string type,name;
      int number,size;
      cout<<"input the type,number,name,size:"<<endl;
      cin>>type>>number>>name>>size;
      Dog *dog = new Dog(type,number,name,size);
      dog->print();
      delete dog;
    }else{
      cout<<"make sure you are input C or D"<<endl;
    }
  }

}


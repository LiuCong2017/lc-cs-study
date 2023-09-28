#include <iostream>
#include <fstream>
using namespace std;

void writeFile()
{
    fstream file;
    file.open("File.txt",ios::out); //File opened in write mode
    if (!file){
        cout<<"Error while creating the file";
    }
    else{
        cout<<"File created successfully";
        file<<"test file";
        file.close();
    }
}

void readFile()
{
    fstream file;

    //File Position Pointers
//    file.seekg(ios::beg)
//    file.seekg(ios::cur)
//    file.seekp(ios::end)

    file.open("File.txt",ios::in); //	File opened in reading mode
    if (!file) {
        cout<<"File doesn’t exist.";
    }else {
        char x;
        while(1){
            file>>x;
            if (file.eof()) break;
            cout<<x;
        }
    }
    file.close();
}

void inFile()
{
    ifstream in;
    in.open("File.txt",ios::in);
    string w;
    while (in>>w){
        cout<<w;
    }
    in.close();
}

int main()
{
//    writeFile();
//    readFile();
    inFile();

    return 0;
}
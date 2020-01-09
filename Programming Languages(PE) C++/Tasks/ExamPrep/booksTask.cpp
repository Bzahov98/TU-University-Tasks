//
// Created by bzahov on 8.01.20 г..
//

#include <iostream>

using namespace std;
class Book;
class Library;

class Library{


    int booksCount;
    string* booksArr;
    Library(int bCount,string* arr){
        booksCount = bCount;
        booksArr = new string [bCount] ;
    }
    ~Library(){
        delete booksArr;
    }

};

class Book : public Library{
    string author;
    bool isAvailable;
    string getDate;

};

int main (){
    cout<< "bbb";
    return 0;
}


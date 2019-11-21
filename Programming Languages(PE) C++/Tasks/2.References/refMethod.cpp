#include <iostream>
#include <stdlib.h>
using namespace std;
class array{
    int size;
    char *p;

public:
    array(int num);
    ~array() { 
        delete[] p; 
    }
    char& put(int i);
    char  get(int i);
};
array::array(int num)
{
    p = new char[num];
    if (!p){
        cout << "Allocation error\n";
        exit(1);
    }
    size = num;
}
char& array::put(int i) //Поставя се нещо в масива
{
    if (i < 0 || i >= size){
        cout << "Bounds error!!!\n";
        exit(1);
    }
    return p[i]; //връща псевдоним за p[i]
}
char array::get(int i) //Взема се нещо от масива.
{
    if (i < 0 || i >= size){
        cout << "Bounds error!!!\n";
        exit(1);
    }
    return p[i]; //връща символ
}
int main(int argc, char **argv[]){
    array a(10);
    a.put(3) = 'X';
    a.put(2) = 'R';
    cout << a.get(3) 
         << "\n"
         << a.get(2);
    cout << "\n";
    a.put(11) = '!'; //сега се генерира грешка по време на изпълнение
    return 0;
}
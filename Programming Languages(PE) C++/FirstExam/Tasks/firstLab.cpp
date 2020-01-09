//
// Created by bzahov on 20.11.19 г..
//

#include <iostream>
#include <math.h>
using namespace std;
class triangle { //Декларация на клас triangle
private:
    double a, b, c; //Член-данни на класа
public:
    triangle(); //Декларация на конструктор
    double face(); //Декларация на член-функция
    void show(char *); //Декларация на член-функция
    ~triangle() //Дефиниция на деструктор
    {
        cout << "\nDestructing object triangle!\n";
    }
};
triangle::triangle() //Дефиниция на конструктора
{
    do
    {
        cout << "\n\nEnter three values for the sides of triangle:\n";
        cin >> a >> b >> c;
    }
    while(!((a>0)&&(b>0)&&(c>0)&&((a+b>c)&&((a+c)>b)&&((b+c)>a))));
}
double triangle::face() //Дефиниция на член-функция
{
    double p, s;
    p = (a+b+c)/2;
    s = sqrt(p*(p-a)*(p-b)*(p-c));
    return s;
}
void triangle::show(char *name) //Дефиниция на член-функция
{
    cout << "Sides of the triangle " << name << ":\n";
    cout << "a=" << a << ",b=" << b << ",c=" << c;
}

int main(){
    triangle ob1; //Създаване на обект ob1 от клас triangle
    double s;
    s = ob1.face(); //Извиква се член-функция face() за обект ob1
    ob1.show("riangle1"); //Извиква се член-функция show() за обект ob1
    cout << "\nThe face of triangle1 is s=" << s;
    triangle ob2;
    triangle *p; //Декларира се указател към обект от клас triangle
    p = &ob2; //Указателят се установява да сочи към ob2
    s = p->face(); //Извиква се член-функция face() за обект ob2
    p->show("triangle2"); //Извиква се член-функция show() за обект ob2
    cout << "\nThe face of triangle2 is s=" << s;
    return 0;
}


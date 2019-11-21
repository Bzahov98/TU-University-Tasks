#include <iostream>
#include <math.h>
using namespace std;
class point //Клас точка
{
    double x;
    double y;

public:
    point(double xcoord, double ycoord);           //Конструктор с два параметъра
    void print();                                  //Печат на точка
    double dist(const point &p1, const point &p2); //Разстояние между дветочки
    ~point(); //Деструктор
};
point::point(double xcoord, double ycoord) //Конструктор с два параметъра
{
    cout << "Creating Point(" << xcoord << "," << ycoord << ")" << endl;
    x = xcoord;
    y = ycoord;
}
void point::print() //Печат на точка
{
    cout << "Point(" << x << "," << y << ")";
}
// const - не може да се променя състоянието на обекта Read only
double point::dist(const point &p1, const point &p2) // Разстояние между две точки
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
point::~point() //Деструктор
{
    cout << "Destructing ";
    print();
    cout << endl;
}
int main(int argc, char* *argv[])
{
    point a(3, 4), b(10, 4); //Обекти от тип Точка
    cout << "Distance between ";
    a.print();
    cout << " and ";
    b.print();
    cout << " is " << a.dist(a, b) << endl;
    return 0;
}
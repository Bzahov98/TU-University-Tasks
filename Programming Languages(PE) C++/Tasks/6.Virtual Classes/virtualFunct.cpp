#include <iostream>
using namespace std;
class Area
{
    double dim1, dim2; //размери на фигурата
public:
    void setArea(double d1, double d2)
    {
        dim1 = d1;
        dim2 = d2;
    }
    void getDim(double &d1, double &d2)
    {
        d1 = dim1;
        d2 = dim2;
    }
    virtual double getarea() = 0; //чисто виртуална функция
};
class Rectangle : public Area
{
public:
    double getarea()
    {
        double d1, d2;
        getDim(d1, d2);
        return d1 * d2;
    }
};
class Triangle : public Area
{
public:
    double getarea()
    {
        double d1, d2;
        getDim(d1, d2);
        return 0.5 * d1 * d2;
    }
};
int main(int argc, const char **argv)
{
    Area *p;
    Rectangle r;
    Triangle t;
    r.setArea(3.3, 4.5);
    t.setArea(4.0, 5.0);
    p = &r;
    cout << "Rectangle has area: " << p->getarea() << "\n";
    p = &t;
    cout << "Triangle has area: " << p->getarea() << "\n";
    return 0;
}
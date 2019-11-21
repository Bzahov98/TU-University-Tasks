#include <iostream>
using namespace std;
class Coord{
    int x, y; //кординатни стойности
public:
    Coord(){x = y = 0 ;}
    Coord(int a, int b){
        x = a;
        y = b;
    }
    void getXY (int& a, int& b){
        a = x;
        b = y;
    }
    friend Coord operator++(Coord &ob);
};

Coord operator++(Coord &ob) //Предефинира ++ с помощта на приятелска функция
{
    ob.x++;
    ob.y++;
    return ob; //връща обекта, който е извършил извикването
}
int main(int argc, char **argv[])
{
    Coord o1(10, 10);
    int x, y;
    ++o1; //o1 се подава с псевдоним
    o1.getXY(x, y);
    cout << "(++o1) X:" << x << ", Y:" << y << "\n";
    return 0;
}
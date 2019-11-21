#include <iostream>
using namespace std;

class Coord{
    private:
    int x,y;
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
    //binars operators
    //Coord operator+(Coord& ob2);
    Coord operator+(Coord ob2);
    Coord operator-(Coord ob2);
    Coord operator=(Coord ob2);
    //unars operators
    Coord operator--(); // prefix --
    Coord operator--(int notUsed); // postfixed --
    Coord operator++(); // prefix ++
    Coord operator++(int notUsed); // postfixed ++
};

//предефиниране на + за класа coord чрез псевдоним
/*Coord Coord::operator+(Coord &ob2){ 
    Coord temp;
    temp.x = x + ob2.x;
    temp.y = y + ob2.y;
    return temp;
}*/
// binars operators
Coord Coord::operator+(Coord ob2){
    Coord tmp;
    tmp.x = x + ob2.x;
    tmp.y = y + ob2.y;
    return tmp;
}

Coord Coord::operator-(Coord ob2){
    Coord tmp;
    tmp.x = x-ob2.x;
    tmp.y = y-ob2.y;
    return tmp;
}

Coord Coord::operator=(Coord ob2){
    x = ob2.x;
    y = ob2.y;
    return *this;
}
//unars operators
Coord Coord::operator--(){ // prefix
    x--;
    y--;
    return *this;
}
Coord Coord::operator--(int notused){ //posfix
    x--;
    y--;
    return *this;
}
Coord Coord::operator++(){ // pre
    x--;
    y--;
    return *this;
}
Coord Coord::operator++(int notused){ // post
    x--;
    y--;
    return *this;
}


int main(int argc, const char** argv) {
    Coord o1(10,10), o2(5,3), o3;
    int x, y;

    o3 = o1 + o2; //добавя два обекта – извиква се operator+()
    o3.getXY(x, y);
    cout << "(o1+o2) X:" << x << ", Y:" << y << "\n";
    
    o3 = o1 - o2; //изважда два обекта – извиква се operator-()
    o3.getXY(x, y);
    cout << "(o1-o2) X:" << x << ", Y:" << y << "\n";
    
    o3 = o1;      //присвоява обект - извиква се operator=()
    o3.getXY(x, y);
    cout << "(o3=o1) X:" << x << ", Y:" << y << "\n";
    return 0;
}
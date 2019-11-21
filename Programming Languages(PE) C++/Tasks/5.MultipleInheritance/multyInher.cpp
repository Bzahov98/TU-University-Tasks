#include <iostream>
#include "string.h"

class Car{
    private:
    char* mark;
    int yearManufact;
    public:
    Car(char*,int);
    ~Car(){
        delete mark;
    }
    void print();
};
Car::Car(char* m, int y){
    mark = new char[strlen(m)+1];
    strcpy(mark,m);
    yearManufact = y;
}
void Car::print(){
    std::cout << mark << std::endl;
    std::cout << yearManufact << std::endl;
}

class TheCar : public Car{
    private:
    int regNumber;
    public:
    TheCar(char *m,int y,int r) : Car(m,y){ regNumber = r;}
    void print();
};

void TheCar::print(){
    Car::print();
    std::cout << regNumber << std::endl;
}

class CarOwner{
    protected:
    char* name;
    int age;
    public:
    CarOwner(char* n,int a);
    ~CarOwner(){
        delete name;
    }
    void print(){
        std::cout << name << std::endl;
        std::cout << age  << std::endl;
    }
};

CarOwner::CarOwner(char* n , int a){
    name = new char[strlen(n)+1];
    age = a;
}

class CarDocument : public TheCar,public CarOwner {
    public: 
    CarDocument(char* ownerName,int ownerAge,
                char *mark,int year,int reg) 
                : CarOwner(ownerName,ownerAge)
                , TheCar(mark,year,reg){};
    void print();
};

void CarDocument::print(){
    TheCar::print();
    CarOwner::print();
}

int main(int argc, const char** argv) {
    TheCar a("bla",2,4);
    a.print();

    CarDocument c("ford",2002,"Bojo",1234,21);
    c.print();
    return 0;
}
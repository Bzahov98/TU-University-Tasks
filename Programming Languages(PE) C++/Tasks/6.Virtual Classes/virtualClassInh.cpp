#include <iostream>
#include "string.h"
using namespace std;

class Vehicle
{
    int numWheels;
    int range;

public:
    Vehicle(int n, int r) { numWheels = n; range = r; }
    void showv()
    {
        cout << "Wheels:" << numWheels << "\n";
        cout << "Range:" << range << "\n";
    }
};

enum Motor
{
    gas,
    electric,
    diesel
};
class Motorized : virtual public Vehicle
{
    enum Motor mtr;

public:
    Motorized(enum Motor m, int w, int r) : Vehicle(w, r) { mtr = m; }
    void showm()
    {
        cout << "Motor:";
        switch (mtr)
        {
        case gas:
            cout << "Gas\n";
            break;
        case electric:
            cout << "Electric\n";
            break;
        case diesel:
            cout << "Diesel\n";
        }
    }
};
class RoadUse : virtual public Vehicle
{
    int passengers;

public:
    RoadUse(int p, int w, int r) : Vehicle(w, r) { passengers = p; }
    void showr()
    {
        cout << "Passengers:" << passengers << "\n";
    }
};
enum Steering
{
    power,
    rack_pinion,
    manual
};
class Car : public Motorized, public RoadUse
{
    enum Steering strng;

public:
    Car(enum Steering s, enum Motor m, int p, int w, int r) 
        : Motorized(m, w, r)
        , RoadUse(p, w, r)
        , Vehicle(w, r)
    {
        strng = s;
    }
    void show()
    {
        showv();
        showr();
        showm();
        cout << "Steering: ";
        switch (strng)
        {
        case power:
            cout << "Power\n";
            break;
        case rack_pinion:
            cout << "Rack and pinion\n";
            break;
        case manual:
            cout << "Manual\n";
        }
    }
};

int main(int argc, const char** argv) {
    Car c(power, gas, 5, 4, 500);c.show();
    return 0;
}
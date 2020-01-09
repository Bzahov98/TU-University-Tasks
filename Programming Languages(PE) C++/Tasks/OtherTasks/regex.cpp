#include <iostream>
#include <regex>
#include<string.h>

using namespace std;

int main() {
    // Target sequence 
    string s = ">regNum: ca2134vd,brand: brandddr,model: brakma,seats: 3,fuelPerKm: 1.240000,yearsOfUse: 5";

    // An object of regex for pattern to be searched 
    regex r("([,|>](\\w+)[:])");

    // regex_replace() for replacing the match with 'geek'
    Car newCar();
    newCar() << std::regex_replace(s, r, "\n");

    string result;


    cout << result;

    return 0;
}
/*Да се състави клас символен низ с член-данни: указател към началото на низа и дължина на низа. Член-
функциите на класа са: конструктори; деструктор; предефинирана операция + за конкатенация на низове;
проверка на типа на данните в низа (допустимост само на букви, интервал и точка); предефинирана операция =.
Да се състави клас служител с член-данни: трите имена (само букви); ЕГН (10 цифри); заплата по щат. Член-
функциите на класа са: конструктор (да проверява и за коректност на данните); предефинирана операция > за
сравняване на заплатите на двама служители.
1.Да се състави външна функция, която сортира масив от служители по заплата в намаляващ ред.
2.Да се състави главна функция, която създава масив от обекти и извежда данните за всички служители преди и
след сортиране.*/

#include <iostream>
#include "string.h"
using namespace std;

class Str{
    private:
    char* startPoint;
    int len;
    public:
    Str();
    Str(int l);
    Str(char*);
    ~Str(){
        delete [] startPoint;
        std::cout << "destruct str" << std::endl;
    }
    void print();
    bool isInputOk(char* str);
};

Str::Str(){
    int l = 10; // defaut length
    startPoint = new char[l];
    len = l;
}

Str::Str(int l){
        startPoint = new char[l];
        len = l;
}

Str::Str(char* newStr){
    if (isInputOk(newStr))
    {
    
        int l = strlen(newStr);
        startPoint = new char[l+1];
        strcpy(startPoint,newStr);
        len = l;
    }else std::cout << "Input is wrong" << std::endl;
}
bool isInputOk(char* str){
    for(int i = 0;i< strlen(str);i++){

        if (((str[i]>= 'a' && str[i]<'z')) || (str[i] == ' ')|| str[i]== '.')
        {
            continue;
        }else
        {
            return false;
        }
        return true;
    }
}
void Str::print(){
    std::cout << startPoint <<" length: " << len << std::endl;
}

class Employer : public Str{
    char* name;
    long egn;
    float salary;
    public:
    Employer(char*,long,float);
    bool operator>(const employ &e) const;
};

Employer::Employer(char* n,long e,float s):Str(n){
    egn = e;
    salary = s;
}

bool Еmployer::operator>(const employ &e) const
{
        if(salary > e.salary)
                return true;
        else
                return false;
}


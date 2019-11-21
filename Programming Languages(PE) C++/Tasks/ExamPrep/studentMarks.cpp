#include <iostream>
#include <vector>
#include <list>
#include <string>  
#include <ctime>
#include <new>
#include <fstream>
using namespace std;
/*
Курсова No1
Да се дефинира базов клас за студент зададен с име, факултетен номер, 
номер на група и курс. Да се дефинира производен клас за успех зададен 
с динамичен масив от оценките по всички дисциплини до момента (дължината 
на масива зависи от курса – счита се, че за семестър броят на оценките е 5). 
Класовете да включват  конструктори без параметри за попълване на член-променливите 
в диалог. Да се определят и извеждат средният  успех за всеки студент и максималния 
среден успех за зададена група. Да се извежда пълната информация за всеки студент 
и за студент, зададен с факултетния си номер. Да се предефинира операцията <<, 
която да се  използва за извеждане на данните. Данните да се съхраняват във файл.
*/
class Student {
    private:
    //char* name;
    string name;
    int facNum;
    int groupNum;
    int courseNum;
    public:
    Student();
    ~Student(){
        //delete name;
        std::cout << "destuct" << std::endl;
    }
   void setName();
   string getName() {
      return name;
   }
   void setFnum();
   int getFnum() {
      return facNum;
   }
   void setGroup();
   int getGroup() {
      return groupNum;
   }
   void setCourse();
   int getCourse() {
      return courseNum;
   }
   int writeStudentsIntoFile();
   
};

Student::Student(){
   setName();
   setFnum();
   setGroup();
   setCourse();
}
void Student::setName() {
   char c;
   cin.get(c);
   cout << "Vuvedete ime: ";
   getline(cin, name);
}
void Student::setFnum() {
   cout << "Vuvedete f. nomer: ";
   cin >> facNum;
}
void Student::setGroup() {
   cout << "Vuvedete grupa: ";
   cin >> groupNum;
}
void Student::setCourse() {
   cout << "Vuvedete curs: ";
   cin >> courseNum;
}


class Marks : public Student{
    vector<int> marksVector;
    static vector<Marks *> studentsVector;
    public:
    Marks();
    ~Marks(){
        std::cout << "destroing" << std::endl;
    }

    void setMarksVector();
    static void calc_Success();
    static int addStudent();
    friend void getMaxSuccessForGroup();
    friend void showInfoForStudent();
    friend ostream & operator<<(ostream&, Marks ob){}


};
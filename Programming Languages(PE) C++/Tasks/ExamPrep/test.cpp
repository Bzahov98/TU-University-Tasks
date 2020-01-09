#include <iostream>
#include <vector>
#include <string>  
#include <ctime>
#include <new>
#include <fstream>
using namespace std;
class Student {
   string name;
   int fnum;
   int group;
   int course;
   public: Student();
   ~Student() {
      cout << "Destructing!" << endl;
   }
   int writeStudentsIntoFile();
   void setName();
   string getName() {
      return name;
   }
   void setFnum();
   int getFnum() {
      return fnum;
   }
   void setGroup();
   int getGroup() {
      return group;
   }
   void setCourse();
   int getCourse() {
      return course;
   }
};
Student::Student() {
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
   cin >> fnum;
}
void Student::setGroup() {
   cout << "Vuvedete grupa: ";
   cin >> group;
}
void Student::setCourse() {
   cout << "Vuvedete curs: ";
   cin >> course;
}
class Ocenki: public Student {
   vector < int > ocenkii;
   static vector < Ocenki * > students;
   public: Ocenki();
   ~Ocenki() {
      cout << "Destructing!" << endl;
   }
   void setOcenki();
   static void sr_uspeh();
   static int addStudent();
   friend void max_uspeh();
   friend void showInfoForStudent();
   friend ostream & operator << (ostream & stream, Ocenki & ob);
   friend int writeStudentsIntoFile();
   friend void showInfo();
};

ostream& operator << (ostream & stream, Ocenki & ob){
    //stream>>ob.getName;
        std::cout << "Not implement <<" << std::endl;
        
    return stream;
}

void Ocenki::sr_uspeh(){

}

void showInfoForStudent(){
    std::cout << "Not implement showInfo" << std::endl;
}

void showInfo(){
    std::cout << "Not implement showInfo" << std::endl;
}

int writeStudentsIntoFile(){
    std::cout << "Not implement write into file" << std::endl;
    return 0;
}

void max_uspeh(){
    std::cout << "TODO max success" << std::endl;
}

vector < Ocenki * > Ocenki::students;
vector < int > ocenkii;
void Ocenki::setOcenki() {
   int a;
   unsigned int z = 2 * 5 * getCourse();
   while (ocenkii.size() < z) {
      cout << "Vuvedete ocenki: ";
      cin >> a;
      ocenkii.push_back(a);
   }
}
Ocenki::Ocenki(): Student() {
   setOcenki();
}
int Ocenki::addStudent() {
   Ocenki * ob;
   try {
      ob = new Ocenki;
      Ocenki::students.push_back(ob);
      return 0;
   } catch (bad_alloc ba) {
      cout << "Allocation failure." << endl;
      return 1;
   }
}
 
int main() {
   string choice;
   int ch;
   while (true) {
      cout << "n----------------------------- MENU -----------------------------" << endl;
      cout << "1. Dobavi student." << endl;
      cout << "2. Show result of execution of the predefined opeartor <<." << endl;
      cout << "3. Zapazi studentite vuv fail." << endl;
      cout << "4. Izvejdane na informaciq za vsi4ki studenti." << endl;
      cout << "5. Izvejdane na informaciq za konkreten student." << endl;
      cout << "6. Izvejdane na sredeniq uspeh na vseki student." << endl;
      cout << "7. Izvejdane na nai-visokiq sreden uspeh za zadadena grupa." << endl;
      cout << "Type  quit  for exit." << endl;
      cout << "----------------------------------------------------------------" << endl;
      cout << "Enter your choice: ";
      cin >> choice;
      if (choice == "quit") break;
      ch = atoi(choice.c_str());
      switch (ch) {
      case 1:
         {
            if (!Ocenki::addStudent()) cout << "Student successfully added!" << endl;
            else cout << "Student wasn't added!" << endl;
         }
         break;
      case 2:
         {
            Ocenki ob;cout << "Showing information about student using <<." << endl;cout << ob;
         }
         break;
      case 3:
         {
            if (!writeStudentsIntoFile()) cout << "Students successfully writed into file!" << endl;
            else cout << "Students unsuccessfully writed into file!" << endl;
            break;
         }
      case 4:
         {
            showInfo();
            break;
         }
      case 5:
         {
            showInfoForStudent();
            break;
         }
      case 6:
         {
            Ocenki::sr_uspeh();
            break;
         }
      case 7:
         {
            max_uspeh();
            break;
         }
      default:
         cout << "Wrong choice!" << endl;
      }
   };
   return 0;
}
#include<stdio.h>
/*Да се напише програма, в която се въвежда цяло число, което представлява код на
геометрична фигура – 1 – квадрат, 2 – правоъгълник, 3 – правоъгълен триъгълник, 4 –
окръжност. След това се въвеждат размерите на избраната геометрична фигура. Програмата
трябва да изведе типа на геометричната фигура, както и нейното лице. За пресмятането на
лицето да се напишат подходящи функции.*/

void loadMenu();
int readValues();
int square();
int rectangle();
int triangle();
int circle();

int main(int argc, char const *argv[]) {
  loadMenu();
  return 0;
}

void loadMenu(){
  int choice;
  while (1) {
    printf("%s\n", "Please enter type num of geometric figure\n1 - square, 2 - rectangle, \n3 - triangle, 4 - circle\n other for EXIT");
    scanf(" %d",& choice);

    if (!(choice > 0 && choice < 5)) loadMenu();
    switch (choice) {
      case 1:
        square();
        break;
      case 2:
        rectangle();
        break;
      case 3:
        triangle();
        break;
      case 4:
        circle();
        break;
      default:
        return;
    }
  }
}
int square(){
  int a=0,result=0;
  printf("%s\n", "Please enter geometric figure, a");
  scanf(" %d",& a);
  result = a*a;
  printf("Square S= %d\n", result);
  return result;
}
int rectangle(){
  int a=0,b=0,result=0;
  printf("%s\n", "Please enter geometric figure a");
  scanf(" %d",& a);
  printf("%s\n", "Please enter geometric figure b");
  scanf(" %d",& b);

  result = a*b;
  printf("Rectangle %d\n", result);
  return result;
}
int triangle(){
  int a=0,b=0,result=0;
  printf("%s\n", "Please enter geometric figure a");
  scanf(" %d",& a);
  printf("%s\n", "Please enter geometric figure b");
  scanf(" %d",& b);

  result = (a*b)/2;
  printf("Triangle %d\n", result);
  return result;
}
int circle(){
  int r,result=0;
  printf("%s\n", "Please enter geometric figure r");
  scanf(" %d",& r);
  result = 3.14 * (r*r);
  printf("Circle %d\n", result);
  return result;
}

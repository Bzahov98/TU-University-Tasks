#include<stdio.h>

int main(){
  int sum=0,totSum=0,first = 1;
  char str[] = "aaa21 bbb54 sss111 aaa55";

  for (int i = 0; /*str[i] != '\0'*/; i++) {
    printf(">%c\n", str[i]);
    if (str[i] >= '0' && str[i]<= '9') {
      printf(">>%c\n", str[i]);
      if (first==1) {
        //printf(">>%d<<<\n", str[i] );
        sum+= str[i]- '0';
        first = 0;
      }else{
        sum *=10;
        sum += str[i] - '0';
      }
    }
    if (str[i] == ' ' || str[i] == '\0') {
      first = 1;
      printf(">>>%d\n", sum);
      totSum += sum;
      sum = 0;
      printf(">>>%d\n", totSum);
      if (str[i] == '\0') {
        break;
      }
    }
  }

  printf("TotalSum %d\n",totSum );
  return 0;
}

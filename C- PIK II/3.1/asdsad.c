#include<stdio.h>
#include<string.h>

//int calculateNumberFromString(char* inputStr);

int main() {
  int i = 0 , j = 0,n = 10;
  int array[n][n];
  char* inputStr;
  for (size_t i = 0; i < 10; i++) {
    for (size_t j = 0; j < 10; j++) {
      array[i][j]= j;
      //printf("%d\n", array[i][j]);
    }
    //printf("\n" );
  }
  //1
  for (size_t i = 0; i < n; i++) {
      printf("%d\n", array[i][i]);
    //printf("\n" );
  }
printf("\n" );
  //2
  for (size_t i = 0; i < n; i++) {
    printf("%d\n", 3* array[i][n-1-i]);

  }
  printf("\n" );


  //scanf("%s", &inputStr);
  //calculateNumberFromString(inputStr);
  return 0;
}

/*int calculateNumberFromString(char* inputStr){
  for (int i = 0; i < strLeng(inputStr); i++) {

  }
  return 0;
}*/

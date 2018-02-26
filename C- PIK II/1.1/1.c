#include<stdio.h>
const int ARRAY_LINE_SIZE = 22;
int int main(void) {
  int i, j, numer;

  return 0;
}

int readFromFile(char allLines[][ARRAY_LINE_SIZE]){
  char inputFileName[100];// = "homework2_BZ.c", outputFileName[] = "test.c";
  int i, j;
  char line[ARRAY_LINE_SIZE];
  FILE *file;

  do {
    printf("Моля въведете името на файла, от който искате да четете!, 'Q' за връщане към менюто\n");
    //printf("Please write path and file name from which to read\n");
    scanf("%s",&inputFileName[0]);

    file = fopen ( inputFileName, "r" );

    if ( file == NULL ){ // check file for wrong
      printf("\n!!!Грешка с файла!!!\n" );
      perror ( inputFileName );

    }else break; // file is fine, continues to read it
  } while(1);

    while (fgets(line, sizeof line, file ) != NULL ){

    }
  }

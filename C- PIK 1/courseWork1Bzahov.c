#include<stdio.h>
#include<string.h>
#define ARRAY_SIZE 150
#define ARRAY_LINE_SIZE 256
#define STR_QUIT_Q "Q"
#define STR_QUIT_q "q"
//enum operators{if = "if", else = "else", switch = "switch", goto = "goto"}

// read functions
int readFromFile    (char allLines[][ARRAY_LINE_SIZE]); // DONE
int readFromKeyboard(char allLines[][ARRAY_LINE_SIZE]); // DONE

// task functions
int lineWithLessSymbols(char allLines[][ARRAY_LINE_SIZE]); //TODO
void operatorsInProgram(char allLines[][ARRAY_LINE_SIZE]){};  //TODO

// write functions
void writeToFile(void){};         //TODO
void writeToScreen(void){};       //TODO

// support functions
void loadMenu(char array[][ARRAY_LINE_SIZE]); // check functions return value
void printfDoubleArray(char allLines[][ARRAY_LINE_SIZE]); // ALMOST DONE TODO
void zeroDoubleArray(char allLines[][ARRAY_LINE_SIZE]); // DONE
int checkFileExtention(char inputFileName[]); // TODO
char* cleanExtraWhiteSpaces(char line[]);

//*****************************************************************************************
int main(){

  int i, j;
  char allLines[ARRAY_SIZE][ARRAY_LINE_SIZE] = {{""}};;

  zeroDoubleArray(allLines);
  loadMenu(allLines);

  return 0;
}
//*****************************************************************************************
void loadMenu(char allLines[][ARRAY_LINE_SIZE]){
    char choice;

    do{
        printf("\n>------------------------------------------------------------<\n");
        printf(">Моля изберете номер на опция:                               <\n");
        printf(">1. Четене от Файл и запис във файл                          <\n");
        printf(">2. Четене от Файл и извеждане на резултата на екрана        <\n");
        printf(">3. Четене от клавиатурата и извеждане във Файл              <\n");
        printf(">4. Четене от клавиатурата и извеждане на резултата на екрана<\n");
        printf(">5. Изход от програмата ( 'Q' or 'q' )                       <\n");
        printf(">------------------------------------------------------------<\n");

        scanf(" %c",&choice); // space before the %; this consumes the whitespace so that the next scanf call should work

        switch(choice){
            //Menu options;
            case '1':
              printf(">>Избрахте: 1. Четене от Файл и запис във файл<\n");
              zeroDoubleArray(allLines);

              if (readFromFile(allLines) != 0) {
                break;
              }
              lineWithLessSymbols(allLines);
              operatorsInProgram(allLines);
              writeToFile();
              break;
            case '2':
              printf(">>Избрахте: 2. Четене от Файл и извеждане на резултата на екрана<\n");
              zeroDoubleArray(allLines);

              if (readFromFile(allLines) != 0) {
                break;
              }
              lineWithLessSymbols(allLines);
              operatorsInProgram(allLines);
              writeToScreen();
              break;
            case '3':
              printf(">>Избрахте: 3. Четене от клавиатурата и извеждане във Файл<\n");
              zeroDoubleArray(allLines);

              readFromKeyboard(allLines);
              lineWithLessSymbols(allLines);
              operatorsInProgram(allLines);
              writeToFile();
              break;


            case '4':
              printf(">>Избрахте: 4. Четене от клавиатурата и извеждане на резултата на екрана\n");
              zeroDoubleArray(allLines);
              readFromKeyboard(allLines);
              lineWithLessSymbols(allLines);
              operatorsInProgram(allLines);
              writeToScreen();
              break;
            //Quit program options;
            case 'Q':
            case 'q':
            case '5':
                printf(">>Изход\n");
                return;
                break;
            default: printf(">>Невалиден избор, моля въведете пак!\n");
                break;
        }

    } while (1);

}

int lineWithLessSymbols(char allLines[][ARRAY_LINE_SIZE]){
  int result=0,i,j,sumbolNumber;
  for (i = 0; i < ARRAY_SIZE; i++) {
    //TODO//allLines[i] = cleanExtraWhiteSpaces(allLines[i]);
  }
  return result;
};

int readFromFile(char allLines[][ARRAY_LINE_SIZE]){
  char inputFileName[100];// = "homework2_BZ.c", outputFileName[] = "test.c";
  int i, j;
  char line[ARRAY_LINE_SIZE];
  FILE *file;

  do {
    printf("Моля въведете името на файла, от който искате да четете!, 'Q' за връщане към менюто\n");
    //printf("Please write path and file name from which to read\n");
    scanf("%s",&inputFileName);
    if (!(strcmp(inputFileName, STR_QUIT_Q) == 0 || strcmp(inputFileName, STR_QUIT_q))) {
      return 1; // return to Menu
    }else if (checkFileExtention(inputFileName)) {
      continue; // ask for new path
    }

    file = fopen ( inputFileName, "r" );

    if ( file == NULL ){ // check file for wrong
      printf("\n!!!Грешка с файла!!!\n" );
      perror ( inputFileName );

    }else break; // file is fine, continues to read it
  } while(1);
  i=0;

  while ( fgets ( line, sizeof line, file ) != NULL ){
    //printf(">Line number:%d-> %s ",i, line);
    strcpy(allLines[i], line);
    i++;
  }

  strcpy(allLines[i],"\0"); // add termination sign in end

  fclose ( file );

  //printfDoubleArray(allLines);

  return 0;
};

int readFromKeyboard(char allLines[][ARRAY_LINE_SIZE]){
  char str[ARRAY_LINE_SIZE];
  int i,x= 0,y = 0;

  while (fgets(str,ARRAY_LINE_SIZE,stdin) != NULL) {
    for (i = 0; str[i] != '\0'; i ++) {
      char currentChar = str[i];
      if (currentChar == '\n'){//} || ((y-1) <= ARRAY_LINE_SIZE)) {
        y = 0;
        x++;
      }else{
        allLines[x][y] = currentChar;
        y++;
      }
      //printf(">>>>%d\n", y);
      //printf("< X: %d ,Y: %d, Char: %c >\n", x,y,currentChar);

    }
  }
  y = 0;
  printf("\n%s\n", "VVVVVVVV");
  printfDoubleArray(allLines);
  return 0;
};

void printfDoubleArray(char allLines[][ARRAY_LINE_SIZE]){
  int i,j;

  for (int i = 0; i< 10 /*TODO*/ ; i++){ //!! TODO: allLines[i][0] != '\0' strcmp(allLines[i],"")) strcmp(allLines[i],"\0"))
    for (int j = 0; allLines[i][j] != '\0'; j++){
      printf("[%d][%d]>> %c\n",i,j,allLines[i][j]);
    }
  }
}

void zeroDoubleArray(char allLines[][ARRAY_LINE_SIZE]){
  int i,j;
  for(i = 0; i < ARRAY_SIZE; i++)
     for(j = 0; j < ARRAY_LINE_SIZE; j++){
       allLines[i][j] = '\0';
     }
}

int checkFileExtention(char inputFileName[]){
  // TODO: !!!!
  printf("%s\n","checkFileExtention" );
  return 0; // for true ,c
}

char* cleanExtraWhiteSpaces(char line[]){//allLines[][ARRAY_LINE_SIZE],int indexOfArray{
//char line[100];
  int i,length,k;
  //scanf("%[^\n]s",line);
  length=strlen(line);

  for(i=0;i<length;){
      if((line[i]==' ')&&(line[i+1]==' ')){
          for(k=i+1;k<length;k++){
              line[k]=line[k+1];
          }
          length= length - 1;
      }
      else i++;
  }
  printf("\n> %s <",line);
  return line;
}

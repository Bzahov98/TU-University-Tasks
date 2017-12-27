#include<stdio.h>
#include<string.h>

#define ARRAY_SIZE 300       // do not work with more than that amount of lines
#define ARRAY_LINE_SIZE 1256 // do not work with more than that amount of symbols per line
#define FILENAME_SIZE 100

#define STR_QUIT_Q "Q"
#define STR_QUIT_q "q"
#define C_FILE_EXTENTION "c"

enum operators {ifEnum, elseEnum, switchEnum, gotoEnum};

// read functions
int readFromFile    (char allLines[][ARRAY_LINE_SIZE]); // DONE
int readFromKeyboard(char allLines[][ARRAY_LINE_SIZE]); // DONE

// task functions
int lineWithLessSymbols(char allLines[][ARRAY_LINE_SIZE]); //    TODO
void operatorsInProgram(char allLines[][ARRAY_LINE_SIZE]){};  // TODO

// write functions
void writeToFile(void){};  //TODO
void writeToScreen(void){};//TODO

// support functions
void loadMenu(char allLines[][ARRAY_LINE_SIZE]); // NOTE check functions return value
void printfDoubleArray(char allLines[][ARRAY_LINE_SIZE]); // DONE
void zeroDoubleArray(char allLines[][ARRAY_LINE_SIZE]); // DONE
int checkFileExtention(char inputFileName[], const char extention[]); // DONE
char* cleanExtraWhiteSpaces(char line[]); // DONE

//*****************************************************************************************
int main(){

  char allLines[ARRAY_SIZE][ARRAY_LINE_SIZE] = {{""}};;

  printf("%d\n", elseEnum);

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
  int result=0,i,j,symbolCount;
  char currentLine[ARRAY_LINE_SIZE],sub[] = "\"";
  char* splittedLine;
  //printfDoubleArray(allLines);
  //printf("\n**************\n");
  //printf("%d %c >>%s<<\n", strlen(allLines[0]),allLines[0][0], allLines[0]);
  if (!strlen(allLines[0])) {
    printf("Грешка - Липса на данни! >%s< %d\n",allLines[0],strlen(allLines[0]));
    return -1; // with error
  }
  for (i = 0; i < 7/*HACK*/; i++) { //IsStringEmpty()
    printf("%s\n", "inLoop\n");
    strcpy(currentLine,allLines[i]);
    if (currentLine && sub) {
    for (char *p = currentLine; (p = strstr(p, sub)) != NULL; p++) {
        j++;
        // substring found at offset
        printf("Found at: %s %tu\n",currentLine, p - currentLine);
        if (*p == '\0')  /* special case for the empty string */
            break;
    }
    if (j == 0) {
        // substring not found
        printf("j = 0\n");
    }
}
    //printf("%d %c >>%s<<\n", strlen(allLines[i]),allLines[i][0] ,allLines[i]);
    //printf("Next: %d %d %c >>%s<<\n", strlen(allLines[i+1]),allLines[i+1][0] == '\0',allLines[i+1][0] ,allLines[i+1]);
    if (!strlen(allLines[i+1]) || i >= ARRAY_SIZE) { //exit when reach end of array //allLines[i+1][0] == '\0' ||
      /*printf("%d %c >>%s<<\n", strlen(allLines[i]),allLines[i][0] ,allLines[i]);
      printf("Next: %d %d line:%d %c >%s<\n", strlen(allLines[i+1]),allLines[i+1][0] == '\0',i,allLines[i+1][0], allLines[i+1]);
      */
      break;
    }
  }
  return result;
}

int readFromFile(char allLines[][ARRAY_LINE_SIZE]){
  char inputFileName[FILENAME_SIZE];// = "homework2_BZ.c", outputFileName[] = "test.c";
  int i = 0;
  char line[ARRAY_LINE_SIZE];
  FILE *inputFile;
  do/* open inputFile*/{
    //printf("Please write path and file name from which to read\n");
    printf("Моля въведете името на файла, от който искате да четете!, 'Q' за връщане към менюто\n");
    scanf("%s",&inputFileName);
    if (!(strcmp(inputFileName, STR_QUIT_Q) == 0 || strcmp(inputFileName, STR_QUIT_q))) {
      return 1; // return to Menu
    }else if (!checkFileExtention(inputFileName, C_FILE_EXTENTION)) {
      continue; // ask for new path
    }

    inputFile = fopen (inputFileName, "r");
    if ( inputFile == NULL ){ // check file for wrong
      printf("\n!!!Грешка с файла!!!\n");
      perror (inputFileName);
    }else break; // file is fine, continues to read it
  }while(1);

  while (fgets(line, ARRAY_LINE_SIZE, inputFile) != NULL){
    //printf(">Line number:%d-> %s ",i, line);
    if (i < ARRAY_SIZE-1) {
      strcpy(allLines[i], line);
      i++;
    }else {
      printf("Файлът е твърде дълъг!!! Ще се обработи до ред: %d\n", i);
      break;
    }
  }

  strcpy(allLines[i],"\0"); // add termination sign in end
  fclose (inputFile);
  printfDoubleArray(allLines);
  return 0;
};

int readFromKeyboard(char allLines[][ARRAY_LINE_SIZE]){ // BUG NB RETURN EMPTY allLines
  char str[ARRAY_LINE_SIZE];
  int i,x= 0,y = 0;

  while (fgets(str,ARRAY_LINE_SIZE,stdin) != NULL) {
    for (i = 0; str[i] != '\0'; i ++) {
      char currentChar = str[i];
      if (currentChar == '\n'){//} || ((y-1) <= ARRAY_LINE_SIZE)) {
        y = 0;
        if (!(++x < ARRAY_SIZE-1)) {
          printf("Файлът е твърде дълъг!!! Ще се обработи до ред: %d\n", i);
          break;
        }
      }else{
        if (y < ARRAY_LINE_SIZE-1){
          allLines[x][y] = currentChar;
          printf("< X: %d ,Y: %d, Char: %c allLines: %c>\n", x,y,currentChar,allLines[x][y]);
          printfDoubleArray(allLines);
          y++;
        }else {
          printf("Редът %d е твърде дълъг!!! Ще се обработи до %d символ\n", x,y);
          y = 0;
          x++;
        }
      }
      //printf(">>>>%d\n", y);      //printf("< X: %d ,Y: %d, Char: %c >\n", x,y,currentChar);
    }
  }
  y = 0;
  printfDoubleArray(allLines);
  return 0;
};

void printfDoubleArray(char allLines[][ARRAY_LINE_SIZE]){
  int i,j;
  printf("\n%s\n", "VVVVVVVV");
  for (i = 0; strlen(allLines[++i]); i++){
    for (j = 0; allLines[i][j] != '\0'; j++){
      printf("[%d][%d]>> %c\n",i,j,allLines[i][j]);
    }
  }
  printf("%s\n", "^^^^^^^^^^");
}

void zeroDoubleArray(char allLines[][ARRAY_LINE_SIZE]){
  int i;//,j;
  for(i = 0; i < ARRAY_SIZE; i++) //allLines[i+1] != 0
     //for(j = 0; j < ARRAY_LINE_SIZE; j++){
       allLines[i][0] = '\0';
     //}
}

int checkFileExtention(char inputFileName[], const char extention[]){
  int i = 0;
  char tempFileName[FILENAME_SIZE];
  char *splitedArray[FILENAME_SIZE];
  strcpy(tempFileName,inputFileName);

  splitedArray[i] = strtok(tempFileName,".");
  while(splitedArray[i]!=NULL){
   splitedArray[++i] = strtok(NULL, ".");
  }
  if(!strcmp(extention, splitedArray[i-1]) == 0) { //get extention
    printf("'%s' не е правилното окончание: '%s'\n", splitedArray[i-1], extention);
    return 0;  // false Not ending with .c (extention[])
  }else return 1;  // for true ending with .c (extention[])
}

char* cleanExtraWhiteSpaces(char line[]){ //allLines[][ARRAY_LINE_SIZE],int indexOfArray{
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

#include <stdio.h>
#include <string.h>

void scanWordForCheck(char *scanWord);

int main()	{
	char str[256], scanWord[50], word[100][256]; // [x][y]

	int index = 0,indexOfCharacter = 0, x= 0, y = 0, z = 0,length = 0, startWordIndex = 0,finishWordIndex = 0;
    int max = 0, min, maxIndx = 1000, minIndx = 0,c = 0, count;
	int isInWord = 1, isWordSame; // false

  scanWordForCheck(scanWord);

  //clear_newlines();
  printf(">Please insert sentence\n" );
  printf(">Stop input with Ctrl + Z or Ctrl + D\n" );
	while (fgets(str,255,stdin) != NULL) {
    for (index = 0; index < str[index]; index ++) {
			char currentChar = str[index];
      if (currentChar == ' ' || currentChar == '\0' || currentChar == '\t' || currentChar == '\n') {
        y = 0;
        x++;
      }else{
      word[x][y] = currentChar;
      y++;
    }
    //printf("< X: %d ,Y: %d, Char: %c >\n", x,y,currentChar);
    //printf(">>>>%d\n", y);

  }

  y = 0;

  } // end of while

  count = 0;
  for ( index = 0; index <= x; index++ ) {
    isWordSame = 1;
    for ( indexOfCharacter = 0; word[index][indexOfCharacter] != '\0'; indexOfCharacter++ ) { //|| (word[x][j] != ' ')
      printf("word[%d][%d] = %c\n", index,indexOfCharacter, word[index][indexOfCharacter] );

      if (indexOfCharacter > max) {
        max = indexOfCharacter;
        maxIndx = index;
      }

      if (word[index][indexOfCharacter] != scanWord[indexOfCharacter]) {
        isWordSame = 0;
      }
    }
    if (indexOfCharacter < min) {
    //  printf("\n_min___%d____\n",index );
      min = indexOfCharacter;
      minIndx = index;
    }

    if (isWordSame) {
      count++;
    }
    printf("---Next Word---\n");
  }

  printf("Word: \'%s\' is found %d times\n",&scanWord, count);
  printf(">The maximum symbols: %d, Word: %d\n", max,maxIndx+1);
  printf(">The minimum symbols: %d, Word: %d\n", min,minIndx+1);
  return 0;
}

void scanWordForCheck(char* scanWord){

    printf(">Please insert word for scan\n" );
    char c = getchar();
    int count = 0;
    while ((count < 50) && (c != EOF)) {    /* don't go over the array size! */
        if (c == ' ' || c == '\n' || c == '\t' || c == '\0') { // we looking for a word!
          break;
        }
        scanWord[count] = c;
        ++count;
        c = getchar();
    }
}

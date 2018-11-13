#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int findPos(char* string,char character);

int main(){
  char data[70][70];
  int count;
  FILE *fp = fopen("input.bin","rb");
  if(fp == NULL) exit(1);
  char c;
  while(1){
    char buf[70];
    fread(buf,sizeof(buf),70,fp);
    /*if (strcmp(buf),"Type") {
      /
    }*/
    char key[20];
    int lastPos = findPos(buf, ':');
    printf("%d--\n",findPos(buf, ':'));
    for (int i = 0; i < lastPos; i++) {
      key[i] = buf[i];
      //printf("%c\n",buf[i]);
    } key[lastPos] = '\0';
    printf("%s\n",key);
    if (strcmp(key,"Type")) {
      int lastPos =findPos(buf, '}');
      int startPos =findPos(buf, '{');
      printf("%d--\n",findPos(buf, ':'));
      for (int i = startPos; i < lastPos-2; i++) {
        key[i] = buf[i];
        //printf("%c\n",buf[i]);
      } key[lastPos-1] = '\0';
      printf("@@%s@@\n", key);
    }else if (strcmp(key,"Source")) {
      /* code */
    }else if (strcmp(key,"Forecast")) {
      /* code */
    }
    //fwrite(buf,sizeof(char),c,fp);
    count++;
    break;
  }
  fclose(fp);
  return 0;
}
int findPos(char* string,char character){
  char *e;
  e = strchr(string, character);
  return (int)(e - string);
}

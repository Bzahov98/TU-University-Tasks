#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
  char data[50][50];
  FILE *fp = fopen("input.bin","wb");
  if(fp == NULL) exit(1);
  char c;
  while(1){
    char s[50] ;
    if(fgets(s,49,  stdin)== NULL) break;
    c= strlen(s);
    fwrite(&c,sizeof(char),1,fp);
  }
  return 0;
}

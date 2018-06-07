#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const char input[] = "newcomers.bin";
const char output[] = "newcomers.bin";

struct Animal{
  unsigned int id;
  double cage_size;
  unsigned int resp_size;
  char* resp_string;
  char animal[6];
};

unsigned int animal_typecnt(char AnimalType[], FILE* fd){
  Animal animal;
  int counter = 0;
  while(!feof(fd)){
      if(fread(&animal.id,sizeof(unsigned int),1,fd)!=EOF){}
      if(fread(&animal.cage_size,sizeof(double),1,fd)!=EOF){}
      if(fread(&animal.resp_size,sizeof(unsigned int),1,fd)!=EOF){}
      animal.resp_string = (char*)malloc(sizeof(char)*animal.resp_size);
      if(fread(animal.resp_string,sizeof(animal.resp_size),animal.resp_size,fd)!=EOF){}
      //animal.animal = (char*) malloc(sizeof(char)* 6);
      if(fread(animal.resp_string,sizeof(animal.animal)*6,animal.resp_size,fd)!=EOF){}
      if(strcmp(animal.animal, AnimalType)==0){
        counter++;
      }
  }
  return counter;
}

int fileopen(FILE* fd,const char* mode,const char* file_name){
  fd = fopen(file_name,mode);
  if (fd == NULL){
    perror("error file open");
    return 1;
  }
  return 0;
}
void deworming(float cageSize){
  FILE * fd_read;
  FILE * fd_write;
  fileopen(fd_read,"rb",input);
  fileopen(fd_write,"wb",output);
  Animal animal;
  while(!feof(fd_read)){
      if(fread(&animal.id,sizeof(unsigned int),1,fd_read)!=EOF){}
      if(fread(&animal.cage_size,sizeof(double),1,fd_read)!=EOF){}
      if(fread(&animal.resp_size,sizeof(unsigned int),1,fd_read)!=EOF){}
      animal.resp_string = (char*)malloc(sizeof(char)*animal.resp_size);
      if(fread(animal.resp_string,sizeof(animal.resp_size),animal.resp_size,fd_read)!=EOF){}
      //animal.animal = (char*) malloc(sizeof(char)* 6);
      if(fread(animal.resp_string,sizeof(animal.animal)*6,animal.resp_size,fd_read)!=EOF){}
      if(animal.cage_size >cageSize){
        fwrite()
      }
  }
}

int main(){
  FILE* fd = NULL;
  fileopen(fd,"rb",input);
  animal_typecnt("Dog",fd);
  deworming(1.3f);
  fclose(fd);
  return 0;
}

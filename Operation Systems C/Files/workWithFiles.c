#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv[]){
	int const size = 128;
	int fd1,fd2,fd3;
	char buf1[size],buf2[size],result[size*2];
	
	fd1 = open(argv[1], O_RDONLY | O_CREAT);
	if(fd1 == -1){
		perror("file cannot be opened");
		return 1;			
	}
	fd2 = open(argv[2], O_RDONLY | O_CREAT);
	if(fd2 == -1){
		perror("file cannot be opened1");
		return 1;			
	}
	fd3 = open(argv[3], O_WRONLY | O_CREAT);
	if(fd3 == -1){
		perror("file cannot be opened2");
		return 1;			
	}
	
	if(read(fd1, buf1, size)==-1){
		perror("file cannot be readed");
		return 1;				
	}else{
		printf("buf1 = %s\n", buf1);
	}
	
	if(read(fd2, buf2, size)==-1){
		perror("file cannot be readed");
		return 1;				
	}else{
		printf("buf2 = %s\n", buf2);
	}

	int i;
	for(i=0; i<strlen(buf1);i++){
		result[i] = buf1[i];	
	}
	printf("buf1 = %s\n", buf1);
	//int len = strlen(buf1) + strlen(buf2);
	//int len = 20;
	
	/*for(i=strlen(buf1); i<len;i++){
		result[i] = buf2[i];	
	}*/
	strcat(result, buf1);
	strcat(result, buf2);

	if(write(fd3, result,strlen(result))==-1){
		perror("file cannot be writed");
		return 1;				
	}else{
		printf("writed %s\n", result);
	}

	close(fd1);
	close(fd2);
	close(fd3);
	return 0;
}


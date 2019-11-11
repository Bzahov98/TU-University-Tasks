#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memory.h"
#define kB 1024
#define MB 1024*1024
#define GB 1024*1024*1024
typedef struct List
{
	int val;
	struct List* next;
}
List;

List* new_List(int val)
{
	List* result = userAllocation(sizeof(List));
	if (result != NULL)
	{
		result->val = val;
		result->next = NULL;
	}
	return result;
}

int main()
{
	List *root, *current;
	char* msg,*msg2;
	initFreeSpace(512*MB);

	printMemoryStatus();

	root = new_List(5);
	printMemoryStatus();
	
	current = new_List(5);
	printMemoryStatus();
	
	userFree(root);
	printMemoryStatus();
	msg = userAllocation(12000);
	//strcpy(msg, "HELLO WORLD!");
	printMemoryStatus();
	userFree(current);
	userFree(msg);
	printMemoryStatus();
	msg = userAllocation(10000);
	printMemoryStatus();
	cleanUpSpace();
	return 0;
}
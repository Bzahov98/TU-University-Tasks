/*
MEMORY ALLOCATION EXAMPLE
assist. prof. Boyan Petrov, (c)2014
Technical Univesity - Sofia
Faculty of Computer Systems and Control

v1.04
*/
#ifndef USER_MEMORY
#define USER_MEMORY
typedef struct MemoryItem
{
	unsigned int size;
	struct MemoryItem* nextItem;
	unsigned char allocated;
	//void* userData;
}
MemoryItem;
void initFreeSpace(	unsigned sizeInBytes);
void cleanUpSpace();
void* userAllocation(int sizeInBytes);
void defragmentMemory();
void userFree(void* userAllocation);
void printMemoryStatus();
#endif
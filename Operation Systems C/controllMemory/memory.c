#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

MemoryItem* memListRoot = NULL;


void initFreeSpace(unsigned sizeInBytes)
{
	memListRoot = calloc(1, sizeInBytes);
	if (memListRoot == NULL) return;
	memListRoot->size = sizeInBytes - sizeof(MemoryItem);
	memListRoot->allocated = 0;
	memListRoot->nextItem = NULL;
}
void cleanUpSpace()
{
	free(memListRoot);
	memListRoot = NULL;
}
void* userAllocation(int sizeInBytes)
{
	MemoryItem* currentItem = memListRoot;
	void* result = NULL;
	MemoryItem* tempItem;
	while (currentItem != NULL)
	{
		if (currentItem->allocated == 0)
			if(currentItem->size >= sizeInBytes + sizeof(MemoryItem))
			{
				tempItem = (MemoryItem*)((char*)currentItem + sizeInBytes + sizeof(MemoryItem));
				tempItem->allocated = 0;
				tempItem->size = currentItem->size - (sizeInBytes + sizeof(MemoryItem));
				tempItem->nextItem = currentItem->nextItem;

				result = (char*)currentItem + sizeof(MemoryItem);
				currentItem->size = sizeInBytes;
				currentItem->nextItem = tempItem;
				currentItem->allocated = 1;
				break;
			}
			else
				if (currentItem->size >= sizeInBytes)
				{
					result = (char*)currentItem + sizeof(MemoryItem);
					currentItem->allocated = 1;
					break;
				}

		currentItem = currentItem->nextItem;
	}
	return result;
}

void userFree(void* userAllocation)
{
	MemoryItem* userBlockMemory;
	char* tempPtr;
	if (userAllocation == NULL) return;
	userBlockMemory = (MemoryItem*)((char*)userAllocation - sizeof(MemoryItem));
	userBlockMemory->allocated = 0;
	defragmentMemory();
}
void defragmentMemory()
{
	MemoryItem* currentItem = memListRoot;
	while (currentItem != NULL)
	{
		if (currentItem->allocated == 0)
		{
			if (currentItem->nextItem != NULL)
			{
				if (currentItem->nextItem->allocated == 0)
				{
					currentItem->size = currentItem->size + sizeof(MemoryItem)+currentItem->nextItem->size;
					currentItem->nextItem = currentItem->nextItem->nextItem;
				}
				else
					currentItem = currentItem->nextItem;
			}
			else
				break;
		}
		else
			currentItem = currentItem->nextItem;
	}
}
void printMemoryStatus()
{
	MemoryItem* currentItem = memListRoot;
	printf("Begin list: \n");
	while (currentItem != NULL)
	{
		printf("%p: Size: %u, Allocated: %d\n", currentItem, currentItem->size, currentItem->allocated);
		currentItem = currentItem->nextItem;
	}
	printf("End list\n\n");
}





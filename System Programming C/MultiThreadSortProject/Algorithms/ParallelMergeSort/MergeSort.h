//
// Created by bzahov on 27.05.20 г..
//

#ifndef MULTYTHREADSORTPROJECT_MERGESORT_H
#define MULTYTHREADSORTPROJECT_MERGESORT_H

#include <iostream>
#include <pthread.h>
#include <ctime>
using namespace std;

class MergeSort {
private:
    //int *notSortedData;
    int *sortedData{};
    int part = 0;
    void merge(int low, int mid, int high);
    void mergeSort(int low, int high);
    void * mergeSortCallback();
    static  void* staticMergeSort(void *arg);
public:
    MergeSort(int* notSortedData){
        this->sortedData = notSortedData;
    }

    // array of size MAX
    static const int MAX = 20;
    static const int HALF_OF_MAX = MAX / 2;
    int initMergeSort();

};

#endif //MULTYTHREADSORTPROJECT_MERGESORT_H

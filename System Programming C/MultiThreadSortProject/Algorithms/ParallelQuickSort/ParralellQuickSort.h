//
// Created by bzahov on 31.05.20 г..
//

#ifndef MULTYTHREADSORTPROJECT_PARRALELLQUICKSORT_H
#define MULTYTHREADSORTPROJECT_PARRALELLQUICKSORT_H

#include <list>
#include <future>
#include <algorithm>
#include "../ParallelMergeSort/MergeSort.h"

using namespace std;

class ParallelQuickSort{
private:
template<typename T>
static list<T> parallel_quick_sort(list<T> input);

public:
    static list<int> initQuickSort(const int *data);

};
//template<typename T>
//list<T> parallel_quick_sort(T *date);
#endif //MULTYTHREADSORTPROJECT_PARRALELLQUICKSORT_H

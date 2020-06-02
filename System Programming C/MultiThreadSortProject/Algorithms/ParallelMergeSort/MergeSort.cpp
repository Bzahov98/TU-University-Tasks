//
// Created by bzahov on 27.05.20 г..
//
//
#include "MergeSort.h"

// number of threads
#define THREAD_MAX 4


void MergeSort::merge(int low, int mid, int high) {
    int *left = new int[mid - low + 1];
    int *right = new int[high - mid];

    // n1 is size of left part and n2 is size
    // of right part
    int n1 = mid - low + 1, n2 = high - mid, i, j;

    // storing values in left part
    for (i = 0; i < n1; i++)
        left[i] = MergeSort::sortedData[i + low];

    // storing values in right part
    for (i = 0; i < n2; i++)
        right[i] = sortedData[i + mid + 1];

    int k = low;
    i = j = 0;

    // merge left and right in ascending order
    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            sortedData[k++] = left[i++];
        else
            sortedData[k++] = right[j++];
    }

    // insert remaining values from left
    while (i < n1) {
        sortedData[k++] = left[i++];
    }

    // insert remaining values from right
    while (j < n2) {
        sortedData[k++] = right[j++];
    }
}

// merge sort function
void MergeSort::mergeSort(int low, int high) {
    // calculating mid point of array
    int mid = low + (high - low) / 2;
    if (low < high) {

        // calling first half
        mergeSort(low, mid);

        // calling second half
        mergeSort(mid + 1, high);

        // merging the two halves
        merge(low, mid, high);
    }
}

// thread function for multi-threading
void * MergeSort::mergeSortCallback() {
    // which part out of 4 parts
    int thread_part = part++;

    // calculating low and high
    int low = thread_part * (MergeSort::MAX / 4);
    int high = (thread_part + 1) * (MergeSort::MAX / 4) - 1;

    // evaluating mid point
    int mid = low + (high - low) / 2;
    if (low < high) {
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}

// merge function for merging two parts
int MergeSort::initMergeSort() {
    //sortedData = notSortedData;

    // t1 and t2 for calculating time for sorting
    clock_t t1, t2;

    t1 = clock();
    pthread_t threads[THREAD_MAX];

    // creating 4 threads
    for (unsigned long &thread : threads) {
        if (pthread_create(&thread, NULL, &MergeSort::staticMergeSort, this)) {
            cerr << "error in creating thread" << endl;
        }
    }
    // joining all 4 threads
    for (int i = 0; i < THREAD_MAX; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            cerr << "error from joining thread: " << i << endl;
        }
    }
    // merging the final 4 parts
    merge(0, (HALF_OF_MAX - 1) / 2, HALF_OF_MAX - 1);
    merge(HALF_OF_MAX, HALF_OF_MAX + (MAX - 1 - HALF_OF_MAX) / 2, MAX - 1);
    merge(0, (MAX - 1) / 2, MAX - 1);

    t2 = clock();

    // displaying sorted array

    cout << "\nMerge Sorted array:\n";
    for (int i = 0; i < MAX; i++)
        cout << sortedData[i] << " ";

    // time taken by merge sort in seconds
    cout << "Time taken: " << (t2 - t1) / (double) CLOCKS_PER_SEC << "(MERGE)" << endl;

    return 0;
}

void *MergeSort::staticMergeSort(void *arg) {
    return static_cast<void *>(((MergeSort *) arg)->mergeSortCallback());
}


// merge function for merging two parts


/*
// FOR DEBUG
int main() {

    cout << "Merge Not sorted array: ";
    int *notSortedData = new int[MAX];
    for (int i = 0; i < MAX; i++) {
        notSortedData[i] = rand() % 100;
        cout << notSortedData[i] << " ";
    }
    cout << endl;
    initMergeSort(notSortedData);
    return 0;
}
*/

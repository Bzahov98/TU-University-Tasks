//
// Created by bzahov on 31.05.20 г..
//


#include "ParralellQuickSort.h"

template<typename T>
list<T> ParallelQuickSort::parallel_quick_sort(list<T> input) {
    std::list<T> result;
    if (input.empty()) {
        return input;
    }


    result.splice(result.begin(), input, input.begin());
    T const &pivot = *result.begin();
    auto divide_point = partition(input.begin(), input.end(),
                                  [&](T const &t) { return t < pivot; });

    std::list<T> lower_part;
    lower_part.splice(lower_part.end(), input, input.begin(),
                      divide_point);

    future<std::list<T> > new_lower(
            async(&ParallelQuickSort::parallel_quick_sort<T>, std::move(lower_part)));

    auto new_higher(ParallelQuickSort::parallel_quick_sort(std::move(input)));
    result.splice(result.end(), new_higher);
    result.splice(result.begin(), new_lower.get());

    return result;
}
//
////template<typename T>
//list<int> testQuickSort(list<int> input) {
//    // t1 and t2 for calculating time for sorting
//    /* clock_t t1, t2;*/
//
//
//
//    if (input.empty()) {
//        return input;
//    }
//
//    //t1 = clock();
//    std::list<int> result;
//    result.splice(result.begin(), input, input.begin());
//    int const &pivot = *result.begin();
//    auto divide_point = partition(input.begin(), input.end(),
//                                  [&](int const &t) { return t < pivot; });
//    std::list<int> lower_part;
//    lower_part.splice(lower_part.end(), input, input.begin(),
//                      divide_point);
//    future<std::list<int> > new_lower(
//            async(&parallel_quick_sort<int>, std::move(lower_part)));
//    auto new_higher(
//            parallel_quick_sort(std::move(input)));
//    result.splice(result.end(), new_higher);
//    result.splice(result.begin(), new_lower.get());
//
//    /*t2 = clock();
//
//    cout << endl << "Result after QUICK sort:" << endl;
//    for (int numb: result) {
//        cout << numb << ",";
//    }
//    cout << "Time taken: " << (t2 - t1) / (double) CLOCKS_PER_SEC << "(Quick)" << endl;*/
//    return result;
//}
//


//template <typename IteratorType>
//void quicksort(IteratorType begin, IteratorType end)
//{
//    if (distance(begin, end) > 1)
//    {
//        const IteratorType pivot = partition(begin, end,true);
//
//        if (distance(begin, end) > 10000)
//        {
//            thread t1([&begin, &pivot](){ quicksort(begin, pivot); });
//            thread t2([&pivot, &end](){ quicksort(pivot + 1, end); });
//
//            t1.join();
//            t2.join();
//        }
//    }
//}

//template <typename IteratorType>
//void quicksort(IteratorType begin, IteratorType end, int depth)
//{
//    if (distance(begin, end) > 1)
//    {
//        const IteratorType pivot = partition(begin, end);
//
//        if (distance(begin, end) > 10000)
//        {
//            if (depth < 5) // <--- HERE
//            { // PARALLEL
//                thread t1([&begin, &pivot](){ quicksort(begin, pivot, 1); });
//                thread t2([&pivot, &end](){ quicksort(pivot + 1, end, 1); });
//
//                t1.join();
//                t2.join();
//            }
//            else
//            { // SEQUENTIAL
//                quicksort(begin, pivot, depth+1);
//                quicksort(pivot + 1, end, depth+1);
//            }
//        }
//    }
//}



list<int> ParallelQuickSort::initQuickSort(const int *data) {
    list<int> dataList;
    list<int> resultList;
    clock_t t1, t2;

    for (int i = 0; i < MergeSort::MergeSort::MAX; ++i) {
        //cerr << data[i] << ", ";
        dataList.push_front(data[i]);
    }
    cerr << endl;

    t1 = clock();
    resultList = parallel_quick_sort(dataList);
    t2 = clock();
    cout << endl << "Result after QUICK sort:" << endl;
    for (int numb: resultList) {
        cout << numb << ",";
    }
    cout << "Time taken: " << (t2 - t1) / (double) CLOCKS_PER_SEC << "(Quick)" << endl;
    return resultList;
}

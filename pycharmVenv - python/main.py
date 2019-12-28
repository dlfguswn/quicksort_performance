import sys
import time
import copy

import functions
import quicksort

if __name__ == '__main__':
    sys.setrecursionlimit(100000)
    array = functions.SortingFunctions(size=1000).array

    sortArr = copy.deepcopy(array)
    qsort = quicksort.Quicksort()
    st = time.time()
    sortArr = qsort.quicksort(array=sortArr, method=qsort.randomizedSortingAlg)
    ed = time.time()
    print("Randomized Quicksort ",ed-st)

    sortArr = copy.deepcopy(array)
    qsort = quicksort.Quicksort()
    st = time.time()
    sortArr = qsort.quicksort(array=sortArr, method=qsort.midOfThreeSortingAlg)
    ed = time.time()
    print("Mid of Three Quicksort ", ed - st)

    sortArr = copy.deepcopy(array)
    qsort = quicksort.Quicksort()
    st = time.time()
    sortArr = qsort.quicksort(array=sortArr, method=qsort.hybridSortingAlg)
    ed = time.time()
    print("Hybrid Quicksort ", ed - st)

    sortArr = copy.deepcopy(array)
    qsort = quicksort.Quicksort()
    st = time.time()
    sortArr = qsort.quicksort(array=sortArr, method=qsort.originalSortingAlg)
    ed = time.time()
    print("Original Quicksort ", ed - st)



import functions
import random

class Quicksort:
    def __init__(self):
        self.func = functions.SortingFunctions()

    def originalSortingAlg(self, array, firstIdx, lastIdx):
        left = firstIdx
        right = lastIdx
        if firstIdx >= lastIdx:
            return

        pivotIdx = firstIdx
        while (left < right):
            while (array[pivotIdx] > array[left]) and (left < lastIdx): left+=1
            while (array[pivotIdx] < array[right]) and (right > firstIdx): right-=1

            if left < right:
                array[left], array[right] = self.func.swap(array=array, srcIndex=left, dstIndex=right)
            else:
                array[pivotIdx], array[right] = self.func.swap(array=array, srcIndex=pivotIdx, dstIndex=right)

        self.originalSortingAlg(array=array, firstIdx=firstIdx, lastIdx=right-1)
        self.originalSortingAlg(array=array, firstIdx=right+1, lastIdx=lastIdx)

    def randomizedSortingAlg(self, array, firstIdx, lastIdx):
        left = firstIdx
        right = lastIdx
        if firstIdx >= lastIdx:
            return

        pivotIdx = random.randint(firstIdx, lastIdx)
        while (left < right):
            while (array[pivotIdx] > array[left]) and (left < lastIdx): left += 1
            while (array[pivotIdx] < array[right]) and (right > firstIdx): right -= 1

            if left < right:
                array[left], array[right] = self.func.swap(array=array, srcIndex=left, dstIndex=right)
            else:
                array[pivotIdx], array[right] = self.func.swap(array=array, srcIndex=pivotIdx, dstIndex=right)

        self.randomizedSortingAlg(array=array, firstIdx=firstIdx, lastIdx=right-1)
        self.randomizedSortingAlg(array=array, firstIdx=right+1, lastIdx=lastIdx)

    def midOfThreeSortingAlg(self, array, firstIdx, lastIdx):
        left = firstIdx
        right = lastIdx
        if firstIdx >= lastIdx:
            return

        pivotIdx = self.func.midOfSubArray(array=array, firstIdx=firstIdx, lastIdx=lastIdx)
        while (left < right):
            while (array[pivotIdx] > array[left]) and (left < lastIdx): left += 1
            while (array[pivotIdx] < array[right]) and (right > firstIdx): right -= 1

            if left < right:
                array[left], array[right] = self.func.swap(array=array, srcIndex=left, dstIndex=right)
            else:
                array[pivotIdx], array[right] = self.func.swap(array=array, srcIndex=pivotIdx, dstIndex=right)

        self.midOfThreeSortingAlg(array=array, firstIdx=firstIdx, lastIdx=right - 1)
        self.midOfThreeSortingAlg(array=array, firstIdx=right + 1, lastIdx=lastIdx)

    def hybridSortingAlg(self, array, firstIdx, lastIdx):
        left = firstIdx
        right = lastIdx
        if firstIdx >= lastIdx:
            return

        if (lastIdx-firstIdx > 40000):
            pivotIdx = self.func.midOfmidInSubArray(array=array, firstIdx=firstIdx, lastIdx=lastIdx)
        else:
            pivotIdx = random.randint(firstIdx, lastIdx)

        while (left < right):
            while (array[pivotIdx] > array[left]) and (left < lastIdx): left += 1
            while (array[pivotIdx] < array[right]) and (right > firstIdx): right -= 1

            if left < right:
                array[left], array[right] = self.func.swap(array=array, srcIndex=left, dstIndex=right)
            else:
                array[pivotIdx], array[right] = self.func.swap(array=array, srcIndex=pivotIdx, dstIndex=right)

        self.midOfThreeSortingAlg(array=array, firstIdx=firstIdx, lastIdx=right - 1)
        self.midOfThreeSortingAlg(array=array, firstIdx=right + 1, lastIdx=lastIdx)

    def quicksort(self, array, method):
        firstIdx = 0
        lastIdx = len(array)-1
        method(array, firstIdx, lastIdx)

        return array
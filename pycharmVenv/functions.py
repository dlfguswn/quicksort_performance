import random

class SortingFunctions:
    def __init__(self, size=None, fileReadFlag=None):
        if size == None:
            self.array = None
        else:
            if fileReadFlag == None:
                self.array = self.shuffle([elem for elem in range(1, size + 1)])
            else:
                print("Not Implemented")

    def swap(self, array, srcIndex, dstIndex):
        return array[dstIndex], array[srcIndex]

    def shuffle(self, array):
        length = len(array)
        cnt = 0
        while length > cnt:
            rn = random.randint(0, length-1)
            array[cnt], array[rn] = self.swap(array=array, srcIndex=cnt, dstIndex=rn)
            cnt+=1

        return array

    def midOfElem(self, elem1, elem2, elem3):
        ret = elem1 > elem2 and elem1 or elem2
        return ret < elem3 and ret or elem3

    def midOfSubArray(self, array, firstIdx, lastIdx):
        mid = int((firstIdx+lastIdx)/2)

        return self.midOfElem(elem1=array[firstIdx], elem2=array[mid], elem3=array[lastIdx])

    def midOfmidInSubArray(self, array, firstIdx, lastIdx):
        length = lastIdx-firstIdx
        std1 = int(length/3)
        std2 = int(length/3)*2+1

        mid1 = self.midOfSubArray(array=array, firstIdx=firstIdx, lastIdx=lastIdx)
        mid2 = self.midOfSubArray(array=array, firstIdx=std1+1, lastIdx=firstIdx+std2)
        mid3 = self.midOfSubArray(array=array, firstIdx=std2+1, lastIdx=lastIdx)

        return self.midOfElem(elem1=mid1, elem2=mid2, elem3=mid3)
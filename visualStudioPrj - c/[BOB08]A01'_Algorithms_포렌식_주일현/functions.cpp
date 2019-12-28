#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "sort.h"

void arrayCopy(int* src, int* dst, int length){
	for(int idx = 0; length > idx; idx++){
		dst[idx] = src[idx];
	}
}

void integerArrayPrint(int* arr, int length){
	for(int idx = 0; length > idx; idx++){
		printf("%d ", arr[idx]);
	}
	printf("\n");
}

void swap(int* arr, int indexOfLeftElem, int indexOfRightElem){
	int tmp = arr[indexOfLeftElem];
	arr[indexOfLeftElem] = arr[indexOfRightElem];
	arr[indexOfRightElem] = tmp;
}

void shuffle(int *arr, int length) { 
	srand(time(NULL)); 
	int rn; 
	for (int i=0; i < length-1; i++) { 
		rn = rand() % (length - i) + i; // i 부터 num-1 사이에 임의의 정수 생성
		swap(arr, i, rn);
	} 
}

int midOfArray(int* arr, int firstIdx, int lastIdx){
	int mid = (firstIdx+lastIdx)/2;
	int ret = arr[firstIdx] > arr[mid] ? arr[firstIdx] : arr[mid];
	ret = ret < arr[lastIdx] ? ret : arr[lastIdx];

	return ret;
}

int midOfmidInSubArray(int* arr, int firstIdx, int lastIdx){
	int length = lastIdx - firstIdx;
	int std_1 = length/3;
	int std_2 = (length/3)*2+1;

	int mid1 = midOfArray(arr, firstIdx, firstIdx+std_1);
	int mid2 = midOfArray(arr, firstIdx+std_1+1, firstIdx+std_2);
	int mid3 = midOfArray(arr, firstIdx+std_2+1, lastIdx);

	int ret = mid1 > mid2 ? mid1 : mid2;
	ret = ret < mid3 ? ret : mid3;

	return ret;
}
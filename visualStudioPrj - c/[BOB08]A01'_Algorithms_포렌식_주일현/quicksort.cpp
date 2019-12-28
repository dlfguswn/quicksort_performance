#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void sortingAlg(int* arr, int firstIdx, int lastIdx){
	int pivotIdx = firstIdx;
	int left = firstIdx+1;
	int right = lastIdx;

	if (firstIdx >= lastIdx){
		return;
	}

	while (left < right){
		while (arr[pivotIdx] > arr[left] && left < lastIdx){ left++; }
		while (arr[pivotIdx] < arr[right] && right > firstIdx){ right--; }
		if(left < right){
			swap(arr, left, right);
		}
		else{
			swap(arr, pivotIdx, right);
		}
	}
	sortingAlg(arr, firstIdx, right-1);
	sortingAlg(arr, right+1, lastIdx);
}

int* quicksort(int* arr, int length){
	int firstIdx = 0;
	int lastIdx = length-1;
	sortingAlg(arr, firstIdx, lastIdx);

	return arr;
}

void sortingAlg_cust(int* arr, int firstIdx, int lastIdx){
	int left = firstIdx;
	int right = lastIdx;
	int pivotIdx = 0;
	if (firstIdx >= lastIdx){
		return;
	}

	if ((lastIdx-firstIdx) < 40000){
		pivotIdx = (rand()%(lastIdx-firstIdx))+firstIdx;
	}
	else{
		pivotIdx = midOfmidInSubArray(arr, firstIdx, lastIdx);
	}

	while (left < right){
		while (arr[pivotIdx] > arr[left] && left < lastIdx){ left++; }
		while (arr[pivotIdx] < arr[right] && right > firstIdx){ right--; }
		if(left < right){
			swap(arr, left, right);
		}
		else{
			swap(arr, pivotIdx, right);
		}
	}
	sortingAlg_cust(arr, firstIdx, right-1);
	sortingAlg_cust(arr, right+1, lastIdx);
}

int* HybridQuicksort(int* arr, int length){
	int firstIdx = 0;
	int lastIdx = length-1;
	sortingAlg_cust(arr, firstIdx, lastIdx);

	return arr;
}

void sortingAlg_rand(int* arr, int firstIdx, int lastIdx){
	int left = firstIdx;
	int right = lastIdx;

	if (firstIdx >= lastIdx){
		return;
	}

	int pivotIdx = (rand()%(lastIdx-firstIdx))+firstIdx;

	while (left < right){
		while (arr[pivotIdx] > arr[left] && left < lastIdx){ left++; }
		while (arr[pivotIdx] < arr[right] && right > firstIdx){ right--; }
		if(left < right){
			swap(arr, left, right);
		}
		else{
			swap(arr, pivotIdx, right);
		}
	}
	sortingAlg_rand(arr, firstIdx, right-1);
	sortingAlg_rand(arr, right+1, lastIdx);
}

int* randomizedQuicksort(int* arr, int length){
	int firstIdx = 0;
	int lastIdx = length-1;
	sortingAlg_rand(arr, firstIdx, lastIdx);

	return arr;
}

void sortingAlg_midOfThree(int* arr, int firstIdx, int lastIdx){
	int left = firstIdx;
	int mid = (firstIdx+lastIdx)/2;
	int right = lastIdx;

	if (firstIdx >= lastIdx){
		return;
	}

	int pivotIdx = arr[firstIdx] > arr[mid] ? firstIdx : mid;
	pivotIdx = arr[pivotIdx] < arr[lastIdx] ? pivotIdx : lastIdx;

	while (left < right){
		while (arr[pivotIdx] > arr[left] && left < lastIdx){ left++; }
		while (arr[pivotIdx] < arr[right] && right > firstIdx){ right--; }
		if(left < right){
			swap(arr, left, right);
		}
		else{
			swap(arr, pivotIdx, right);
		}
	}
	sortingAlg_rand(arr, firstIdx, right-1);
	sortingAlg_rand(arr, right+1, lastIdx);
}

int* midOfThreeQuicksort(int* arr, int length){
	int firstIdx = 0;
	int lastIdx = length-1;
	sortingAlg_midOfThree(arr, firstIdx, lastIdx);

	return arr;
}
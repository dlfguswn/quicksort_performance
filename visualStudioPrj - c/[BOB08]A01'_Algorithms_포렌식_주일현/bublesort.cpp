#include "functions.h"

int* bubblesort(int* arr, int length){
	for(int idx = 0; length > idx; idx++){
		for(int jdx = idx+1; length > jdx; jdx++){
			if(arr[idx] > arr[jdx]){
				swap(arr, idx, jdx);
			}
		}
	}

	return arr;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#include "sort.h"

int main(){
	clock_t start, end;
	float res;
	float sum = 0.0;

	int length = 200000;
	int* arr = (int*)calloc(length, sizeof(int));
	int* sortTest = (int*)calloc(length, sizeof(int));
	
	for(int idx = 0; length > idx; idx++){ arr[idx] = idx+1; } // array init
	
	for(int cnt = 0; 1000 > cnt; cnt++){
		shuffle(arr, length);
		arrayCopy(arr, sortTest, length);;
		start = clock();
		quicksort(sortTest, length);
		end = clock();
		res = (float)(end - start)/CLOCKS_PER_SEC;
		sum+=res;
	}
	printf("Original Quicksort : %.6f\n",sum/1000);
	
	sum = 0.0;
	for(int cnt = 0; 1000 > cnt; cnt++){
		shuffle(arr, length);
		arrayCopy(arr, sortTest, length);
		start = clock();
		randomizedQuicksort(sortTest, length);
		end = clock();
		res = (float)(end - start)/CLOCKS_PER_SEC;
		sum+=res;
	}
	printf("Randomized Quicksort : %.6f\n",sum/1000);

	sum = 0.0;
	for(int cnt = 0; 1000 > cnt; cnt++){
		shuffle(arr, length);
		arrayCopy(arr, sortTest, length);
		start = clock();
		midOfThreeQuicksort(sortTest, length);
		end = clock();
		res = (float)(end - start)/CLOCKS_PER_SEC;
		sum+=res;
	}
	printf("Mid-of Three Quicksort : %.6f\n",sum/1000);
	
	sum=0.0;
	for(int cnt = 0; 1000 > cnt; cnt++){
		shuffle(arr, length);
		arrayCopy(arr, sortTest, length);
		start = clock();
		HybridQuicksort(sortTest, length);
		end = clock();
		res = (float)(end - start)/CLOCKS_PER_SEC;
		sum+=res;
	}
	printf("Hybrid Quicksort : %.6f\n",sum/1000);
}
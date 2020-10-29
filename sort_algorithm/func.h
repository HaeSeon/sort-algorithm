#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>​
#include <time.h>

int merge_count;
int insertion_count;
int heap_sort_count;
int quick_sort_count;

int* generateRandomArray(int data[], int length, int range);
void swap(int* aa, int* bb);
void checkTime(void (*func)(int*, int), int array[], int length);

void insertionSort(int array[], int length);

void merge(int array[], int p, int q, int r);
void mergeSortFunc(int array[], int p, int r);
//inline 함수는 header 파일에 전체 코드 포함되어있어야함. 
inline void mergeSort(int array[], int length) {
	mergeSortFunc(array, 0, length - 1);
}

void maxHeapify(int* array, int heapsize, int parent);
void buiildMaxHeap(int* array, int heapsize);
void heapSort(int* array, int heapsize);

void quickSortFunc(int (*partition)(int*, int, int), int array[], int p, int r);

//last element as pivot
int partitionV1(int array[], int p, int r);
inline void quickSortV1(int array[], int length) {
	quickSortFunc(partitionV1,array, 0, length - 1);
}

int generateRandomNum(int length);

//random number as pivot
int partitionV2(int array[], int p, int r);
inline void quickSortV2(int array[], int length) {
	quickSortFunc(partitionV2, array, 0, length - 1);
}

//median of three partitioning as pivot
int partitionV3(int array[], int p, int r);
inline void quickSortV3(int array[], int length) {
	quickSortFunc(partitionV3, array, 0, length - 1);
}

//랜덤하게 3개의 값을 뽑은 후 중간값을 pivot으로 결정
int partitionV4(int array[], int p, int r);
inline void quickSortV4(int array[], int length) {
	quickSortFunc(partitionV4, array, 0, length - 1);
}


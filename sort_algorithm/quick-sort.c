#include<time.h>

quick_sort_count = 0;

void quickSortFunc(int (*partition)(int*,int,int),int array[], int p, int r) {
	if (p < r) {
		int q = partition(array, p, r);
		quickSortFunc(partition,array, p, q - 1);
		quickSortFunc(partition,array, q + 1, r);
		quick_sort_count++;
	}
	else {
		return;
	}
}


//last element as pivot
int partitionV1(int array[], int p, int r) {
	int pivot = array[r];
	int i;
	int q = p;
	for (i = p; i < r; i++) {
		if (array[i] <= pivot) {
			swap(&array[i], &array[q]);
			q++;
			quick_sort_count++;
		}
	}
	swap(&array[r], &array[q]);
	return q;
}


//random number as pivot
int partitionV2(int array[], int p, int r) {
	//srand(time(NULL));
	//int num = p + (rand() % (r - p + 1));    //배열 크기보다 작게 랜덤피벗 설정(use built in function)
	int num = p+generateRandomNum(r-p+1);		//배열 크기보다 작게 랜덤피벗 설정(use generateRandNum)
	//printf("%d\n",num);
	swap(&array[num], &array[r]);
	int pivot = array[r];
	int i;
	int q = p;

	for (i = p; i < r; i++) {
		if (array[i] <= pivot) {
			swap(&array[i], &array[q]);
			q++;
			quick_sort_count++;
		}
	}
	swap(&array[r], &array[q]);

	return q;
}

//median of three partitioning as pivot
int partitionV3(int array[], int p, int r) {
	int mid = p + (r - p) / 2;
	int i;
	int q = p;

	//첫번째, 가운데, 마지막 요소중 중간값을 피벗으로 결정
	if (array[p] > array[mid]) {
		swap(&array[p], &array[mid]);
		quick_sort_count++;
	}
	if (array[mid] > array[r]) {
		swap(&array[mid], &array[r]);
		quick_sort_count++;
	}
	if (array[p] > array[mid]) {
		swap(&array[p], &array[mid]);
		quick_sort_count++;
	}
	swap(&array[mid], &array[r]);
	int pivot = array[r];



	for (i = p; i < r; i++) {
		if (array[i] <= pivot) {
			swap(&array[i], &array[q]);
			q++;
			quick_sort_count++;
		}
	}
	swap(&array[r], &array[q]);

	return q;

}

//pick three random number, then select median value
int partitionV4(int array[], int p, int r) {
	int i;
	int q = p;

	//랜덤하게 3개의 배열값을 선택
	srand(time(NULL));
	int num1 = p + (rand() % (r - p + 1));
	int num2 = p + (rand() % (r - p + 1));
	int num3 = p + (rand() % (r - p + 1));
	//printf("pivot : %d ,%d  ,%d  \n",num1,num2,num3);

	//랜덤하게 뽑은 세 배열값의 중간값을 피벗으로 결정
	if (array[num1] > array[num2]) {
		swap(&array[num1], &array[num2]);
		quick_sort_count++;
	}
	if (array[num2] > array[num3]) {
		swap(&array[num2], &array[num3]);
		quick_sort_count++;
	}
	if (array[num1] > array[num2]) {
		swap(&array[num1], &array[num2]);
		quick_sort_count++;
	}
	swap(&array[num2], &array[r]);
	int pivot = array[r];

	for (i = p; i < r; i++) {
		if (array[i] <= pivot) {
			swap(&array[i], &array[q]);
			q++;
			quick_sort_count++;
		}
	}
	swap(&array[r], &array[q]);
	return q;
}
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



int partitionV2(int array[], int p, int r) {
	srand(time(NULL));
	//int num = p + (rand() % (r - p + 1));    //�迭 ũ�⺸�� �۰� �����ǹ� ����
	int num = generateRandomNum(r-p+1);		//�迭 ũ�⺸�� �۰� �����ǹ� ����
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

int partitionV3(int array[], int p, int r) {
	int mid = p + (r - p) / 2;
	int i;
	int q = p;

	//ù��°, ���, ������ ����� �߰����� �ǹ����� ����
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


int partitionV4(int array[], int p, int r) {
	int i;
	int q = p;

	//�����ϰ� 3���� �迭���� ����
	srand(time(NULL));
	int num1 = p + (rand() % (r - p + 1));
	int num2 = p + (rand() % (r - p + 1));
	int num3 = p + (rand() % (r - p + 1));

	//�����ϰ� ���� �� �迭���� �߰����� �ǹ����� ����
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
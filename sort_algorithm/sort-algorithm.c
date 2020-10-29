#include "func.h"

//for select pivot randomly
int generateRandomNum(int length) {
	struct timeb cur_time;
	ftime(&cur_time);

	char* p;
	p = (char*)malloc(sizeof(char));

	int random_num = (int)p + 1;
	random_num = (int)(random_num * cur_time.millitm * 0.0001234) % length;
	if (random_num < 0) {
		random_num = random_num * (-1);
	}
	return random_num;
}

//millisecond와 메모리 주소를 이용하여 난수배열 생성
//data: 배열, length: 배열 길이, range: 난수 범위
int* generateRandomArray(int data[], int length, int range) {
	
	struct timeb cur_time;
	ftime(&cur_time);
	
	//int distribution[500] = { 0 };	//난수 분포도 확인
	for (int i = 0; i < length; i++)
	{
		char* p;
		p = (char*)malloc(sizeof(char)); 

		int random_num = (int)p + 1;  
		random_num = (int)(random_num * cur_time.millitm * 0.0001234) % range;
		if (random_num < 0) {
			random_num = random_num * (-1);
		}
		//distribution[random_num] = distribution[random_num] + 1;
		//printf("%d\n", random_num);
		data[i] = random_num;
	}

	//분포도 확인
	for (int i = 0; i < range; i++) {
		//printf("%d : %d\n", i, distribution[i]);
	}

	//난수로 생성된 배열 확인
	for (int i = 0; i < length; i++) {
		//printf("%d : %d\n", i, data[i]);
	}
	return data;
}


//swap the value of an array
void swap(int* aa, int* bb) {
	int temp = *aa;
	*aa = *bb;
	*bb = temp;
}

//estimate time while the function is running
float checkTime(void (*func)(int*,int),int array[],int length) {
	clock_t start, end;
	float times;

	start = clock();
	func(array,length);
	end = clock();
	times = (double)(end - start)/ CLOCKS_PER_SEC;
	printf("실행시간 : %f sec\n", times);

	return times;
}


void writefile(int length) {
	//write outputfile
	FILE* fp = NULL;
	fopen_s(&fp, "C:\\Users\\gildo\\Develop\\sort_algorithm\\outputfile.txt", "w");
	if (fp == NULL) {
		fprintf(stderr, "Can not write file.\n");
		return -1;
	}
	fprintf(fp, "Sort type             clock time       comparision\n");

	int temp_arr[10000] = {0};
	int resultarray[10000] = {0};
	
	*temp_arr = *generateRandomArray(temp_arr, length, length);

	printf("original array is : \n");
	for (int i = 0; i < length; i++) {
		//4printf("%d: %d\n", i, temp_arr[i]);
		resultarray[i] = temp_arr[i];
	}

	printf("\n");

	


	fprintf(fp, "Insertion Sort  %15f  ", checkTime(insertionSort, temp_arr, length));
	fprintf(fp, "%15ld\n", insertion_count);

	fprintf(fp, "Merge Sort      %15f  ", checkTime(mergeSort, temp_arr, length));
	fprintf(fp, "%15d\n", merge_count);

	for (int i = 0; i < length; i++) {
		temp_arr[i] = resultarray[i];
	}
	fprintf(fp, "Heap Sort       %15f  ", checkTime(heapSort, temp_arr, length));
	fprintf(fp, "%15d\n", heap_sort_count);

	for (int i = 0; i < length; i++) {
		temp_arr[i] = resultarray[i];
	}
	fprintf(fp, "Quick Sort V1   %15f  ", checkTime(quickSortV1, temp_arr, length));
	fprintf(fp, "%15d\n", quick_sort_count);

	for (int i = 0; i < length; i++) {
		temp_arr[i] = resultarray[i];
	}
	quick_sort_count = 0;
	fprintf(fp, "Quick Sort V2   %15f  ", checkTime(quickSortV2, temp_arr, length));
	fprintf(fp, "%15d\n", quick_sort_count);

	for (int i = 0; i < length; i++) {
		temp_arr[i] = resultarray[i];
	}
	quick_sort_count = 0;
	fprintf(fp, "Quick Sort V3   %15f  ", checkTime(quickSortV3, temp_arr, length));
	fprintf(fp, "%15d\n", quick_sort_count);

	for (int i = 0; i < length; i++) {
		temp_arr[i] = resultarray[i];
	}
	quick_sort_count = 0;
	fprintf(fp, "Quick Sort V4   %15f  ", checkTime(quickSortV4, temp_arr, length));
	fprintf(fp, "%15d\n", quick_sort_count);

	fclose(fp);
}


int main(){

	writefile(10000);

	//generateRandomArray(a, 10240,10240);
	//printf("original array : ");
	for (int i = 0; i < 1024; i++) {
		//printf("%d ", a[i]);
	}
	//printf("<Insertion Sort>");
	//checkTime(insertionSort,a,10240);
	//printf("%d", insertion_count);

	//printf("<Merge Sort>");
	//checkTime(mergeSort, a, 1024);
	//printf("%d", merge_count);

	//printf("<Heap Sort>");
	//checkTime(heapSort, a, 10240);

	//printf("<Quick Sort version1>");
	//checkTime(quickSortV1, a, 10240);
	//printf("%d", quick_sort_count);

	//printf("<Quick Sort version2>");
	//checkTime(quickSortV2, a, 10240);

	//printf("<Quick Sort version3>");
	//checkTime(quickSortV3, a, 10240);
	//printf("%d", quick_sort_count);

	//printf("<Quick Sort version4>");
	//checkTime(quickSortV4, a, 10240);

	//printf("\nsorted array : ");
	for (int i = 0; i < 1024; i++) {
		//printf("%d ", a[i]);
	}
	return 0;
}
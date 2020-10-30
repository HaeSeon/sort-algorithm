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
	fopen_s(&fp, "C:\\Users\\gildo\\Develop\\sort_algorithm\\outputfile1.txt", "w");
	if (fp == NULL) {
		fprintf(stderr, "Can not write file.\n");
		return -1;
	}
	
	int temp_arr[1024] = {0};
	int resultarray[1024] = {0};
	*temp_arr = *generateRandomArray(temp_arr, length, length);

	//정렬 결과 검증
	fprintf(fp,"random array is \n");
	for (int i = 0; i < length; i++) {
		fprintf(fp,"%d ", temp_arr[i]);
		resultarray[i] = temp_arr[i];	//모든 정렬함수가 같은 randomdata에 대해 작동하기 위하여. 
	}
	fprintf(fp,"\n\n");
	//Insertion 결과
	checkTime(insertionSort, temp_arr, length);
	fprintf(fp,"<after sorting with insertion-sort is> \n");
	for (int i = 0; i < length; i++) {
		fprintf(fp,"%d ", temp_arr[i]);
	}
	fprintf(fp,"\n\n");
	//Merge 결과
	for (int i = 0; i < length; i++) {
		temp_arr[i] = resultarray[i];
	}
	checkTime(mergeSort, temp_arr, length);
	fprintf(fp, "<after sorting with merge-sort is> \n");
	for (int i = 0; i < length; i++) {
		fprintf(fp, "%d ", temp_arr[i]);
	}
	fprintf(fp, "\n\n");
	//Heap 결과
	for (int i = 0; i < length; i++) {
		temp_arr[i] = resultarray[i];
		//printf("%d ", temp_arr[i]);
	}
	checkTime(heapSort, temp_arr, length);
	fprintf(fp, "<after sorting with heap-sort is> \n");
	for (int i = 0; i < length; i++) {
		fprintf(fp, "%d ", temp_arr[i]);
	}
	fprintf(fp, "\n\n");
	//Quick_V1 결과
	for (int i = 0; i < length; i++) {
		temp_arr[i] = resultarray[i];
	}
	checkTime(quickSortV1, temp_arr, length);
	fprintf(fp, "<after sorting with quick-sort-v1 is> \n");
	for (int i = 0; i < length; i++) {
		fprintf(fp, "%d ", temp_arr[i]);
	}
	fprintf(fp, "\n\n");
	//Quick_V2 결과
	for (int i = 0; i < length; i++) {
		temp_arr[i] = resultarray[i];
	}
	checkTime(quickSortV2, temp_arr, length);
	fprintf(fp, "<after sorting with quick-sort-v2 is> \n");
	for (int i = 0; i < length; i++) {
		fprintf(fp, "%d ", temp_arr[i]);
	}
	fprintf(fp, "\n\n");
	//Quick_V3 결과
	for (int i = 0; i < length; i++) {
		temp_arr[i] = resultarray[i];
	}
	checkTime(quickSortV3, temp_arr, length);
	fprintf(fp, "<after sorting with quick-sort-v3 is> \n");
	for (int i = 0; i < length; i++) {
		fprintf(fp, "%d ", temp_arr[i]);
	}
	fprintf(fp, "\n\n");
	//Quick_V4 결과
	for (int i = 0; i < length; i++) {
		temp_arr[i] = resultarray[i];
	}
	checkTime(quickSortV4, temp_arr, length);
	fprintf(fp, "<after sorting with quick-sort-v4 is> \n");
	for (int i = 0; i < length; i++) {
		fprintf(fp, "%d ", temp_arr[i]);
	}
	fprintf(fp, "\n\n\n");


	fprintf(fp, "<<sorted array (size : 1024)>>\n");
	//성능 측정 및 비교 (measure time and comparision)
	fprintf(fp, "Sort type             clock time       comparision\n");

	for (int i = 0; i < length; i++) {
		temp_arr[i] = resultarray[i];
	}
	fprintf(fp, "Insertion Sort  %15f  ", checkTime(insertionSort, temp_arr, length));
	fprintf(fp, "%15ld\n", insertion_count);

	for (int i = 0; i < length; i++) {
		temp_arr[i] = resultarray[i];
	}
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

	fprintf(fp,"\n");

	fclose(fp);
}


int main(){

	//writefile(32);
	writefile(1024);
	//writefile(10000);
	return 0;
}
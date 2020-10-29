heap_sort_count = 0;

void maxHeapify(int* array, int heapsize, int parent) {
	int largest = parent;
	int left = 2 * parent + 1;  //루트노드를 0으로했기때문
	int right = 2 * parent + 2;

	if (left < heapsize && array[left] > array[largest]) {
		largest = left;
		heap_sort_count++;
	}

	if (right < heapsize && array[right] > array[largest]) {
		largest = right;
		heap_sort_count++;
	}

	if (largest != parent) {
		swap(&array[parent], &array[largest]);
		maxHeapify(array, heapsize, largest);
		heap_sort_count++;
	}

}

void buiildMaxHeap(int* array, int heapsize) {
	int mid = heapsize / 2 - 1;
	for (int i = mid; i >= 0; i--) {
		maxHeapify(array, heapsize, i);
	}

}

void heapSort(int* array, int heapsize) {
	buiildMaxHeap(array, heapsize);
	while (heapsize > 1) {
		swap(&array[0], &array[heapsize - 1]);
		heapsize--;
		maxHeapify(array, heapsize, 0);
		heap_sort_count++;
	}
}

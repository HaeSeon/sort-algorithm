insertion_count = 0;

void insertionSort(int array[], int length) {
	int i, j, key;
	i = 0;
	for (j = 1; j < length; j++) {
		key = array[j];
		i = j - 1;
		insertion_count++;
		while (i >= 0 && array[i] > key) {
			array[i + 1] = array[i];
			i = i - 1;
			insertion_count++;
		}
		array[i + 1] = key;
	}
}
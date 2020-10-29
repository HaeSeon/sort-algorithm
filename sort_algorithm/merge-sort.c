merge_count = 0;

void merge(int array[], int p, int q, int r) {
	int i, j, k;
	int resultarray[10000] = { 0 };
	i = p;
	j = q + 1;
	k = p;

	while (i <= q && j <= r) {
		if (array[i] < array[j]) {
			resultarray[k] = array[i];
			k++;
			i++;
			merge_count++;
		}
		else {
			resultarray[k] = array[j];
			j++;
			k++;
			merge_count++;
		}
	}
	while (i <= q) {
		resultarray[k] = array[i];
		k++;
		i++;
		merge_count++;
	}
	while (j <= r) {
		resultarray[k] = array[j];
		j++;
		k++;
		merge_count++;
	}
	k--;
	for (i = p; i <= r; i++) {
		array[i] = resultarray[i];
	}
}


void mergeSortFunc(int array[], int p, int r) {
	if (p < r) {
		int q = p + (r - p) / 2;
		mergeSortFunc(array, p, q);
		mergeSortFunc(array, q + 1, r);
		merge(array, p, q, r);
		merge_count++;
	}
}



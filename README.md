# sort-algorithm

insertion, merge, heap, quick sort

1. 파일 구성

   - func.h

     전처리를 위한 헤더파일. 효율적인 코드를 위해 코드분할을 하였다.

   - insertion-sort.c
   - merge-sort.c
   - heap-sort.c
   - quick-sort.c
     - V1: last element as pivot
     - V2: random number as pivot
     - V3: median of three partitioning as pivot
     - V4: pick three random number, then select median value
   - sort-algorithm.c

     main함수가 들어있는 파일로 random array 생성, output 파일쓰기 등 수행

2. insertion-sort.c

   - insertion_count
     - type: int
     - comparison 횟수를 카운트하는 변수
   - insertionSort (int array[], int length)
     - array : input 배열
     - length : input 배열 길이
     - 삽입정렬을 수행하는 함수이다.

3. merge-sort.c

   - merge_count
     - type: int
     - comparison 횟수를 카운트하는 변수
   - merge (int array[], int p, int q, int r)
     - array : input 배열
     - p : 정렬된 왼쪽 배열 인덱스
     - q+1 : 정렬된 오른쪽 배열 인덱스
     - r : 합쳐지는 배열 인덱스
     - resultarray[] : merge sort는 정렬할 때 추가적인 공간이 필요하다. (not in place)
     - 정렬된 2개의 배열의combine을 수행하는 함수이다.
   - mergeSort(int array[], int p, int r)
     - array : input 배열
     - p : 첫번째 인덱스
     - r : 마지막 인덱스
     - merge sort를 수행하는 함수

   ```
   if (p < r) {
      	int q = p + (r - p) / 2;		//divide
       mergeSortFunc(array, p, q);		//conquer
       mergeSortFunc(array, q + 1, r);	//conquer
       merge(array, p, q, r);			//combine
      }
   ```

   - mergeSortFunc : inline function으로 mergeSort가 들어있으며, func.h에 정의되어있다.

4. heap-sort.c

   - heap_count
     - type: int
     - comparison 횟수를 카운트하는 변수
   - maxHeapify(int\* array, int heapsize, int parent)
     - array : input 배열
     - heapsize : 힙 크기
     - parent : parent node
     - 최대힙을 만들기 위해 특정 노드를 중심으로 이 밑의 트리가 힙 성질을 만족하게 만든다.
   - buiildMaxHeap(int\* array, int heapsize)
     - array : input 배열
     - heapsize : 힙 크기
     - 최대힙을 만드는 함수
   - heapSort(int\* array, int heapsize)
     - array : input 배열
     - heapsize : 힙 크기(배열 크기)
     - heapsize가 1이 될 때 까지 위의 함수들을 반복 호출하는 함수.

5. quick-sort.c

   - quick_sort_count
     - type: int
     - comparison 횟수를 카운트하는 변수
   - quickSortFunc(int (_partition)(int_,int,int),int array[], int p, int r)
     - \*partition() : 아래의 partition함수들을 인자로 받는다.
     - array : input 배열
     - p : 배열의 처음 요소를 가리킴
     - r : 배열의 마지막 요소를 가리킴
     - quickSort를 수행한다.

   ```
   if (p < r) {
       int q = partition(array, p, r); //divide
       quickSortFunc(partition,array, p, q - 1); //conquer
       quickSortFunc(partition,array, q + 1, r); //conquer
   }
   ```

   - partitionV1(int array[], int p, int r)
     - array : input 배열
     - p : 배열의 처음 요소를 가리킴
     - r : 배열의 마지막 요소를 가리킴
     - 가장 왼쪽에 있는 element를 pivot으로 정하는 함수
   - partitionV2(int array[], int p, int r)
     - array : input 배열
     - p : 배열의 처음 요소를 가리킴
     - r : 배열의 마지막 요소를 가리킴
     - 랜덤으로 pivot으로 정하는 함수
   - partitionV3(int array[], int p, int r)
     - array : input 배열
     - p : 배열의 처음 요소를 가리킴
     - r : 배열의 마지막 요소를 가리킴
     - 처음, 중간 끝 요소중 중간값을 pivot으로 정하는 함수
   - partitionV4(int array[], int p, int r)
     - array : input 배열
     - p : 배열의 처음 요소를 가리킴
     - r : 배열의 마지막 요소를 가리킴
     - 세가지 요소를 랜덤으로 뽑아 그 중 중간값을 pivot으로 정하는 함수

6. sort-algorithm.c

   - generateRandomNum(int length)
     - length : 랜덤 값을 만들고 싶은 범위(길이)
     - int 형의 random_num을 return 한다.
     - quickSortV2의 pivot을 랜덤으로 결정할 때 사용한다.
   - generateRandomArray(int data[], int length, int range)
     - data : 랜덤 값들이 들어갈 배열
     - length : 배열 길이
     - range : 난수 범위
     - millisecond와 메모리 주소를 이용하여 난수배열 생성
     - 함수 성능의 정확도와 검증 결과는 lesson-learned-from-programming-assignment.doc 에 설명
     - 난수 배열 data를 return 한다.
   - swap(int* aa, int* bb)
     - 배열의 두 값을 바꿔주는 함수
   - checkTime(void (_func)(int_,int),int array[],int length) \* (\*func)(): 수행 시간을 측정하고싶은 함수
     - array: func함수에 수행시킬 배열
     - length: func 함수에 수행시킬 배열의 길이
     - 함수의 수행시간을 측정해주는 함수
     - 수행시간 times를 return 한다.
   - writefile(int length)
     - length : 배열 길이
     - output file작성을 효율적으로 하기 위한 함수
   - main()
     - 메인 함수

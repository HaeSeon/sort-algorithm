#include<stdio.h>
#include<stdlib.h>
#include <sys/timeb.h>​

//millisecond와 메모리 주소를 이용하여 난수배열 생성
//data: 배열, length: 배열 길이, range: 난수 범위
int generate_random_array(int data[], int length, int range) {
	
	struct timeb cur_time;
	ftime(&cur_time);
	int distribution[500] = { 0 };	//난수 분포도 확인
	for (int i = 0; i < length; i++)
	{
		char* p;
		p = (char*)malloc(sizeof(char)); 

		int random_num = (int)p + 1;  
		random_num = (int)(random_num * cur_time.millitm * 0.0001234) % range;
		if (random_num < 0) {
			random_num = random_num * (-1);
		}
		distribution[random_num] = distribution[random_num] + 1;
		//printf("%d\n", random_num);
		data[i] = random_num;
	}

	//분포도 확인
	for (int i = 0; i < range; i++) {
		printf("%d : %d\n", i, distribution[i]);
	}

	//난수로 생성된 배열 확인
	for (int i = 0; i < length; i++) {
		//printf("%d : %d\n", i, data[i]);
	}
	return data;
}




int main(){
	int a[1024];
	generate_random_array(a,1024,200);
	return 0;
}
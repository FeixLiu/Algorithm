#include<stdio.h>
void heapSort(int*, int, int);
int main(void)
{
	int size = 50;
	int num[50] = {23, 14, 35, 45, 12, 07, 32, 01, 98, 46,
		       87, 75, 54, 73, 92, 85, 62, 60, 63, 51,
		       47, 49, 29, 39, 27, 61, 34, 58, 19, 21,
		       86, 41, 05, 83, 69, 91,  8, 90, 99, 84,
		       83, 58, 30, 10, 15, 82, 23, 28, 95, 94};
	heapSort(num, 0, 49);
	int count;
	for(count = 0; count < size; count ++)
	{
		if(count % 10 == 0)
			printf("\n");
		printf("%d\t", num[count]);
	}
	printf("\n");
	return 0;
}
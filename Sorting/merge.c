#include<stdio.h>
#include<stdlib.h>
void mergeSort(int*, int, int);
void merge(int*, int, int, int);
int main(void)
{
	int size = 50;
	int num[50] = {23, 14, 35, 45, 12, 07, 32, 01, 98, 46,
		       87, 75, 54, 73, 92, 85, 62, 60, 63, 51,
		       47, 49, 29, 39, 27, 61, 34, 58, 19, 21,
		       86, 41, 05, 83, 69, 91,  8, 90, 99, 84,
		       83, 58, 30, 10, 15, 82, 23, 28, 95, 94};
	mergeSort(num, 0, 49);
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

void mergeSort(int* num, int left, int right)
{
	if(left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(num, left, mid);
		mergeSort(num, mid + 1, right);
		merge(num, left, mid, right);
	}
}

void merge(int* num, int left, int mid, int right)
{
	int size = right - left + 1;
	int* temp = (int*)malloc(size * sizeof(int));
	int i = left, j = mid + 1, count = 0;
	while(i <= mid && j <= right)
		if(num[i] < num[j])
			temp[count ++] = num[i ++];
		else
			temp[count ++] = num[j ++];
	while(i <= mid)
		temp[count ++] = num[i ++];
	while(j <= right)
		temp[count ++] = num[j ++];
	for(i = left, count = 0; i <= right; i ++, count ++)
		num[i] = temp[count];
	free(temp);
}

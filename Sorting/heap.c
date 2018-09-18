#include<stdio.h>
void heapSort(int*, int);
void heapAdjust(int*, int, int);
void createHeap(int*, int);
int main(void)
{
	int size = 51;
	int num[51] = {00, 23, 14, 35, 45, 12, 07, 32, 01, 98, 46,
		       87, 75, 54, 73, 92, 85, 62, 60, 63, 51,
		       47, 49, 29, 39, 27, 61, 34, 58, 19, 21,
		       86, 41, 05, 83, 69, 91,  8, 90, 99, 84,
		       83, 58, 30, 10, 15, 82, 23, 28, 95, 94};
	createHeap(num, 50);
	heapSort(num, 50);
	int count;
	for(count = 1; count < size; count ++)
	{
		if(count % 10 == 1)
			printf("\n");
		printf("%d\t", num[count]);
	}
	printf("\n");
	return 0;
}

void heapSort(int* num, int size)
{
	int temp;
	for(temp = size; temp > 0; temp --)
	{
		int inter = num[size];
		num[size] = num[1];
		num[1] = inter;
		size --;
		heapAdjust(num, size, 1);
	}
}

void heapAdjust(int* num, int size, int par)
{
	int temp, pos, lc, rc;
	while(par <= size / 2)
	{
		temp = num[par];
		lc = par << 1;
		rc = lc + 1;
		if(num[par] < num[lc])
		{
			num[par] = num[lc];
			pos = lc;
		}
		if(rc <= size && num[par] < num[rc])
		{
			num[par] = num[rc];
			pos = rc;
		}
		if(par == pos)
			break;
		else
			num[pos] = temp;
		par = pos;
	}
}

void createHeap(int* num, int size)
{
	int i;
	for(i = size / 2; i != 0; i--)
	{
		heapAdjust(num, size, i);
	}
}

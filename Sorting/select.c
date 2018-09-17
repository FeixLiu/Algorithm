#include<stdio.h>
void selectSort(int size, int* num);
int main(void)
{
	int size = 50;
	int num[50] = {23, 14, 35, 45, 12, 07, 32, 01, 98, 46,
				   87, 75, 54, 73, 92, 85, 62, 60, 63, 51,
				   47, 49, 29, 39, 27, 61, 34, 58, 19, 21,
				   86, 41, 05, 83, 69, 91,  8, 90, 99, 84,
				   83, 58, 30, 10, 15, 82, 23, 28, 95, 94};
	selectSort(size, num);
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

void selectSort(int size, int* num)
{
	int i, j, min;
	for(i = 0; i < size; i++)
	{
		min = i;
		for(j = i + 1; j < size; j++)
		{
			if(num[j] < num[min])
				min = j;
		}
		if(min != i)
		{
			int temp = num[i];
			num[i] = num[min];
			num[min] = temp;
		}
	}
}
#include<stdio.h>
int main(void)
{
	int a;
	scanf("%d", &a);
	int b;
	b = a/100 + ((a%100)/10)*10 + (a%10)*100;
	printf("%03d", b);
	return 0;
}

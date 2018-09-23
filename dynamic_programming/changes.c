#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void changes(int);
int coin[3] = {1, 3, 5};
int n = 3;

typedef struct State
{
	int nCoin; //the number of coins
	int lastSum; //last state
	int addCoin; //the kind of coin that is used 
	//to change from the last state to current state
} state;

int main(void)
{
	int total;
	scanf("%d", &total);
	changes(total);
	return 0;
}

void changes(int total)
{
	state* sum = (state*)malloc((total + 1) * sizeof(state));
	int i, j;
	for(i = 0; i <= total; i ++)
		sum[i].nCoin = INT_MAX;
	sum[0].nCoin = 0;
	sum[0].lastSum = 0;
	for(i = 1; i <= total; i ++) //change for i dollars
		for(j = 0; j < n; j ++) //use the j kind of coins
			if(i - coin[j] >= 0 && sum[i - coin[j]].nCoin + 1 < sum[i].nCoin)
			{ //use the existing knowledge to solve problem
				sum[i].nCoin = sum[i - coin[j]].nCoin + 1;
				sum[i].lastSum = j;
				sum[i].addCoin = coin[j];
			}
	if(sum[total].nCoin == INT_MAX)
		printf("Cannot make change.\n");
	else
	{
		while(total > 0)
		{
			printf("%d %d\n", sum[total].nCoin, sum[total].addCoin);
			total -= sum[total].addCoin;
		}
	}
}

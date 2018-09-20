#include<stdio.h>
#include<string.h>
void getNext(char*, int, int*);
void getNextVal(char*, int, int*);
int kmp(char*, int, char*, int, int*, int);

int main(void)
{
	char* s = "aaaaaaaaaaaacdadadcaaaab";
	char* subs = "aaaab";
	int lens = strlen(s);
	int lensubs = strlen(subs);
	int next[lensubs];
	int nextVal[lensubs];
	getNext(subs, lensubs, next);
	getNextVal(subs, lensubs, nextVal);
	int i;
	int pos;
	scanf("%d", &pos);
	if(pos % 2 == 0)
		printf("%d\n", kmp(s, lens, subs, lensubs, next, pos));
	else
		printf("%d\n", kmp(s, lens, subs, lensubs, nextVal, pos));
	return 0;
}

void getNext(char* subs, int lensubs, int* next)
{
	next[0] = -1;
	int i = 0, j = -1;
	while(i < lensubs)
	{
		if(j == -1 || subs[i] == subs[j])
			next[++ i] = ++ j;
		else
			j = next[j];
	}
}

void getNextVal(char* subs, int lensubs, int* nextVal)
{
	nextVal[0] = -1;
	int i = 0, j = -1;
	while(i < lensubs)
	{
		if(j == -1 || subs[i] == subs[j])
		{
			i++, j++;
			if(subs[i] != subs[j])
				nextVal[i] = j;
			else
				nextVal[i] = nextVal[j];
		}
		else
			j = nextVal[j];
	}
}

int kmp(char* s, int lens, char* subs, int lensubs, int* nextPos, int pos)
{
	int i = pos - 1, j = -1;
	while(i < lens && j < lensubs)
	{
		if(j == -1 || s[i] == subs[j]) 
			i ++, j ++;
		else
			j = nextPos[j];
	}
	if(j >= lensubs)
		return i - lensubs;
	else
		return -1;
}

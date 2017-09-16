#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

	int n;
	int size = sizeof(char)*20;
	scanf("%d", &n);
	char** array = malloc(sizeof(char*)*n);
	
	for (int i = 0; i < n; i++)	
	{
		char* p  = malloc(size);
		scanf("%s",p);
		array[i] = p;
	}

	printf("query begin\n");
	int queryNum;
	scanf("%d", &queryNum);
	
	char **query = malloc(sizeof(char*)*queryNum);
	int* ans = malloc(sizeof(int)*queryNum);

	for (int j = 0; j < queryNum; j++)
	{
		query[j] = malloc(size);
		scanf("%s", query[j]);
	}
	
	for(int j = 0; j < queryNum; j++)
	{
		char *target = query[j];
		int num = 0;
		for (int i = 0; i < n ; i++)	
		{
			if (strcmp(target, array[i]) == 0)
			{
				num ++;
			}
		}

		ans[j] = num;
		printf("%d\n", num);
	}

	return 0;
}

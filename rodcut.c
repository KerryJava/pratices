#include <stdio.h>
#include <stdlib.h>

int cut(int *price, int n, int *r, int *s)
{
	int max = 0;
	r[n] = max;
	for (int i = 1; i <= n; i++)
	{
		//int p = price[i];
		int sub = cut(price,n-i,r, s) + price[i];

//		printf(" rev %d in %d iterator %d", sub, n, i);
		if (sub > max)
		{
			max = sub;
			s[n] = i;
			r[n] = max;
		}

	}

	return max;
}

void cutrod(int *price, int n)
{
	int *r = malloc(sizeof(int)*(n+1));	
	int *s = malloc(sizeof(int)*(n+1));

	for (int j = 0; j <= n; j++)
	{
		r[j] = 0;
	}

	int i = cut(price, n, r, s);

	for (int j = 0; j <= n; j++)

	{
		printf("%d\t", r[j]);
	}

	
	printf("\n%d\n", i);

	printf("----Path\n");
	
	int sum = n;
	for (int i = n; i > 0 && sum > 0; i = i - s[n])
	{
		printf("%d\t", s[i]);
		sum -= s[i];
		
	}

	printf("\n");


	return;
}

int main()
{
	int price[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

	int size = sizeof(price)/sizeof(int);

	for (int i = 0; i < (size);i++)
	{
		printf("%d\t", i);
	}

	printf("\n");

	for (int i = 0; i < (size);i++)
	{
		printf("%d\t", price[i]);
	}

	printf("\n");

	cutrod(price, size-1); 	

	int num; 
	int cnt = 0;
	scanf("%d", &num);

	while(cnt < num)
	{

		int n = 0;
		scanf("%d", &n);	
		cutrod(price, n);
		cnt++;
	}
}




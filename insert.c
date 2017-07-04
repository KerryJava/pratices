#include<stdio.h>

void swap(int *a, int *b);

void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void insertsort(int a[],int len)
{
	int i,j;
	int key;
	for(i = 1; i < len; i++)
	{
		key = a[i];	
		j = i-1;
		for (; j >= 0&& a[j] > key; j--) 
		{
			a[j+1] = a[j];
		}

		a[j+1] = key;
	}
}

int main()
{
	int array[]= {11,3,5,4,9,1,10,13,14,0,234};

	insertsort(array, sizeof(array)/sizeof(int));	

	return 0;
}


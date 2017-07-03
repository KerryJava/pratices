#include<stdio.h>

void swap(int *a, int *b);

void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void bubblesort(int a[],int len)
{
	int i,j;
	for(i = 0; i < len; i++)
	{
		for (j = 0; j+1  < len-i; j++) 
		{
			if (a[j+1]< a[j])
			{
				swap(&a[j+1], &a[j]);
			}
		}
	}
}

int main()
{
	int array[]= {11,3,5,4,9,1,10,13,14,0,234};

	bubblesort(array, sizeof(array)/sizeof(int));	

	return 0;
}


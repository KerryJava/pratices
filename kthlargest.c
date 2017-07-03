#include<stdio.h>

void swap(int *a, int *b);

int  partition(int array[],int  start,int  end)
{
	int compareVal = array[end];
	int lastLessPos = start-1;
	for(int i=start; i < end; i++)
	{
		if (compareVal >  array[i]) 
		{
			lastLessPos ++;		
			swap(&array[i], &array[lastLessPos]);
		}
	}

	swap(&array[lastLessPos+1], &array[end]);

	return lastLessPos+1;
}

void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void quick_sort(int array[],int  start,int  end, int k)
{
	if (start > end || k > end){
		return;
	}

	int middle = partition(array, start, end);

	if (k == middle)
	{
		printf("the %d largest element is %d\n", k, array[k]);
		return;
	}


	quick_sort(array, start, middle-1, k);
	quick_sort(array, middle+1, end, k); 
}


int main()
{
	int array[]= {11,3,5,4,9,1,10,13,14,0,234,8};
	
	quick_sort(array,0, sizeof(array)/sizeof(int)-1, 10);

	return 0;
}


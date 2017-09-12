#include<stdio.h>

int binarySearch(int array[], int start, int end, int target);

int binarySearch(int array[], int start, int end, int target)
{

	int mid = (start + end)>>1;

	if (start > end)	
	{
		return -1;
	}

	if (array[mid] < target)
	{
		return binarySearch(array, mid + 1, end, target);
	}
	else if (array[mid] > target)
	{
		return binarySearch(array, start, mid - 1, target);
	}
	else 
	{
		return mid;
	}
}


int main()
{
	int array[]= {1,3,9,11,21,26};

	int idx = binarySearch(array, 0, sizeof(array)/sizeof(int)-1, 21);

	printf("-----%d\n", idx);
}

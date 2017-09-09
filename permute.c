#include<stdio.h>
#include<string.h>

void swapElem(char array[], int indexA , int indexB)
{
	char temp = array[indexA];
	array[indexA] = array[indexB];
	array[indexB] = temp;
}


void seq(char array[], int start , int end)
{
	//printf("1array %s\n", array);

	if (start >= end-1) 
	{
	//printf("\n Start %c %c %s------\n", start, end, array);
		printf("array %s\n", array);
		return;
	}

	for (int  i = start ; i < end ; i++)
	{
//		printf("%c", array[start]);
		//swap(&array[start], &array[i]);
		swapElem(array, start , i);
		seq(array, start +1 , end);
		swapElem(array, start , i);
		//swap(&array[start], &array[i]);
	}
}

int  main()
{
	char  testArray[] = "ABC";

	seq(testArray, 0, sizeof(testArray)/sizeof(char)-1); 
	return 0;
}



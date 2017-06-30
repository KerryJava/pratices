#include <stdio.h>
void printArray(char *array,int first, int last);
void swap(char *array, int i , int j );

int main()
{
	char alphbet[] = "abcdef";

	int len = sizeof(alphbet)/sizeof(char)-1;
	//for(int i = 0; i < len; i++) 
	{
		printArray(alphbet, 0, len);
	}

	return 0;
}

void printArray(char *array,int first, int last)
{
	if (first == last-1) 
	{	
		for(int j = 0 ; j < last; j++) 
		{
			printf("%c",array[j]);
		}

		printf("\n");
		return;
	}

	for (int i = first; i < last; i ++)	
	{
		swap(array, first, i);	
		printArray(array, first+1, last);
		swap(array, first, i);	
	}
}

void swap(char *array, int i , int j )
{
	char c;
	c = array[i];
	array[i] = array[j];
	array[j] = c;
}




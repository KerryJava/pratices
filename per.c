#include <stdio.h>
void printArray(char *array,int first, int last);
void swap(char *array, int i , int j );
void printArray2(char *array,int first, int last);
void swapElem(char *i , char *j );

int main()
{
	char alphbet[] = "abcdef";
	//char alphbet2[] = {'a','b','c','d','e','f'};
	char alphbet2[] = {'a','b','c',};

	int len = sizeof(alphbet)/sizeof(char)-1;
	//for(int i = 0; i < len; i++) 
	{
		//printArray(alphbet, 0, len);
	}

	int len2 = sizeof(alphbet2)/sizeof(char);
	//for(int i = 0; i < len; i++) 
	{
		printArray(alphbet2, 0, len2);
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

void printArray2(char *array,int first, int last)
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
		swapElem( &array[first], &array[i]);	
		printArray(array, first+1, last);
		swapElem(&array[first],&array[i]);	
	}
}
void swap(char *array, int i , int j )
{
	char c;
	c = array[i];
	array[i] = array[j];
	array[j] = c;
}

void swapElem(char *i , char *j )
{
	char c;
	c = *i;
	*i = *j;
	*j = c;
}




#include<stdio.h>
#include<stdlib.h>
#define MAX 256

char * compress(char *input);


char * compress(char *input)
{
	char *p = input;
	char *prev = NULL;
	int num;

	while(*p) 
	{
		if (prev && *prev != *p)
		{
			num ++;
		}
		prev = p;
		p++;
	}

	char * output = (char*)malloc(sizeof(char)*(num*2+1));
	output[num*2] = '\0';

	p = input;	
	prev = p;
	num = 0;
	output[0] = input[0];
	char *start = output;

	while(*p) 
	{
		if (*prev == *p)
		{
			num ++;
		}
		else {
			*output = '0' +  num ;
			num = 1;
			output ++;			
			*output = *p;
			output ++;
		}

		prev = p;
		p++;
	}

	*output = '0' + num;
	output[num*2] = '\0';

	return start;
}

int main()
{
	char * str = "aabbbcdaa";
	char *output = compress(str);
	printf("%s\n", output);
}

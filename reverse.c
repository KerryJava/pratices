#include<stdio.h>

void reverse(char *p);;
void reverse(char *p)
{
	char *last;
	char *start = p;
	char temp;
	while(*p) {
		p++;
	}
	
	last = p-1;

	while(start < last)
	{
		temp = *start;
		*start = *last;
		*last = temp;
		start ++;
		last --;
	}
	
}

int main()
{
	char str[] = "abcd";

	reverse(str);

	printf("%s\n", str);
}

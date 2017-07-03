#include<stdio.h>

int main()
{
	char c = 0x01;

	char *str = (c & 0x1) ? "bigendian":"smallendian";
	printf("is %s\n", str);


	return 0;
}


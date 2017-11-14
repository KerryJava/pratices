#include<stdio.h>
typedef struct stack {
	char c[1000];
	int idx;
}Stack;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	printf("%d\n", 1 != 1);
	printf("%d\n", 1 == 1);

	while('\0') {
		printf("xxxx");
	}

	Stack s;
	s.idx = 10;

	printf("%d\n",s.idx);

	int i[] =  {0,1,2,3};

	swap(&i[0], &i[2]);

	for (int j = 0; j < sizeof(i)/sizeof(int);j++)
	{

		printf("%d\t", i[j]);
	}

	printf("\n");

}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX (21+5)
#define SUB 21
typedef struct tire {
	char		c;
	struct tire    *next[256];
}		Node;

void 
insert(Node * p, char *s)
{
	printf("%s\n", s);
}

void 
print(Node * p, char *s)
{
	printf("%s\n", s);

}

void 
process(Node * p)
{
	char		s         [MAX + 1];
	char		sub       [SUB];

	scanf("%s", s);

	switch (s[0]) {
	case 'a':
		strcpy(sub, &s[3]);
		insert(p, sub);
		break;
	case 'f':
		strcpy(sub, &s[4]);
		print(p, sub);
		break;
	}
}

int 
main()
{
	int		num;
	char		ch;
	scanf("%d", &num);
	int		count = 0;
	Node           *p = malloc(sizeof(Node));
	while (count < num) {
		process(p);
		count++;
	}
	/*
	 * Enter your code here. Read input from STDIN. Print output to
	 * STDOUT
	 */
	return 0;
}

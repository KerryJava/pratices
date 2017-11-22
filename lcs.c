#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX (100)
enum status {
	INIT,
	MATCH,
	MORE,
	LESS,
}		STATUS;

int 
lcs(int *a, int a_idx, int a_size, int *b, int b_idx, int b_size, int **arr)
{
	char           *c;
	int		len1;
	int		len2;

	if (a_idx >= a_size || b_idx >= b_size) {
		return 0;
	}
	if (a[a_idx] == b[b_idx]) {
		arr[a_idx][b_idx] = MATCH;
		return lcs(a, a_idx + 1, a_size, b, b_idx + 1, b_size, arr) + 1;
	} else {

		len1 = lcs(a, a_idx + 1, a_size, b, b_idx, b_size, arr);
		len2 = lcs(a, a_idx, a_size, b, b_idx + 1, b_size, arr);

		if (len1 > len2) {
			arr[a_idx][b_idx] = MORE;
		} else {
			arr[a_idx][b_idx] = LESS;
		}

		return len1 > len2 ? len1 : len2;
	}
}

char           *
print(int *a, int a_size, int *b, int b_size, int **arr)
{
	int		size = a_size > b_size ? (a_size + 1) : (b_size + 1);
	char           *s = malloc(sizeof(char) * (size));
	int		a_idx = 0;
	int		b_idx = 0;
	int		i = 0;
	while (a_idx < a_size && b_idx < b_size) {
		switch (arr[a_idx][b_idx]) {
		case MATCH:
			s[i] = a[a_idx];
			printf("match --%d [%d %d]--", a[a_idx], a_idx, b_idx);
			i++;
			a_idx++;
			b_idx++;
			break;
		case MORE:
			a_idx++;
			break;
		case LESS:
			b_idx++;
			break;
		default:
			printf("--%d --", arr[a_idx][b_idx]);
			a_idx++;
			b_idx++;
			break;
		}
	}

	printf("\n");
	s[i] = '\0';
	return s;
}

char           *
lcsPrint(int *a, int a_size, int *b, int b_size)
{
	int		col = a_size;
	int		row = b_size;

	for (int i = 0; i < a_size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	for (int i = 0; i < b_size; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");

	int           **arr = malloc(sizeof(int *) * (col));
	for (int i = 0; i < col; i++) {
		arr[i] = malloc(sizeof(int) * row);
		for (int j = 0; j < row; j++) {
			arr[i][j] = INIT;
		}
	}

	int		len = lcs(a, 0, a_size, b, 0, b_size, arr);
	char           *c = malloc(sizeof(char) * 100);

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			printf("|%d| ", arr[i][j]);
		}

		printf("\n");

	}

	printf("\n");

	return print(a, a_size, b, b_size, arr);;
}

int 
main()
{
	int		a         , b;
	scanf("%d %d", &a, &b);
	int            *a_arr = malloc(sizeof(int) * a);
	int            *b_arr = malloc(sizeof(int) * b);
	int           **p_arr = malloc(sizeof(int *) * 2);
	p_arr[0] = a_arr;
	p_arr[1] = b_arr;
	int            *num_arr = malloc(sizeof(int) * 2);
	num_arr[0] = a;
	num_arr[1] = b;

	int		i = 0;
	while (i < 2) {
		int		num = num_arr[i];
		int            *p = p_arr[i];
		int		count = 0;
		char		nextchar;
		while (count < num) {
			scanf("%d", &(p[count]));
			count++;
		}


		i++;
	}

	char           *s = lcsPrint(a_arr, a, b_arr, b);
	printf("%s", s);
	/*
	 * Enter your code here. Read input from STDIN. Print output to
	 * STDOUT
	 */
	return 0;
}

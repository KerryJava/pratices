/**
 *  * Return an array of size *returnSize.
 *   * Note: The returned array must be malloced, assume caller calls free().
 *    */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 	(5)

typedef struct result {
	char          **s;
	char           *origin;
	int		count;
}		Result;

void 
initResult(Result * result, int count)
{
	result->s = malloc(sizeof(char *) * count);
	result->count = 0;
	result->origin = NULL;
}

void 
freeResult(Result * result)
{
	result->count = 0;
	free(result->s);
	free(result->origin);
}

void 
insertResult(Result * result, char *s)
{
	result->s[result->count] = malloc(sizeof(char) * strlen(s));
	strncpy(result->s[result->count], s, strlen(s));
	result->s[result->count][strlen(s)] = '\0';
	result->count++;
}

void 
swap(char *a, char *b)
{
	int		temp = *a;
	*a = *b;
	*b = temp;
}

void 
printResult(Result * s)
{
	for (int i = 0; i < s->count; i++) {
		printf("%s\n", s->s[i]);
	}
}


void 
combinations(char *digits, char map[][LEN], int idx, Result * s)
{
	if (digits[idx] == '\0') {
		insertResult(s, s->origin);
		return;
	}
	char           *p = map[digits[idx] - '0'];
	char           *origin = s->origin;

	for (int i = 0; p[i]; i++) {
		char		c = origin[idx];
		origin[idx] = p[i];
		combinations(digits, map, idx + 1, s);
		origin[idx] = c;
	}
}

char          **
letterCombinations(char *digits, int *returnSize)
{

	char		map       [][LEN] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	int		len = strlen(digits);
	int		arrayLen = sizeof(map) / sizeof(map[0]);
	int		size = LEN;
	
	for (int i = 1; i < len; i++)
	{
		size *= LEN;
	}

	char           *output = malloc(sizeof(char) * (len + 1));
	int		count = -1;

	Result		s;
	initResult(&s, size);
	s.origin = output;

	for (int i = 0; i < len; i++) {
		char           *p = map[digits[i] - '0'];
		if (!strcmp(p, "")) {
			output[i] = p[0];
		}
	}
	output[len] = '\0';

	combinations(digits, map, 0, &s);

	printResult(&s);

	*returnSize = s.count;
	return s.s;
}

int 
main()
{
	printf("%lu\n", strlen(""));
	int		size = 0;
	char          **p = letterCombinations("999", &size);
	for (int i = 0; i < size; i++) {
		printf("%s\n", *(p + i));
	}

}

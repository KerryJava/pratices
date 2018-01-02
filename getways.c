#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

long 
getWays(long n, int c_size, long int *c)
{

	if (c_size == 0) {
		return 0;
	}
	if (n == 0) {
		return 1;
	}
	if (n < 0) {
		return 0;
	}
	long		max = 0;
	for (int i = 0; i < c_size; i++) {

		long		temp = getWays(n - c[i], c_size, c);
		if (temp > 0) {
			max += temp;
		}
	}

	return max;
}

int 
main()
{
	int		n;
	int		m;
	scanf("%d %d", &n, &m);
	long           *c = malloc(sizeof(long) * m);
	for (int c_i = 0; c_i < m; c_i++) {
		scanf("%ld", &c[c_i]);
	}
	long		ways = getWays(n, m, c);
	printf("%ld", ways);
	return 0;
}

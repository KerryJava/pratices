#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    int n; 
    int m; 
    scanf("%i %i", &n, &m);

    int *array = malloc(sizeof(int)*n);

    memset(array, 0, sizeof(int)*n);

    int max=0;
    for(int a0 = 0; a0 < m; a0++){
        int a; 
        int b; 
        int k; 
        scanf("%i %i %i", &a, &b, &k);

	array[a] += k;

	if (b < n)
	{
		array[b] -= k;
	}

    }

    int sum = 0;
    for (int i = 0; i < n; i ++)
    {
	sum += array[i];
	if (sum > max)
	{
		max = sum;
	}
    }

    printf("%d\n",max);
	return 0;
}

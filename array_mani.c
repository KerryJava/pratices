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
    
    for(int i = 0; i < n; i++)
    {
	    array[i] = 0;
    }

    int max=0;
    for(int a0 = 0; a0 < m; a0++){
        int a; 
        int b; 
        int k; 
        scanf("%i %i %i", &a, &b, &k);

	for (int j = a; j < b; j++)
	{
		array[j] += k;

		if (array[j] > max)
		{
			max = array[j];
		}
	}
    }

    printf("%d\n",max);
	return 0;
}

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int* leftRotation(int a_size, int* a, int d, int *result_size) {
    // Complete this function
    int offset = d % a_size;
    int *half = malloc(sizeof(int)*offset);
    
    for (int j = 0; j < offset; j++)
    {
        half[j] = a[j];
    }
  
        int i;
        for (i = offset; i < a_size; i++)
        {
            a[i-offset] = a[i];
        }

	int j  = i - offset;
        	
        for (i = 0; i < offset ; i ++ )
        {
            a[j+i] = half[i];
        }
    
    *result_size = a_size;
    
    return a;
}

int main() {
    int n; 
    int d; 
    scanf("%i %i", &n, &d);
	n = 14;
	d = 7;
    int a[]= {26 ,54 ,63 ,24 ,17 ,32 ,81 ,98 ,67 ,35, 1 ,74 ,79 ,7};
//    int *a = malloc(sizeof(int) * n);
//    for (int a_i = 0; a_i < n; a_i++) {
//       scanf("%i",&a[a_i]);
//    }

   
    int result_size;
    int* result = leftRotation(n, a, d, &result_size);
    for(int result_i = 0; result_i < result_size; result_i++) {
        if(result_i) {
            printf(" ");
        }
        printf("%d", result[result_i]);
    }
    puts("");


    return 0;
}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_VALUE (100)

int 
main()
{

	int		num;
	int            *ar;
	scanf("%d\n", &num);
	int		count = num;
	int		cnt_array  [MAX_VALUE] = {0};

	for (int i = 0; i < MAX_VALUE; i++) {
		cnt_array[i] = 0;
	}
	ar = (int *)malloc(sizeof(int) * num);
	while (count < num) {
		scanf("%d", (ar + count));
		count++;
	}

	for (int i = 0; i < num; i++) {
		cnt_array[ar[i]]++;
	}

	for (int j = 0; j < num; j++) {
		printf("%d ", cnt_array[ar[j]]);
	}

	printf("\n");

	return 0;
}

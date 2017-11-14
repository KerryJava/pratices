#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
void
printInsertionSort(int ar_size, int *ar)
{
	for (int i = 0; i < ar_size; i++) {
		printf("%d ", ar[i]);
	}

	printf("\n");

}
void
insertionSort(int ar_size, int *ar)
{

	int		temp = ar[ar_size - 1];
	int		i = ar_size - 2;
	for (; i >= 0; i--) {
		if (ar[i] >= temp) {
			ar[i + 1] = ar[i];
			printInsertionSort(ar_size, ar);

		} else {
			ar[i + 1] = temp;
			printInsertionSort(ar_size, ar);
			break;
		}

	}


	if (i < 0) {
		a[0] = temp;
		printInsertionSort(ar_size, ar);
	}
}


int
main(void)
{
	int		_ar_size;
	scanf("%d", &_ar_size);
	int		_ar        [_ar_size], _ar_i;
	for (_ar_i = 0; _ar_i < _ar_size; _ar_i++) {
		scanf("%d", &_ar[_ar_i]);
	}

	insertionSort(_ar_size, _ar);
	return 0;
}

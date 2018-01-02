#include<stdio.h>
#include<limits.h>
#define MAX(a, b) ((a) > (b) ? (a):(b))
#define MIN(a, b) ((a) > (b) ? (b):(a))
//
// maxSub = MAX{ left + middle, right+middle}
//
// a b c d e f 
// a  {b, c, d, e} f 
//



int
maxSubArray(int *nums, int numsSize)
{

	if (numsSize == 0) {
		return 0;
	}
	if (numsSize == 1) {
		return nums[0];
	}
	if (numsSize == 2) {
//		return MAX(nums[0], nums[1]);
	}
	int		max = INT_MIN;
	for (int i = 1; i < (numsSize - 1); i++) {
		int		middle = maxSubArray(nums + i, numsSize - 1 - i);

		int		left = nums[i - 1];
		int		right = nums[numsSize - 1];
		int		sum = middle;

		if (left > 0) {
			sum += left;
		}
		if (right > 0) {
			sum += right;
		}
		if (max < sum) {
			max = sum;
			printf("right %d\n", right);
			printf("---first %d max %d numsSize %d i %d left %d right %d [%d] middle %d \n", nums[0], max, numsSize, i, left, right, numsSize - 1 + i - 1, middle);
		}
	}

	return max;
}

int 
main()
{
	int		array      [] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	printf("%d\n", maxSubArray(array, sizeof(array) / sizeof(int)));
}

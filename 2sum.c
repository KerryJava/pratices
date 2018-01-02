#include <stdio.h>
#include <stdlib.h>
/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *   */
typedef struct data {
	int		origin;
	int		val;
}		Data;

void
initData(Data * data)
{
	data->origin = 0;
	data->val = 0;
}

void
copyData(Data * a, Data * b)
{
	a->origin = b->origin;
	a->val = b->val;
}

void
swapData(Data * a, Data * b)
{
	Data		temp;
	copyData(&temp, a);
	copyData(a, b);
	copyData(b, &temp);
}

int
partition(Data * nums, int start, int end)
{
	//Data		pviot;
	//copyData(&pviot, (nums + start));
	//printf("pviot %d\n", pviot.val);
	int		sortIdx = start;
	for (int i = start+1; i <= end ; i++) {
		if (nums[start].val > nums[i].val)
		{
		sortIdx++;
		swapData((nums + sortIdx), (nums + i));
		printf("%d %d\n", nums[i].val, i);
		}
	}

	printf("%d %d %d\n", sortIdx, start, end);
	swapData((nums + start), (nums + sortIdx));

	return sortIdx;
}

void
quickSort(Data * nums, int start, int end)
{
	if (start < end) {
		int		mid = partition(nums, start, end);
		quickSort(nums, start, mid - 1);
		quickSort(nums, mid + 1, end);
	}
}

void
quickSortMethod(Data * nums, int numsSize)
{
	quickSort(nums, 0, numsSize - 1);
}

void
insertSort(Data * nums, int numsSize)
{
	Data		temp;
	for (int i = 0; i < numsSize - 1; i++) {
		int		j = i;
		copyData(&temp, (nums + j + 1));
		for (; j >= 0 && temp.val < nums[j].val; j--) {
			copyData((nums + j + 1), (nums + j));
		}

		copyData((nums + j + 1), &temp);
	}
}

int            *
twoSum(int *nums, int numsSize, int target)
{

	Data           *d = malloc(sizeof(Data) * numsSize);

	for (int i = 0; i < numsSize; i++) {
		Data           *p = (d + i);
		p->origin = i;
		p->val = nums[i];
	}

	quickSortMethod(d, numsSize);

	for (int i = 0; i < numsSize; i++) {
		Data		temp = d[i];
		printf("%d\t", temp.val);
	}
	printf("\n");

	for (int i = 0; i < numsSize; i++) {
		Data		temp = d[i];
		printf("%d\t", temp.origin);
	}
	printf("\n");

	int            *result = malloc(sizeof(int) * 2);
	result[0] = 0;
	result[1] = 0;

	int		end = numsSize - 1;
	for (int i = 0; i < numsSize; i++) {
		int		oppo = target - d[i].val;
		for (int j = end; j > i; j--) {
			if (oppo > d[j].val) {
				break;
			} else if (oppo == d[j].val) {
				end = j;
				printf("find %d %d", i, j);
				result[0] = d[i].origin;
				result[1] = d[j].origin;

				free(d);
				return result;
				break;
			}
		}
	}

	free(d);
	return result;
}

int 
main()
{
	//int		nums       [] = {2, 5, 5, 11, 10};
	int		nums       [] = {150,24, 79, 50, 88, 345, 3};
	int            *p = twoSum(nums, sizeof(nums) / sizeof(int), 200);
	printf("\n");
	printf("%d %d\n", p[0], p[1]);
}

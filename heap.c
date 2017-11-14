#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100000
#define OFFSET 1

typedef struct heap {
	int		p          [MAX];
	int		idx;
}		Heap;

void 
swap(int *a, int *b)
{
	int		temp = *a;
	*a = *b;
	*b = temp;
}

int 
rightChild(int idx)
{
	return ((idx + OFFSET) * 2 + 1) - OFFSET;
}

int 
leftChild(int idx)
{
	return ((idx + OFFSET)* 2) - OFFSET;
}

void 
initHeap(Heap * h)
{
	h->idx = 0 - OFFSET;
}

int 
isEmpty(Heap * h)
{
	return h->idx == (0 - OFFSET);
}

void 
heaplify(Heap * h, int idx)
{

	int		smallest = idx;
	if (rightChild(idx) <= h->idx && h->p[rightChild(idx)] < h->p[smallest]) {
		smallest = rightChild(idx);
	}
	if (leftChild(idx) <= h->idx && h->p[leftChild(idx)] < h->p[smallest]) {
		smallest = leftChild(idx);
	}
	if (smallest != idx) {
		swap(&(h->p[smallest]), &(h->p[idx]));
		heaplify(h, smallest);
	}
}

void 
insertHeap(Heap * h, int v)
{
	if (isEmpty(h)) {
		h->idx++;
		h->p[h->idx] = v;
		return;
	}
	h->idx++;
	h->p[h->idx] = v;
	swap(&(h->p[h->idx]), &(h->p[1 - OFFSET]));

	for (int i = h->idx; i >= (1 - OFFSET); i--) {
		heaplify(h, i);
	}
}

void 
getMin(Heap * h, int *value)
{
	if (isEmpty(h)) {
		return;
	}
	swap(&(h->p[1 - OFFSET]), &(h->p[h->idx]));
	h->idx--;
	heaplify(h, h->idx);
}

void 
printHeap(Heap h)
{
	printf("%d\n", h.p[0]);
}



int 
main()
{
	int		num;
	scanf("%d", &num);

	int		cnt = 0;
	int		operate;
	int		input;
	int		newline;
	int		temp;
	Heap		heap;
	initHeap(&heap);
	while (cnt < num) {
		scanf("%d", &operate);

		switch (operate) {
		case 1:
			scanf("%d", &input);
//			printf("operate %d - %d\n",operate,  input);
			insertHeap(&heap, input);
			break;
		case 2:
			scanf("%d", &input);
//			printf("operate %d - %d\n",operate,  input);
			getMin(&heap, &temp);
			break;
		case 3:
			if (cnt != num -1)
			{
//				scanf("%d", &newline);
			}

//			printf("operate %d  ",operate);
			printHeap(heap);
			break;
		}

		cnt++;
	}

	/*
	 * Enter your code here. Read input from STDIN. Print output to
	 * STDOUT
	 */
	return 0;
}

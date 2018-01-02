#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100000
#define OFFSET 1
#define INVALID (0-OFFSET)
#define FIRST_IDX (1-OFFSET)

typedef long	Type;

typedef struct heap {
	Type		p         [MAX];
	int		idx;
}		Heap;

void 
swap(Type * a, Type * b)
{
	Type		temp = *a;
	*a = *b;
	*b = temp;
}

int 
parent(int idx)
{
	return ((idx + OFFSET) / 2 - OFFSET);
}

int 
rightChild(int idx)
{
	return ((idx + OFFSET) << 1 + 1 - OFFSET);

}

int 
leftChild(int idx)
{
	return ((idx + OFFSET) << 1 - OFFSET);
}

void 
initHeap(Heap * h)
{
	h->idx = INVALID;
}

int 
isEmpty(Heap * h)
{
	return h->idx == INVALID;
}

void 
heaplify(Heap * h, int idx)
{
	int		smallest = idx;

	if (idx > h->idx) {
		return;
	}
	int		right = rightChild(idx);
	int		left = leftChild(idx);
	if (right <= h->idx && h->p[right] < h->p[smallest]) {
		smallest = right;
	}
	if (left <= h->idx && h->p[left] < h->p[smallest]) {
		smallest = left;
	}
	if (smallest != idx) {
		swap(&(h->p[smallest]), &(h->p[idx]));
		heaplify(h, smallest);
	}
}

void 
insertHeap(Heap * h, Type v)
{
	h->idx++;
	h->p[h->idx] = v;

	for (int i = h->idx; i > FIRST_IDX && h->p[parent(i)] > h->p[i]; i = parent(i)) {
		swap(&(h->p[parent(i)]), &(h->p[i]));
	}

}

void 
deleteVal(Heap * h, long value, int idx)
{
	int		target = idx;

	if (value < h->p[target]) {
		return;
	}
	if (h->p[target] == value) {
		swap(&(h->p[target]), &(h->p[h->idx]));
		h->idx--;
		heaplify(h, target);
		return;
	}
	int		right = rightChild(idx);
	if (right <= h->idx && h->p[right] >= h->p[target]) {
		deleteVal(h, value, right);
	}
	int		left = leftChild(idx);

	if (left <= h->idx && h->p[left] >= h->p[target]) {
		deleteVal(h, value, left);
	}
}

void 
deleteHeapVal(Heap * h, Type value)
{
	deleteVal(h, value, FIRST_IDX);
}

void 
getMin(Heap * h, Type * value)
{
	if (isEmpty(h)) {
		return;
	}
	swap(&(h->p[FIRST_IDX]), &(h->p[h->idx]));
	h->idx--;
	heaplify(h, h->idx);
}

void 
printHeap(Heap * h)
{
	if (isEmpty(h))
		return;
	printf("%ld\n", h->p[FIRST_IDX]);
}

void 
printAll(Heap h)
{
	for (int i = 0; i <= h.idx; i++) {
		printf("|%d ", h.p[i]);
	}

	printf("\n");
}

int 
main()
{
	int		num;
	scanf("%d", &num);

	int		cnt = 0;
	int		operate;
	Type		input;
	int		newline;
	int		temp;
	Heap		heap;
	initHeap(&heap);
	while (cnt < num) {
		scanf("%d", &operate);

		switch (operate) {
		case 1:
			scanf("%ld", &input);
			insertHeap(&heap, input);
			break;
		case 2:
			scanf("%ld", &input);
			deleteHeapVal(&heap, input);
			break;
		case 3:
			printHeap(&heap);
			break;
		}

		cnt++;
	}

	return 0;
}

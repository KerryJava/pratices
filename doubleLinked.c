#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int		data;
	struct Node    *next;
	struct Node    *prev;
}		Node;

Node           *
SortedInsert(Node * head, int data)
{

	Node           *node = (Node *) malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	if (!head) {
		head = (Node *) malloc(sizeof(Node));
		head->prev = NULL;
		head->next = node;

		node->prev = head;
		return head;
	}
	Node           *p = head->next;
	Node           *prev = head;

	printf("%d--x\n", data);
	while (p) {
		printf("%d--\n", p->data);
		if (p->data > data) {
			p->prev->next = node;
			node->prev = p->prev;
			node->next = p;
			p->prev = node;

			return head;
		} else {
			prev = p;
			p = p->next;
		}
	}

	prev->next = node;
	node->prev = prev;

	return head;
}

int 
main()
{

//	int		a          [] = {1, 4, 2, 3, 7, 6, 9};
int		a        [] = {1, 4, 2, 3, 7, 6, 9, 10};
	int		num = sizeof(a) / sizeof(int);
	Node           *p = NULL;
	for (int i = 0; i < num; i++) {
		p = SortedInsert(p, a[i]);
	}

	p = p->next;
	while (p) {
		printf("%d\n", p->data);
		p = p->next;
	}
}

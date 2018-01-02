#include<stdio.h>
#include<stdlib.h>
#define MAX 127 
typedef struct node {
	struct node    *next[MAX];
	int		diff;
	int		height;
	char		c;
	char		nextChar;
}	Node;

void 
initNode(Node * node)
{
	node->c = 0;
	node->height = 0;
	node->diff = 0;
	node->nextChar = 0;
	for (int i = 0; i < MAX; i++) {
		node->next[i] = NULL;
	}
}

void 
insertNode(Node * node, char *s)
{
	int		i = 0;
	Node           *head = node;
	Node           *p = node;

	if (!s[0]) {
		p->diff = 1;
	}
	while (s[i]) {
		printf("%d\n", s[i]);	
		if (s[i] >= MAX)
		{
			printf(" over lap\n");
		}
		if (!p->next[s[i]]) {
			p->next[s[i]] = malloc(sizeof(Node));
			initNode(p->next[s[i]]);
			p->next[s[i]]->c = s[i];
		}
		if (s[i] != p->nextChar) {
			if (p->nextChar == 0) {
				p->diff = 1;
			}
			p->nextChar = s[i];
			printf("%d\n",p->diff);
		} else {
			p->diff++;
		}


		p = p->next[s[i]];

		i++;

		if (i > head->height) {
			head->height = i;
		}
	}
}

char           *
longestComm(Node * node, int strsSize)
{
	Node           *p = node;

	char           *ch = malloc(sizeof(char) * (node->height + 1));
	int		i = 0;
	printf("jjj\n");
	while (p && p->diff == strsSize) {
		ch[i] = p->nextChar;
		printf("xxxx\n");
		printf("%c\n",ch[i]);
		i++;
		p = p->next[p->nextChar];
	}

	ch[i] = '\0';
	return ch;
}

void 
myfreeTree(Node * root)
{
	if (!root) {
		return;
	}
	for (int i = 0; i < MAX; i++) {
		if (root->next[i] != NULL) {
			myfreeTree(root->next[i]);
		}
	}

	free(root);
}

char           *
longestCommonPrefix(char **strs, int strsSize)
{
	Node           *root = malloc(sizeof(Node));
	initNode(root);
	for (int i = 0; i < strsSize; i++) {
		insertNode(root, strs[i]);
	}

	char           *p = longestComm(root, strsSize);
//	char           *second = malloc(sizeof(char) * (root->height + 1));
//	strcpy(second, p);
	//myfreeTree(root);
//	
	return p;
}

int main()
{
	setbuf(stdout, NULL);

	char *ch[1] = { "c"};
		char *p = longestCommonPrefix(ch, 1);
		printf("%c\n",p[0]);
	printf("%s", p);
	fflush (stdout);
}

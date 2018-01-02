#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int		start;
	int		end;
	int		len;
}		Node;

Node           *
longest(char *s, int start, int end, Node * mem, int size)
{
	Node           *ret = (mem + start * size + end);
	if (ret->len) {
		return ret;
	}
	if (start == end) {
		ret->start = start;
		ret->end = end;
		ret->len = 1;
		return ret;
	}
	Node           *p1 = mem + start * size + end;
	Node           *p2 = mem + ((start + 1) * size + end);
	Node           *p3 = mem + (start * size + end - 1);
	Node           *max;
	if (s[start] == s[end]) {
		if (end - start >= 2) {
			Node           *sub = mem + ((start + 1) * size + end - 1);

			if (!sub->len) {
				sub = longest(s, start + 1, end - 1, mem, size);
			}
			p1->start = sub->start;
			p1->end = sub->end;
			p1->len = sub->len;
		} else if (end - start == 1) {
			p1->len = 2;
			p1->start = start;
			p1->end = end;
			return p1;
		}
		if (start + 1 == p1->start && end - 1 == p1->end) {
			p1->len += 2;
			p1->start = start;
			p1->end = end;
			return p1;
		}
	}
	if (!p2->len) {
		p2 = longest(s, start + 1, end, mem, size);
	}
	if (!p3->len) {
		p3 = longest(s, start, end - 1, mem, size);
	}
	if (p2->len > p3->len) {
		max = p2;
	} else {
		max = p3;
	}

	ret->start = max->start;
	ret->end = max->end;
	ret->len = max->len;

	return ret;
}

char           *
longestPalindrome(char *s)
{
	int		len = strlen(s) ? strlen(s) : 1;
	int		size = len * len;
	Node           *mem = malloc(sizeof(Node) * (size));
	memset(mem, 0, size);
	Node           *p = longest(s, 0, strlen(s) - 1, mem, len);
	char           *retS = malloc(sizeof(char) * (p->len + 1));
	strncpy(retS, s + p->start, p->len);
	retS[p->len] = '\0';

	free(mem);

	return retS;
}
int 
main()
{
	int		n;
	int		count = 0;
	char		input     [200];
//	char *input;

	scanf("%d", &n);
	while (count < n) {
		scanf("%s", input);
//		
//		input = "slvafhpfjpbqbpcuwxuexavyrtymfydcnvvbvdoitsvumbsvoayefsnusoqmlvatmfzgwlhxtkhdnlmqmyjztlytoxontggyytcezredlrrimcbkyzkrdeshpyyuolsasyyvxfjyjzqksyxtlenaujqcogpqmrbwqbiaweacvkcdxyecairvvhngzdaujypapbhctaoxnjmwhqdzsvpyixyrozyaldmcyizilrmmmvnjbyhlwvpqhnnbausoyoglvogmkrkzppvexiovlxtmustooahwviluumftwnzfbxxrvijjyfybvfnwpjjgdudnyjwoxavlyiarjydlkywmgjqeelrohrqjeflmdyzkqnbqnpaewjdfmdyoazlznzthiuorocncwjrocfpzvkcmxdopisxtatzcpquxyxrdptgxlhlrnwgvee";
		char           *s = longestPalindrome(input);
		printf("%s\n", s);
		count++;
	}
	return 0;
}

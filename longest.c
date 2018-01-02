#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char           *
longest(char *s, int start, int end)
{

	if (start == end) {
		char           *retStr = malloc(sizeof(char) * 2);
		retStr[0] = s[start];
		retStr[1] = '\0';
		return retStr;
	} else if (start > end) {
		char           *retStr = malloc(sizeof(char) * 2);
		retStr[0] = '\0';
		return retStr;
	}
	char           *left = longest(s, start + 1, end);
	char           *right = longest(s, start, end - 1);
	char           *mid = longest(s, start + 1, end - 1);

	char           *resStr = malloc(sizeof(char) * (end - start + 2));
	char           *pMax;
	char           *retMax;

	if (s[start] == s[end]) {
		resStr[0] = s[start];
		strcpy(resStr + 1, mid);
		resStr[strlen(mid) + 1] = s[end];
	}
	if (strlen(left) > strlen(right)) {
		pMax = left;
	} else {
		pMax = right;
	}

	if (strlen(resStr) > strlen(pMax)) {
		pMax = resStr;
	} else {
		strcpy(resStr, pMax);
	}

	printf("%s %s %s\n", left, right, mid);
	free(left);
	free(right);
	free(mid);

	return resStr;
}

char           *
longestPalindrome(char *s)
{

	return longest(s, 0, strlen(s) - 1);
}

int 
main()
{
//	printf("%s", longestPalindrome("babaddtattarrattatddetartrateedredivider"));
	printf("%s", longestPalindrome("cbbd"));
}

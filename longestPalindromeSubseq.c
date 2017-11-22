#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int
longestPalindromeSubseq(char *s)
{

	unsigned int	len = strlen(s);
	if (len == 0) {
		return 0;
	}
	if (len == 1) {
		return 1;
	}
	char           *sub = malloc(sizeof(char) * (len + 1));
	int		max = 1;
	for (int i = 0; i < len; i++) {
		for (int j = len - 1; j > 0 && i <= j; j--) {
			if (s[i] == s[j]) {
				int		start = i + 1;
				int		end = j - 1;
				int		temp = 2;

				if (start <= end) {
					strncpy(sub, s + start,  end - start + 1);
					sub[end - start + 1] = '\0';
					temp += longestPalindromeSubseq(sub);
				}

				if (temp > max) {
					max = temp;
				}
			}
		}
	}

	return max;
}

int 
main()
{
	char           *s = "cbbd";
	printf("%d\n", longestPalindromeSubseq(s));
}

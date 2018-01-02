#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX 256
#define INVALID (-1)
int 
lengthOfLongestSubstring(char *s)
{
	int map       [MAX] = {INVALID};
	memset(map, INVALID, sizeof(int) * MAX);
	int		length = 0;
	int		i = 0;
	int		max = 0;
	int start = INVALID;
	while (s[i]) {
		printf(" b %d \n", map['b']);
		int  repeatIdx = map[s[i]];
		if (map[s[i]] == INVALID || ( repeatIdx < start)) {
			printf("add length %d %c %d\n", length+1, s[i], i);	
			length++;
		} else {
			length = i - repeatIdx;
			printf("%d -length map %d %c\n", length, i, s[i]);
			for (int j = repeatIdx - 1; j >= 0; j--) {
				map[s[j]] = INVALID;
				printf(" %c %d| ", s[j], map[s[j]]);
			}

			printf("---\n---\n");

			for (int k = repeatIdx+1; k < i; k++)
			{
				//map[s[k]] = k;
				printf(" %c %d|| ", s[k], map[s[k]]);
			}
			printf("\n");
		}

		map[s[i]] = i;

		if (max < length) {
			printf("max is %d %c\n", i, s[i]);
			max = length;
		}
		i++;
	}

	return max;
}

int 
main()
{
	char           *s = "abcabcbb";
	//char           *s = "abba";
	//char  *s = "blqsearxxxbiwqa";
	printf("%d\n", lengthOfLongestSubstring(s));
}

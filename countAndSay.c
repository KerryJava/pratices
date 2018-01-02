#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SZ(n) ((2 * n + 1) * (sizeof(char)))
char             *
count(char *s, int n, char *pc)
{
//	printf(" %d \n", n );
	int		i = 0;
	int		count = 1;
	int		j = 0;
	for (; i < n; i++) {
		if (i + 1 != n && s[i] == s[i + 1]) {
			count++;
		} else {
			snprintf((pc + j), 3, "%d%d", count, s[i] - '0');
			count = 1;
			j += 2;
		}
	}


	return pc;
}

char           *
countAndSay(int n)
{

	char           *s = malloc(SZ(n));
	memset(s, '\0', SZ(n));

	s[0] = '1';
	s[1] = '\0';

	char           *proc;
	char           *temp;
	for (int i = 2; i <= n; i++) {
		proc = malloc(SZ(strlen(s)));
		memset(proc, '\0', SZ(strlen(s)));
		temp = count(s, strlen(s), proc);
		//memset(s, '\0', SZ(n));
		//strcpy(s, temp);
		free(s);
		s = proc;
	}

	return s;
}

int main()
{
	printf("%s\n", countAndSay(100));
	return 0;
}

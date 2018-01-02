#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INDEX(i,j, l) ((i)*(l)+(j))
int 
longestMem(char *s, int *mem, int start_idx, int end_idx, int s_len)
{
	unsigned int	len = end_idx - start_idx + 1;

	if (len == 0) {
		return 0;
	}
	if (len == 1) {
		mem[INDEX(start_idx, end_idx, s_len)] = 1;
		return 1;
	}
	if (mem[INDEX(start_idx, end_idx, s_len)] != -1) {
		return mem[INDEX(start_idx, end_idx, s_len)];
	}
	int		max = 1;
	int		found = 0;
	int		allFit = end_idx - start_idx + 1;
	for (int i = start_idx; i <= end_idx; i++) {
		int		j = end_idx;
		if (found) {
		}
		for (; i < j; j--) {
			int		temp = 0;
			if (mem[INDEX(i, j, s_len)] != -1) {
				temp = mem[INDEX(i, j, s_len)];
				if (temp > max) {
					max = temp;
				}
				found = 1;
				break;
			} else if (s[i] == s[j]) {
				temp = 2;
				int		start = i + 1;
				int		end = j - 1;

				if (end >= start) {
					temp += longestMem(s, mem, start, end, s_len);
				}
				if (temp > max) {
					max = temp;
				}
				found = 1;
				break;
			}
		}

		if (max >= (allFit)) {
			break;
		}
	}

	mem[INDEX(start_idx, end_idx, s_len)] = max;

	return max;
}

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
	int            *mem = malloc(sizeof(int) * (len * len));

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < (len); j++) {
			mem[INDEX(i, j, len)] = -1;
		}
	}

	return longestMem(s, mem, 0, len - 1, len);


}

/*
int
longestMem(char *s, int **mem, int start_idx, int end_idx)
{
	unsigned int	len = end_idx - start_idx + 1;
	if (len == 0) {
		mem[start_idx][end_idx] = 0;
		return 0;
	}
	if (len == 1) {
		mem[start_idx][end_idx] = 1;
		return 1;
	}
	if (mem[start_idx][end_idx] != -1) {
		return mem[start_idx][end_idx];
	}
	int		max = 1;
	for (int i = start_idx; i <= end_idx; i++) {
		for (int j = end_idx; i < j; j--) {
			int		temp = 0;
			if (mem[i][j] != -1) {
				temp = mem[i][j];
				if (temp > max) {
					max = temp;
				}
				break;

			} else if (s[i] == s[j]) {
				temp = 2;
				int		start = i + 1;
				int		end = j - 1;

				if (end >= start) {
					if (mem[start][end] != -1) {
						temp += mem[start][end];
						printf("%d %d %d\n", mem[start][end], start, end);

					} else {
						temp += longestMem(s, mem, start, end);

					}

				}
				if (temp > max) {
					max = temp;
				}
				break;
			}
		}
	}

	mem[start_idx][end_idx] = max;

	return max;
}

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
	int           **mem = malloc(sizeof(int *) * (len));

	for (int i = 0; i < len; i++) {
		mem[i] = malloc(sizeof(int) * len);
		for (int j = 0; j < len; j++) {
			mem[i][j] = -1;
		}
	}

	return longestMem(s, mem, 0, len - 1);


}
*/
/*
 * int longestPalindromeSubseq(char *s) {
 * 
 * unsigned int	len = strlen(s); if (len == 0) { return 0; } if (len == 1) {
 * return 1; } char           *sub = malloc(sizeof(char) * (len + 1)); int
 * ax = 1; for (int i = 0; i < len; i++) { for (int j = len - 1; j > 0 && i
 * <= j; j--) { if (s[i] == s[j]) { int		start = i + 1; int
 * nd = j - 1; int		temp = 2;
 * 
 * if (start <= end) { strncpy(sub, s + start, end - start + 1); sub[end - start
 * + 1] = '\0'; temp += longestPalindromeSubseq(sub); } if (temp > max) { max
 * = temp; } } } }
 * 
 * return max; }
 */
int
main()
{
	char           *s = "cbbd";
	s = "gphyvqruxjmwhonjjrgumxjhfyupajxbjgthzdvrdqmdouuukeaxhjumkmmhdglqrrohydrmbvtuwstgkobyzjjtdtjroqpyusfsbjlusekghtfbdctvgmqzeybnwzlhdnhwzptgkzmujfldoiejmvxnorvbiubfflygrkedyirienybosqzrkbpcfidvkkafftgzwrcitqizelhfsruwmtrgaocjcyxdkovtdennrkmxwpdsxpxuarhgusizmwakrmhdwcgvfljhzcskclgrvvbrkesojyhofwqiwhiupujmkcvlywjtmbncurxxmpdskupyvvweuhbsnanzfioirecfxvmgcpwrpmbhmkdtckhvbxnsbcifhqwjjczfokovpqyjmbywtpaqcfjowxnmtirdsfeujyogbzjnjcmqyzciwjqxxgrxblvqbutqittroqadqlsdzihngpfpjovbkpeveidjpfjktavvwurqrgqdomiibfgqxwybcyovysydxyyymmiuwovnevzsjisdwgkcbsookbarezbhnwyqthcvzyodbcwjptvigcphawzxouixhbpezzirbhvomqhxkfdbokblqmrhhioyqubpyqhjrnwhjxsrodtblqxkhezubprqftrqcyrzwywqrgockioqdmzuqjkpmsyohtlcnesbgzqhkalwixfcgyeqdzhnnlzawrdgskurcxfbekbspupbduxqxjeczpmdvssikbivjhinaopbabrmvscthvoqqbkgekcgyrelxkwoawpbrcbszelnxlyikbulgmlwyffurimlfxurjsbzgddxbgqpcdsuutfiivjbyqzhprdqhahpgenjkbiukurvdwapuewrbehczrtswubthodv";
	s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	printf("%d\n", longestPalindromeSubseq(s));
}

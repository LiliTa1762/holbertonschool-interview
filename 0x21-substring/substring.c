#include "substring.h"

/**
 * find_substring -  find the possible substrings in a list of words
 * @s: string to scan
 * @words: array of words
 * @nb_words: number of elements in the array words
 * @n: holds the address at which to store the number of elements
 * Return:  an allocated array, storing each index in s or NULL 
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int counter, str_len, words_len, check, current_index, i, j, k;
	int *array_idx, *match_idx;

	if (nb_words == 0 || !s || !words || !n)
		return (NULL);
	str_len = strlen(s);
	array_idx = malloc(str_len * sizeof(int));
	match_idx = malloc(nb_words * sizeof(int));
	if (!match_idx || !array_idx)
		return (NULL);
	words_len = strlen(words[0]);
	counter = 0;
	for (i = 0; i <= str_len - nb_words * words_len; i++)
	{
		memset(match_idx, 0, nb_words * sizeof(int));
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				current_index = i + j * words_len;
				check = strncmp(s + current_index, *(words + k), words_len);
				if (!*(match_idx + k) && !check)
				{
					*(match_idx + k) = 1;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (j == nb_words)
		{
			*(array_idx + counter) = i;
			counter += 1;
		}
	}
	free(match_idx);
	*n = counter;
	return (array_idx);
}

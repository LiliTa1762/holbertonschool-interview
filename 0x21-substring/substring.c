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

	int current_idx, counter, str_len, word_len, check_str, i, j, k;
	int *match, *idx_array;

	if (!s || !words || !n || nb_words == 0)
		return (NULL);
	str_len = strlen(s);
	word_len = strlen(words[0]);
	idx_array = malloc(str_len * sizeof(int));
	if (!idx_array)
		return (NULL);
	match = malloc(nb_words * sizeof(int));
	if (!match)
		return (NULL);
	for (i = counter = 0; i <= str_len - nb_words * word_len; i++)
	{
		memset(match, 0, nb_words * sizeof(int));
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				current_idx = i + j * word_len;
				check_str = strncmp(s + current_idx, *(words + k), word_len);
				if (!*(match + k) && !check_str)
				{
					*(match + k) = 1;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (j == nb_words)
			*(idx_array + counter) = i, counter += 1;
	}
	free(match);
	*n = counter;
	return (idx_array);
}

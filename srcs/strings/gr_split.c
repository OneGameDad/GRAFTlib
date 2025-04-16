/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpellech <gpellech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:20:03 by gpellech          #+#    #+#             */
/*   Updated: 2025/04/13 13:21:15 by gpellech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graftlib.h"
#include <stdlib.h>

/** Determines the number of words a string should be split into
 * @param s The string in question
 * @param c The dividing character
 * @returns The number of array elements needed
 */
static int	numwords(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			++count;
		++i;
	}
	return (count);
}

/** Writes the individial strings to the array
 * @param result The array that holds the strings
 * @param s The string being splut
 * @param word The element of the array
 * @returns 1 when successful, 0 otherwise
 */
static int	split_words(t_arena *arena, char **result, char const *s, char c)
{
	int		start;
	int		end;
	int		word;

	end = 0;
	start = 0;
	word = 0;
	while (s[end])
	{
		if (s[end] == c || s[end] == 0)
			start = end + 1;
		if (s[end] != c && (s[end + 1] == c || s[end + 1] == 0))
		{
			result[word] = alloc_data(arena, sizeof(char)
					* (end - start + 2));
			gr_strlcpy(result[word], (s + start), end - start + 2);
			word++;
		}
		end++;
	}
	result[word] = 0;
	return (1);
}

char	**gr_strsplit(t_arena **arena, char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = alloc_data(arena, sizeof(char *)
			* (numwords(s, c) + 1));
	split_words(arena, result, s, c);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:48:53 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:10:06 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Count the number of words in a string delimited by a specified character.
 *
 * @param s String to count words in.
 * @param c Delimiter character.
 *
 * @return Returns the number of words in the string.
 */
static char	ft_countwords(char *s, char c)
{
	int	i;
	int	wordcount;

	i = 0;
	wordcount = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			wordcount++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (wordcount);
}

/**
 * Get the length of a word in a string until a specified delimiter character.
 *
 * @param s String containing the word.
 * @param c Delimiter character.
 *
 * @return Returns the length of the word.
 */
static int	ft_wordlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

/**
 * Split a string into an array of words based on a specified
 * delimiter character.
 *
 * @param s String to be split.
 * @param c Delimiter character.
 *
 * @return Returns an array of strings containing the words.
 */
char	**ft_split(char const *s, char c)
{
	char	**words;
	int		wdcount;
	int		j;

	j = 0;
	if (!s)
		return (0);
	wdcount = ft_countwords((char *)s, c);
	words = malloc (sizeof(char *) * (wdcount + 1));
	if (!words)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			words[j] = ft_substr(s, 0, ft_wordlen(s, c));
			j++;
		}
		while (*s && *s != c)
			s++;
	}
	words[j] = 0;
	return (words);
}

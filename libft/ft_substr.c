/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:55:50 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/02 12:46:02 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Create a substring from a string, starting from a specified index and
 * with a specified length.
 *
 * @param s String to create a substring from.
 * @param start Starting index of the substring.
 * @param len Length of the substring.
 *
 * @return Returns a new string containing the substring, or NULL if
 *         memory allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*memalloc;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	memalloc = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	if (!memalloc)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			memalloc[j] = s[i];
			j++;
		}
		i++;
	}
	memalloc[j] = '\0';
	return (memalloc);
}

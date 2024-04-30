/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:33:47 by jofilipe          #+#    #+#             */
/*   Updated: 2024/04/30 14:16:22 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Concatenate two strings.
 *
 * @param str1 First string.
 * @param str2 Second string.
 *
 * @return Returns a new string containing the concatenated content of str1
 *         and str2, or NULL if memory allocation fails.
 */
char	*ft_strjoin(char const *str1, char const *str2)
{
	char			*join;
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;

	i = 0;
	j = 0;
	if (!str1 || !str2)
		return (0);
	size = ft_strlen(str1) + ft_strlen(str2);
	join = (char *)malloc(sizeof(char) * (size + 1));
	if (!join)
		return (0);
	while (str1[j])
		join[i++] = str1[j++];
	j = 0;
	while (str2[j])
		join[i++] = str2[j++];
	join[i] = '\0';
	return (join);
}

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
	char		*memall;
	int			len;
	int			i;
	int			j;

	i = 0;
	j = 0;
	len = ft_strlen(str1) + ft_strlen(str2);
	memall = malloc((len + 1) * sizeof(char));
	if (!memall)
		return (NULL);
	while (str1 && *(str1 + i))
	{
		*(memall + i) = *(str1 + i);
		i++;
	}
	while (str2 && *(str2 + j))
		*(memall + i++) = *(str2 + j++);
	*(memall + i) = '\0';
	return (memall);
}

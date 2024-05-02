/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:33:47 by jofilipe          #+#    #+#             */
/*   Updated: 2024/05/02 16:18:48 by bbento-e         ###   ########.fr       */
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
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;
	size_t	total_len;

	total_len = (ft_strlen(s1) + ft_strlen(s2));
	str = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

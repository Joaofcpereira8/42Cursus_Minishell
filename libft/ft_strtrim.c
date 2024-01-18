/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:42:27 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:13:21 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Trim characters specified in the set from the beginning and end of a string.
 *
 * @param s1 String to trim.
 * @param set Set of characters to trim.
 *
 * @return Returns a new string with leading and trailing characters from
 *         set removed, or NULL if memory allocation fails.
 */
char	*ft_strtrim(char *s1, char *set)
{
	char	*result;
	int		start;
	int		end;

	start = 0;
	if (!s1)
		return (0);
	end = ft_strlen((char *)s1);
	while (s1[start] && ft_strchr((char *)set, s1[start]))
		start++;
	while (end > start && ft_strchr((char *)set, s1[end - 1]))
		end--;
	result = ft_substr(s1, start, (end - start));
	return (result);
}

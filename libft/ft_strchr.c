/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:41:58 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:10:16 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Locate the first occurrence of a character in a string.
 *
 * @param str String to search.
 * @param c Character to locate.
 *
 * @return Returns a pointer to the first occurrence of the character
 * in the string, or NULL if the character is not found.
 */
char	*ft_strchr(const char *str, int c)
{
	while (*str != c && *str != '\0')
		str++;
	if (*str == '\0')
	{
		if (c != '\0')
			return (NULL);
		else
			return ((char *)str);
	}
	return ((char *)str);
}

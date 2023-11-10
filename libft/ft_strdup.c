/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:17:46 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:10:26 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Duplicate a string.
 *
 * @param str String to be duplicated.
 *
 * @return Returns a pointer to the duplicated string, or NULL if memory
 *         allocation fails.
 */
char	*ft_strdup(const char *str)
{
	char	*memalloc;
	int		i;

	i = 0;
	memalloc = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (memalloc == NULL)
		return (NULL);
	while (str[i])
	{
		memalloc[i] = str[i];
		i++;
	}
	memalloc[i] = '\0';
	return (memalloc);
}

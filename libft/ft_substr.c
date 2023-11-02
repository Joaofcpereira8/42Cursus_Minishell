/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:55:50 by jofilipe          #+#    #+#             */
/*   Updated: 2022/11/29 16:59:03 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

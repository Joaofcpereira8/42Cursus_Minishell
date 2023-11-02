/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:33:47 by jofilipe          #+#    #+#             */
/*   Updated: 2022/11/29 16:57:58 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

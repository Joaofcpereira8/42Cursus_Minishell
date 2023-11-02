/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkconversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:28:44 by jofilipe          #+#    #+#             */
/*   Updated: 2022/12/07 12:08:45 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_checkconversion(char var)
{
	char	*conversion;
	int		i;

	i = 0;
	conversion = "cspdiuxX%";
	while (conversion[i])
	{
		if (var == conversion[i])
			return (conversion[i]);
		i++;
	}
	return (0);
}

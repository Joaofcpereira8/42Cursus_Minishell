/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_checkconversion.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:28:44 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:08:19 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Check if a character is a valid conversion specifier in ft_printf.
 *
 * @param var Character to be checked.
 *
 * @return Returns the character if it is a valid conversion specifier.
 *         Returns 0 if the character is not a valid specifier.
 */
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

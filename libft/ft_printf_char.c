/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:28:50 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:08:10 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Print a character to the standard output.
 *
 * @param c Character to be printed.
 *
 * @return Returns the number of characters printed (1).
 */
int	ft_printf_char(char c)
{
	write(1, &c, 1);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:17:30 by jofilipe          #+#    #+#             */
/*   Updated: 2024/01/17 12:17:30 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes a single character to the standard output.
 *
 * The `ft_putchar` function writes the character
 * `c` to the standard output (file descriptor 1).
 *
 * @param c The character to be written to the standard output.
 */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

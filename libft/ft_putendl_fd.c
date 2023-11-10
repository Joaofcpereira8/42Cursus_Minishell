/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:18:18 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/10 14:09:32 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Write a string followed by a newline character to the specified
 * file descriptor.
 *
 * @param s String to be written.
 * @param fd File descriptor to write to.
 */
void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (!s || !fd)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

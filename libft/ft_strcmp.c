/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:10:44 by jofilipe          #+#    #+#             */
/*   Updated: 2024/01/04 12:10:46 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares two strings lexicographically.
 *
 * The `ft_strcmp` function compares the two strings
 * `s1` and `s2` lexicographically.
 * It compares each corresponding character in the strings until a difference
 * is encountered or one of the strings
 * is terminated by a null character ('\0').
 *
 * @param s1 Pointer to the first null-terminated string to be compared.
 * @param s2 Pointer to the second null-terminated string to be compared.
 *
 * @return An integer greater than, equal to, or less than 0, according to
 * whether `s1` is greater than, equal to, or less than `s2`. The comparison
 * is based on the ASCII values of the characters.
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

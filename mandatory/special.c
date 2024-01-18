/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:15:45 by bbento-e          #+#    #+#             */
/*   Updated: 2024/01/10 10:10:35 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	iseven(int s_trig)
{
	if(s_trig % 2 != 0)
		return (-1);
	return (0);
}

int	check_spec(char **str)
{
	int		i;
	int		j;
	int		s_trig;
	char	s_char;

	j = 0;
	s_trig = 0;
	while (str[j])
	{
		i = 0;
		while (str[j][i] != '\0')
		{
			if(str[j][i] == '\"' || str[j][i] == '\'' || str[j][i] == '\\')
			{
				if (s_trig == 0)
					s_char = str[j][i];
				if (str[j][i] == s_char)
					s_trig++;
			}
			i++;
		}
		j++;
	}
	return (iseven(s_trig));
}

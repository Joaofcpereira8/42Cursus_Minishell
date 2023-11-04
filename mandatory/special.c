/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:15:45 by bbento-e          #+#    #+#             */
/*   Updated: 2023/11/04 19:40:10 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int iseven(int s_trig)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_verif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:19:52 by jofilipe          #+#    #+#             */
/*   Updated: 2024/01/23 18:19:52 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

bool	metacharacters_verif(void)
{
	int		i;
	char	meta;
	bool	is_meta;

	i = -1;
	meta = '\"';
	is_meta = false;
	if (is_every_space(mini_shell()->input) == -1)
		return (false);
	while (mini_shell()->input[++i])
	{
		if (is_meta && mini_shell()->input[i] == meta)
			is_meta = false;
		else if (!is_meta && ft_strchr("\"\'", mini_shell()->input[i]))
		{
			meta = mini_shell()->input[i];
			is_meta = true;
		}
	}
	if (is_meta)
		return (pars_error("u_c", 2));
	return (true);
}
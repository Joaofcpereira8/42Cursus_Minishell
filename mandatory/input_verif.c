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

int	figure_out(void)
{
	if (!metacharacters_verif())
		return (-1);
	read_metachar();
	return (0);
}

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
		return (pars_error('q', 2));
	return (true);
}

void	read_metachar(void)
{
	int	i;

	i = 0;
	while (mini_shell()->input[i])
	{
		if (mini_shell()->input[i] == ' ')
			i++;
		else if (mini_shell()->input[i] == '|')
			i += conv_to_token(ft_strdup("|"), piped);
		else if (mini_shell()->input[i] == '>')
			i += conv_to_token(ft_strdup(">"), red_in);
		else if (mini_shell()->input[i] == '<')
			i += conv_to_token(ft_strdup("<"), red_out);
		else if (!ft_strncmp(&mini_shell()->input[i], ">>", 2))
			i += conv_to_token(ft_strdup(">>"), red2_in);
		else if (!ft_strncmp(&mini_shell()->input[i], "<<", 2))
			i += conv_to_token(ft_strdup("<<"), red2_out);
	}
}

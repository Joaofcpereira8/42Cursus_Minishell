/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_verif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:19:52 by jofilipe          #+#    #+#             */
/*   Updated: 2024/03/19 11:20:17 by jofilipe         ###   ########.fr       */
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
	bool	db_quote;

	i = -1;
	meta = '\"';
	db_quote = false;
	if (is_every_space(mini_shell()->input) == -1)
		return (false);
	while (mini_shell()->input[++i])
	{
		if (db_quote && mini_shell()->input[i] == meta)
			db_quote = false;
		else if (!db_quote && ft_strchr("\"\'", mini_shell()->input[i]))
		{
			meta = mini_shell()->input[i];
			db_quote = true;
		}
	}
	if (db_quote)
		return (pars_error('q', 2));
	return (true);
}

int find_sym(char *quote, char *str)
{
	int		skip;
	char	*token;
	bool	can_join;

	skip = ft_strlen_skp(str, quote);
	can_join = is_joinable(str, quote, skip);
	token = ft_substr(str, 0, skip);
	if (quote[0] == '=')
		conv_to_token(token, dbl_quote, can_join);
	else if (quote[0] == '\'')
		conv_to_token(token, sng_quote, can_join);
	else
		conv_to_token(token, rest, can_join);
	return (skip);
}

bool	is_joinable(char *str, char *match, int skip)
{
	if (!str[skip])
		return (false);
	if (!ft_strcmp(SYM, match) && ft_strchr(QUO, str[skip]))
		return (true);
	if (ft_strchr(SYM, match[0]) && !ft_strchr(QUO, str[skip + 1]))
		return (true);
	return (false);
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
			i += conv_to_token(ft_strdup("|"), piped, 0);
		else if (mini_shell()->input[i] == '>')
			i += conv_to_token(ft_strdup(">"), red_in, 0);
		else if (mini_shell()->input[i] == '<')
			i += conv_to_token(ft_strdup("<"), red_out, 0);
		else if (!ft_strncmp(&mini_shell()->input[i], ">>", 2))
			i += conv_to_token(ft_strdup(">>"), red_apnd, 0);
		else if (!ft_strncmp(&mini_shell()->input[i], "<<", 2))
			i += conv_to_token(ft_strdup("<<"), red_hdoc, 0);
		else if (mini_shell()->input[i] == '"')
			i += find_sym("\"", &mini_shell()->input[i + 1]) + 2;
		else if (mini_shell()->input[i] == '\'')
			i += find_sym("'", &mini_shell()->input[i + 1]) + 2;
		else
			i += find_sym(SYM, &mini_shell()->input[i]);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:00:52 by jofilipe          #+#    #+#             */
/*   Updated: 2024/04/30 15:35:30 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	expand_variable(t_token *token)
{
	char	*value;
	char	*key;
	char	*tmp;
	char	*new_str;

	tmp = ft_strnstr(token->str, "$", ft_strlen(token->str));
	while (ft_strnstr(token->str, "$", ft_strlen(token->str)))
	{
		if (ft_strlen(token->str) == 1)
			break ;
		key = find_key(tmp);
		if (ft_strcmp(key, "$?") == 0)
			value = ft_itoa(mini_shell()->exit_status);
		else
			value = ft_get_env(key);
		if (value)
		{
			new_str = ft_streplace(token->str, key, value);
			free(token->str);
			token->str = ft_strtrim(new_str, "\"");
			free(new_str);
			free(value);
		}
		free(key);
	}
}

char	*find_key(char *str)
{
	char	*tmp;
	int		len;

	len = 0;
	tmp = ft_strnstr(str, "$", ft_strlen(str));
	if (tmp[1] == '?')
		return (ft_strdup("$?"));
	while (ft_isalnum(tmp[len + 1]) || tmp[len + 1] == '_')
		len++;
	return (ft_substr(tmp, 0, len + 1));
}

char	*ft_streplace(char *str, char *old, char *new)
{
	char	*ret;
	char	*tmp;
	char	*ptr;
	int		len;

	if (!str || !old || !new)
		return (NULL);
	len = ft_strlen(str) + ft_strlen(new) - ft_strlen(old);
	ret = ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (NULL);
	ptr = ft_strnstr(str, old, ft_strlen(str));
	if (!ptr)
		return (NULL);
	tmp = ft_substr(str, 0, ptr - str);
	ft_strlcat(ret, tmp, len + 1);
	ft_strlcat(ret, new, len + 1);
	ft_strlcat(ret, ptr + ft_strlen(old), len + 1);
	free(tmp);
	return (ret);
}

void	merge_env_tokens(t_list *env_tokens)
{
	t_list	*aux;
	t_token	*next_token;
	t_token	*curr_token;
	char	*tmp;

	while (env_tokens)
	{
		curr_token = env_tokens->content;
		if (!env_tokens->next)
			return ;
		if (!curr_token->can_join)
		{
			env_tokens = env_tokens->next;
			continue ;
		}
		next_token = env_tokens->next->content;
		tmp = curr_token->str;
		curr_token->str = ft_strjoin(curr_token->str, next_token->str);
		free(tmp);
		curr_token->can_join = curr_token->can_join & next_token->can_join;
		aux = env_tokens->next;
		env_tokens->next = env_tokens->next->next;
		ft_lstdelone(aux, (void *)destroy_token);
	}
}

void	expander(void)
{
	t_list	*current;
	t_token	*token;

	current = mini_shell()->env_token;
	while (current)
	{
		token = ((t_token *)current->content);
		if (token->type == red_apnd)
			current = current->next;
		else if (token->type == dbl_quote || token->type == rest)
			expand_variable(token);
		current = current->next;
	}
	merge_env_tokens(mini_shell()->env_token);
}

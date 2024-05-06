/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:11:46 by bbento-e          #+#    #+#             */
/*   Updated: 2024/04/30 18:52:22 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	handle_minus(void)
{
	char	*temp;

	if (chdir(mini_shell()->oldpwd) == 0)
	{
		temp = mini_shell()->cwd;
		mini_shell()->cwd = getcwd(NULL, 0); // Properly allocate and check for errors
		free(temp);
		printf("%s\n", mini_shell()->cwd);
		return (0);
	}
	else
	{
		perror("Failed to change directory");
		return (err_handler('d', NULL, 0));
	}
}

void	if_oldpwd_not_exists(void)
{
	char	*env_oldpwd;

	env_oldpwd = ft_get_env("OLDPWD");
	if (env_oldpwd)
		mini_shell()->oldpwd = strdup(env_oldpwd); // Make a copy if needed
	free(env_oldpwd);
}

int	mini_cd(char **args)
{
	if (!mini_shell()->oldpwd)
		if_oldpwd_not_exists();
	if (!args[1] && (chdir(getenv("HOME")) == 0))
	{
		free(mini_shell()->oldpwd);
		mini_shell()->oldpwd = mini_shell()->cwd;
		mini_shell()->cwd = getcwd(NULL, 0);
	}
	else if (args[1][0] == '-' && !args[1][1])
		return (handle_minus());
	else if (chdir(args[1]) == 0 || ((args[1][0] == ' ' || (args[1][0] == '~'
			&& !args[1][1]) || (args[1][0] == '-' && args[1][1] == '-'
			&& !args[1][2]) || !args[1]) && chdir("/home/") == 0))
	{
		mini_shell()->oldpwd = mini_shell()->cwd;
		mini_shell()->cwd = getcwd(NULL, 0);
	}
	else
		return (err_handler('d', args[1], 1));
	mini_shell()->exit_status = 0;
	return (0);
}

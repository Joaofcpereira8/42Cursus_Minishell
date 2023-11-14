/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:26:42 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/14 15:10:55 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status = 0;

/**
 * Main program.
 *
 * @param argc Necessita de apenas 1 arg;
 * @param argv Vai ser o minishell;
 * @param envp Variaveis de ambiente.
 *
 */

int main(int argc, char *argv[], char **env)
{
	(void)argv;
	char	input[MAX_INPUT_SIZE];
	char	*user;
	char	*session;

	if (argc > 1)
		return(err_handler('a'));
	else
	{
		ft_get_env(&user, &session);
		while (1)
		{
			printf("%s@%s$ ", user, session);
			if (fgets(input, sizeof(input), stdin) == NULL)
			{
				perror("fgets");
				exit(EXIT_FAILURE);
			}
		}
		size_t len = strlen(input);
		if (len > 0 && input[len - 1] == '\n')
		{
			input[len - 1] = '\0';
		}
		char *args[] = {input, NULL};
		exec_command(args, env);
	}
	return (0);
}

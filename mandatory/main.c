/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:26:42 by jofilipe          #+#    #+#             */
/*   Updated: 2023/11/16 18:18:53 by bbento-e         ###   ########.fr       */
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
	t_env_detail envi;
/*	char	*user = NULL;
	char	*session = NULL;*/

	if (argc > 1)
		return(err_handler('a'));
	else
	{
		ft_get_env(&envi);
		while (1)
        {
            printf("%s@%s:~%s$ ", envi.user, envi.sesh, envi.path);
            if (fgets(input, sizeof(input), stdin) == NULL) {
                perror("fgets");
                exit(EXIT_FAILURE);
            }
            size_t len = strlen(input);
            if (len > 0 && input[len - 1] == '\n') {
                input[len - 1] = '\0';
            }
            char *args[] = {input, NULL};
            exec_command(args, env);
        }
	}
	return (0);
}

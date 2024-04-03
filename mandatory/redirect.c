/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:05:45 by jofilipe          #+#    #+#             */
/*   Updated: 2024/04/03 14:31:58 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

/*
int	test_char(const unsigned char c)
{
	//holds an identifier for an open file
	int	file_desc;
	//will hold a duplicate copy of the stdout identifier
	int	copy_out;
	//will hold the value of the test outcome
	//(-1) if fail/(0) if success
	int	outcome;

	init_redirect(&file_desc, &copy_out);
	ft_putchar(c);
	reset_output(&copy_out);
	outcome = compare_results(c, file_desc);
	return (outcome);
}

static void	init_redirect(int *file_desc, int *copy_out)
{
	//nao podemos usar fileno
	*file_desc = open("temp", O_RDWR|O_CREAT|O_TRUNC, 0777);
	*copy_out = dup(fileno(stdout));
	dup2(*file_desc, fileno(stdout));
}

static void	reset_output(int *copy_out)
{
	dup2(*copy_out, fileno(stdout));
	close(*copy_out);
}

static int compare_results(const unsigned char c, const int fd)
{
	FILE  *file;
	unsigned char res;  file = fdopen(fd, "r");
	rewind(file);
	fscanf(file, "%c", &res);
	if (res != c)
	{
		printf("FAILED: Error in ft_putchar\n");
		printf("Used char %c (%d), but got %c (%d)\n", c, c, res, res);
		return (-1);
	}
	clean_up(file);
	return (0);
}

static void clean_up(FILE * file)
{
	if (fclose(file))
	{
		fprintf(stderr, "Cannot close temp file\n");
		exit (1);
	}
	if (remove ("temp"))
	{
		fprintf(stderr, "Cannot remove temp file\n");
		exit (1);
	}
}*/

/**
 * @brief Redirections
 *
 * @param comm Comunismo
 * @param token Tokens
 */
int	redirects(char **comm, t_meta_tok token)
{
	int	i;

	i = 0;
	while (comm[i])
	{
		if (token == red_out)
			return (handle_output(comm));
		else if (token == red_apnd)
			return (handle_appnd(comm));
		else if (token == red_in)
			return (handle_input(comm));
		else if (token == red_hdoc)
			return (handle_hdoc(comm));
		i++;
	}
	return (-1);
}

int	handle_input(char **comm)
{
	mini_shell()->fd_in = open(comm[1], O_RDONLY);
	return (0);
	/* if(mini_shell()->fd_in)
		return (0);
	return (err_handler('r', "<")); */
}

int	handle_output(char **comm)
{
	(mini_shell()->fd_in) = open(comm[1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
 	printf("entered output with command %s\n", comm[6]);
    (mini_shell()->fd_out) = open(comm[6], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	printf("opened file with fd %i\n", mini_shell()->fd_out);
	if((mini_shell()->fd_out) == -1)
		return (err_handler('r', ">"));
	printf("attempting dup2\n");
	dup2(mini_shell()->fd_out, 1);
	printf("closing fd %i\n", mini_shell()->fd_out);
	close(mini_shell()->fd_out);
	return (0);
}

int	handle_hdoc(char **comm)
{
	mini_shell()->fd_in = heredoc(comm[1]);
	if(mini_shell()->fd_in)
		return (0);
	return (err_handler('r', "<<"));
}

int	handle_appnd(char **comm)
{
	mini_shell()->fd_in = open(comm[1], O_WRONLY | O_CREAT | O_APPEND, 0666);
	return (0);
	/* if(mini_shell()->fd_in)
		return (0);
	return (err_handler('r', ">>")); */
}

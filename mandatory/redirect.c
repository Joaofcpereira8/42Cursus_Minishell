/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:05:45 by jofilipe          #+#    #+#             */
/*   Updated: 2024/03/19 00:31:51 by bbento-e         ###   ########.fr       */
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


int	redirects(t_data *data, char **comm, t_meta_tok token)
{
	int	i;

	i = 0;
	while (comm[i])
	{
		if (token == red_apnd)
			return (handle_appnd(data, comm));
		else if (token == red_hdoc)
			return (handle_hdoc(data, comm));
		else if (token == red_in)
			return (handle_input(data, comm));
		else if (token == red_out)
			return (handle_output(data, comm));
		i++;
	}
	return (-1);
}

int	handle_input(t_data *data, char **comm)
{
	(void)data;
	mini_shell()->fd_in = open(comm[1], O_RDONLY);
	if(mini_shell()->fd_in)
		return (0);
	return (err_handler('r', "<"));
}

/* int handle_output(t_data *data, char **comm) {
    (void)data;

    // Find the '>' operator
    int i = 0;
    while (comm[i] && strcmp(comm[i], ">") != 0) {
        i++;
    }

    // Check if '>' was found and if there's a word after it
    if (comm[i] && comm[i + 1]) {
        // Open the file
        int fd_out = open(comm[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
        if (fd_out == -1) {
            return err_handler('r', ">");
        }

        // Save the current standard output
        int stdout_copy = dup(STDOUT_FILENO);

        // Replace standard output with the file
        dup2(fd_out, STDOUT_FILENO);

        // Execute your command here

        // Restore the standard output
        dup2(stdout_copy, STDOUT_FILENO);

        // Close the file descriptors
        close(fd_out);
        close(stdout_copy);

        return 0;
    } else {
        // Handle error: no filename provided
        return -1;
    }
} */

int	handle_output(t_data *data, char **comm)
{
	printf("entered output with command %s\n", comm[6]);
	(void)data;
	mini_shell()->fd_out = open(comm[6], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if(mini_shell()->fd_out == -1)
		return (err_handler('r', ">"));
	dup2(mini_shell()->fd_out, 1);
	close(mini_shell()->fd_out);
	return (0);
}

int	handle_hdoc(t_data *data, char **comm)
{
	(void)data;
	mini_shell()->fd_in = heredoc(comm[1]);
	if(mini_shell()->fd_in)
		return (0);
	return (err_handler('r', "<<"));
}

int	handle_appnd(t_data *data, char **comm)
{
	(void)data;
	mini_shell()->fd_in = open(comm[1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	if(mini_shell()->fd_in)
		return (0);
	return (err_handler('r', ">>"));
}

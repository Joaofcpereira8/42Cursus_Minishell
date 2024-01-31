/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:26:52 by jofilipe          #+#    #+#             */
/*   Updated: 2024/01/26 12:23:54 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../../libft/libft.h"
# include "env.h"
# include "tokens.h"

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>

# define MAX_INPUT_SIZE 1024

typedef enum e_type
{
	KEYWORD,
	IDENTIFIERS,
	OPERATORS,
	LITERALS,
	PUNCTUATION,
	COMMENTS,
	SPECIAL_SYMBOLS,
	WHITESPACE,
	EOF_TOKE,
}				t_type;

typedef struct s_data
{
	int			fd;
	char		*oldpwd;
	char		*pwd;
	int			path_change;
	int			pid;
	char		*comm;
	char		**paths;
}				t_data;

//working on the real deal.
//experimentar input como char **
//e quando encontra um | ou >>
//incrementa para o proximo array
typedef struct s_mini_env
{
	int		fd_in;
	int		fd_out;
	int		exit_status;
	int		cmd_num;
	char	*cwd;
	char	*input;
	char	*prompt;
	char	**env;
	char	**path;
	t_list	*env_amb_list;
	t_list	*env_token;
}			t_mini_env;

// ------ EXECVE ------ //
void		get_paths(t_data *data);
char		*path_join(char *path, char *cm);
void		exec_command(t_data *data, char **args, t_mini_env *envp);

// ------ USER ------ //
char		pwd_finder(t_data *data);
void		get_prompt(t_mini_env *envp);

// ----- BUILT-INs ----- //
int			minipdw(t_data *data);
int			minicd(t_data *data, char **args);
void		minienv(t_list *env_amb_list);
int			miniecho(t_data *data, char **args);
void		miniexit(t_data *data, char **args);
int			miniunset(t_data *data, char **args);
int			miniexport(t_data *data, char **args);
int			built_type(t_data *data, char **args);
int			built_type_next(t_data *data, char **args);

// ----- PARSER ----- //
int			iseven(int s_trig);
int			check_spec(char **str);
void		parser(void);

// ----- REDIRECTS ---- //
int			redirects(t_data *data, char **comm);
int			handle_hdoc(t_data *data, char **comm);
int			handle_appnd(t_data *data, char **comm);
int			handle_input(t_data *data, char **comm);
int			handle_output(t_data *data, char **comm);

// ------ ERRORS ----- //
int			err_handler(char c, char *cmd);
int			check_args(char **str);

// ----- UTILS ----- //
int			ft_strlen_flag(char const *str, char flag);
int			sz_env_list(char **env);
void		list_delete(void *list);
char		**add_to_mat(char **mat1, char *str);
int			is_every_space(char *str);
int			pars_error(char c, int ex_stat);

// ---- VARIABLE_GLOBAL ---- //
t_mini_env	*mini_shell(void);

// ---- ENV ---- //
void		env_update(void);
char		**env_to_mat(t_list *env_list);
char		*ft_get_env(char *type);

// ---- ENV_VAR_LIST ---- //
t_list		*envlist(char **env);
void		add_env_vars(t_list **envlist, char *container);
t_env		*new_env_list(char *type, char *info);
t_env		*env_verif(t_list *env, char *type);

// ---- INPUT_VERIF ---- //
int			figure_out(void);

/**
 * @brief Checks for the balanced use of quotes in a given input string.
 *
 * This function ensures that quotes (single or double) in
 * the input string are properly balanced, i.e., every opening
 * quote has a corresponding closing quote. It also handles the case of unclosed quotes.
 *
 * @return Returns true if quotes are balanced; otherwise,
 * returns false and sets the exit status for an unclosed quote.
 */
bool		metacharacters_verif(void);
void		read_metachar(void);

// ---- TOKENS ----



#endif

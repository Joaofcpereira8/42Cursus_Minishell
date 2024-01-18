/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:26:52 by jofilipe          #+#    #+#             */
/*   Updated: 2024/01/10 09:55:05 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../../libft/libft.h"
# include "env.h"


# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>


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

typedef struct s_env_detail
{
	char	*user;
	char	*sesh;
	char	*path_env;
	char	*prompt;
}				t_env_detail;

typedef struct s_token
{
	char	*str;
	t_type	type;
}				t_token;

typedef struct s_data
{
	char 		*oldpwd;
	char		*pwd;
	int			pid;
	char		*comm;
	char		*cwd;
	char 		**paths;
	int 		path_change;
}				t_data;

//working on the real deal.
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
}			t_mini_env;

// ------ EXECVE ------
void		get_paths(t_data *data);
char		*path_join(char *path, char *cm);
void		exec_command(t_data *data, char **args, char **env);

// ------ USER ------
char		pwd_finder(t_data *data);
void		ft_get_env1(t_env_detail *envi);

// ----- BUILT-INs -----
int			minipdw(t_data *data);
int			minicd(t_data *data, char **args);
void		minienv(t_list *env_amb_list);
int			miniecho(t_data *data, char **args);
void		miniexit(t_data *data, char **args);
int			miniunset(t_data *data, char **args);
int			miniexport(t_data *data, char **args);
int			built_type(t_data *data, char **args);
int			built_type_next(t_data *data, char **args);

// ----- PARSER -----
int			iseven(int s_trig);
int			check_spec(char **str);

// ------ ERRORS -----
int			err_handler(char c, char *cmd);
int			check_args(char **str);

// ----- UTILS -----
int			ft_strlen_flag(char const *str, char flag);
int			sz_env_list(char **env);
void		list_delete(void *list);
char		**add_to_mat(char **mat1, char *str);

// ---- VARIABLE_GLOBAL ----
t_mini_env	*mini_shell(void);

// ---- ENV ----
void		env_update(void);
char		**env_to_mat(t_list *env_list);
char		*ft_get_env(char *type);

// ---- REDIRECT ----
//int			test_char(const unsigned char c);
//static void	init_redirect(int *file_desc, int *copy_out);
//static void	reset_output(int *copy_out);
//static int compare_results(const unsigned char c, const int fd);
//static void clean_up(FILE * file);

// ---- ENV_VAR_LIST ----
t_list		*envlist(char **env);
void		add_env_vars(t_list **envlist, char *container);
t_env		*new_env_list(char *type, char *info);
t_env		*env_verif(t_list *env, char *type);
#endif

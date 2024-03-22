/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:26:52 by jofilipe          #+#    #+#             */
/*   Updated: 2024/03/22 18:25:45 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../../libft/libft.h"
# include "env.h"

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <signal.h>
# include <errno.h>
# include <sys/types.h>

# define SYM	"<>\'\"| "
# define QUO	"\'\""
# define SPE	"<>| "

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

typedef enum e_meta_tok
{
	red_in,
	red_apnd,
	red_out,
	red_hdoc,
	piped,
	sng_quote,
	dbl_quote,
	rest,
}			t_meta_tok;

typedef enum e_operations
{
	READ,
	NEXT,
	AFTER,
	RESET
}			t_operations;

//typedef enum e_meta_tok t_meta_tok;

typedef struct s_token
{
	char		*str;
	t_meta_tok	type;
	bool		can_join;
}				t_token;

/**
 * @brief A structure to represent a node of an Abstract Syntax Tree
 *
 * @param token The token associated with the node
 * @param args The arguments of the token
 * @param index Used if the token represents a command
 * @param left The left child of the node
 * @param right The right child of the node
 */
typedef struct s_a_s_tree
{
	t_token				*token;
	char				**args;
	int					index;
	struct s_a_s_tree	*right;
	struct s_a_s_tree	*left;
}			t_a_s_tree;

/**
 *@brief "Global" variable that's used in the majority
 *of the project
 *
 *@param fd_in Standard input fd
 *@param fd_out Standard output fd
 *@param exit_status Last command's exit status
 *@param cmd_num Number of commands
 *@param cwd Current working directory
 *@param input Input in the command line
 *@param prompt Prompt in the command line
 *@param env Environment ambient's matrix
 *@param path Environment ambient's PATH
 *@param env_amb_list Linked list of the environment variables
 *@param env_token Linked list of metacharacters tokens
 *@param ast Abstract Syntax Tree
 *@param temp_env Linked list of temporary environment variables
*/
typedef struct s_mini_env
{
	int			fd_in;
	int			fd_out;
	int			exit_status;
	int			cmd_num;
	char		*cwd;
	char		*input;
	char		*prompt;
	char		**env;
	char		**path;
	int			**pipes;
	t_list		*env_amb_list;
	t_list		*env_token;
	t_a_s_tree	*ast;
	t_list		*temp_env;
}			t_mini_env;

// ------ MAIN ------ //
/**
 *@brief Uma vez chamada, inicializa a estrutura mini_shell.
 *
 *@param env Variavel de ambiente
 */
void		mini_init(char	**env);

/**
 * @brief Main program.
 *
 * @param argc Necessita de apenas 1 arg;
 * @param argv Vai ser o minishell;
 * @param env Variaveis de ambiente.
 */
int			main(int argc, char **argv, char **envp);

// ------ EXECVE ------ //
void		get_paths(t_data *data);
char		*path_join(char *path, char *cm);
void		exec_command(t_data *data, char **args, t_mini_env *envp);

// ------ USER ------ //
char		pwd_finder(t_data *data);
void		get_prompt(t_mini_env *envp);

// ----- BUILT-INs ----- //
int			minipdw(t_data *data);
void		minienv(t_list *env_amb_list);
int			minicd(t_data *data, char **args);
int			miniecho(t_data *data, char **args);
void		miniexit(t_data *data, char **args);
int			miniunset(t_data *data, char **args);
int			miniexport(t_data *data, char **args);
int			built_type(t_data *data, char **args);
int			built_type_next(t_data *data, char **args);

// ----- INPUT_ANALYSIS ----- //
/**
 * @brief Lê a linha introduzida após o promp e esta é
 * guardada na estrutura mini_shell.
  */
void		input(void);
int			iseven(int s_trig);
int			check_spec(char **str);

// ----- REDIRECTS ---- //
int			heredoc(char *file);
int			handle_hdoc(t_data *data, char **comm);
int			handle_appnd(t_data *data, char **comm);
int			handle_input(t_data *data, char **comm);
int			handle_output(t_data *data, char **comm);
int			redirects(t_data *data, char **comm, t_meta_tok token);

// ------ ERRORS ----- //
int			err_handler(char c, char *cmd);
int			check_args(char **str);

// ----- UTILS ----- //
int			sz_env_list(char **env);
/**
 * @brief Faz free à memória alocada da matriz e o último
 * elemento da matriz tem que ficar NULL.
 *
 * @param list A matriz a fazer free.
  */
void		list_delete(void *list);
int			is_every_space(char *str);
int			pars_error(char c, int ex_stat);
int			ft_strlen_skp(char *str, char *c);
char		**add_to_mat(char **mat1, char *str);
int			ft_strlen_flag(char const *str, char flag);

// ---- VARIABLE_GLOBAL ---- //
t_mini_env	*mini_shell(void);

// ---- ENV ---- //
/**
 * @brief Atualiza as variáveis de ambiente e é chamado cada vez
 * que um comando é executado.
  */
void		env_update(void);

/**
 * @brief Vai à envlisr para encontrar a variável de ambiente que
 * coincide com o TYPE e retorna o valor.
 *
 * @param type Nome da variável.
 * @return char* Ou o valor da variável ou uma string
 * vazia para o novo pointer
 */
char		*ft_get_env(char *type);

/**
 * @brief Converte a lista das variáveis de ambiente para uma matriz para depois
 * puder ser usada quando o execve for chamado.
 *
 * @param env_list A lista das variáveis de ambiente.
 * @return char** Um novo pointer para a matriz de variáveis de ambiente.
 * @return NULL se o malloc falhar.
 */
char		**env_to_mat(t_list *env_list);

// ---- ENV_VAR_LIST ---- //
/**
 * @brief Usada no início do programa para criar a nossa própria
 * lista de variáveis de ambiente, usando as mesmas do sistema.
 *
 * @param envp Matriz das variáveis de ambiente original.
 * @return t_list* Um novo pointer para a lista de variáveis de ambiente.
 * @return NULL se o malloc não funcionar.
  */
t_list		*envlist(char **env);
t_env		*env_verif(t_list *env, char *type);
t_env		*new_env_list(char *type, char *info);
void		add_env_vars(t_list **envlist, char *container);

// ---- INPUT_VERIF ---- //
int			figure_out(void);
bool		metacharacters_verif(void);
int			find_sym(char *quote, char *str);
bool		is_joinable(char *str, char *match, int skip);
void		read_metachar(void);

// ---- INPUT_VERIF2 ---- //
bool		input_analysis(void);
t_token		*scanner(t_operations operations);
bool		pipe_or_redir(t_token *token);
bool		redirection(t_token *token);
bool		is_command(t_token *token);

// ---- EXPANDER ---- //
void		expander(void);
void		expand_variable(t_token *token);
char		*find_key(char *str);
char		*ft_streplace(char *str, char *old, char *new);

// ---- FREE ---- //
void		ft_clean(void *pointer);

// ---- AST_TOKENS ---- //
t_a_s_tree	*ast_new_token(t_token *token);
void		ast_insert(t_a_s_tree **ast, t_a_s_tree *node, bool left);


// ---- PARSER ---- //
void		parser(void);
t_a_s_tree	*parser_pipes(void);
t_a_s_tree	*parser_commands(void);
t_a_s_tree	*extend_command(t_a_s_tree *command);
t_a_s_tree	*extend_pipes(t_a_s_tree *ast, t_a_s_tree *command);

// ---- SIGNALS ---- //
/**
 * @brief Vão ser preparados as rotinas de sinais (signal handler)
 * para SIGINT E SIGQUIT antes de o shell iniciar.
 * SIGINT para ctrl + C
 * SIGQUIT para crtl +
  */
void		signals(void);


// ---- HANDLE_SIGNALS ---- //
void		handle_sigint(int signum);


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

/** @brief Reads metacharacters from the shell's input string and converts them into tokens.
 *
 * This function iterates through the shell's input string and identifies metacharacters,
 * including pipes (|), redirection symbols (<, >, >>, <<), and quotes (single and double).
 * It converts these metacharacters into tokens, which represent commands, arguments,
 * and special constructs in the shell's language.
 *
 * @return None
 */
void		read_metachar(void);

// ---- TOKENS ---- //
t_token		*new_token(char *str, t_meta_tok type, bool join);
t_token		*copy_token(t_token *token);
int			conv_to_token(char *str, t_meta_tok type, bool joinable);
void		destroy_token(t_token *token);

// ---- EXECUTE ---- //
void		pipes_generate(void);
pid_t		execute_pipes(t_a_s_tree *node);

#endif

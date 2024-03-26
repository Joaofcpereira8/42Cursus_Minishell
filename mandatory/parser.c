/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:11:13 by jofilipe          #+#    #+#             */
/*   Updated: 2024/03/20 15:37:24 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_a_s_tree	*parser_pipes(void)
{
	t_a_s_tree	*ast;
	t_a_s_tree	*command;

	command = NULL;
	ast = parser_commands();
	if (!ast)
		return (NULL);
	while (scanner(READ) && scanner(READ)->type == piped)
	{
		scanner(NEXT);
		command = parser_commands();
		ast = extend_pipes(ast, command);
	}
	return (ast);
}

t_a_s_tree	*parser_commands(void)
{
	t_a_s_tree	*cmd;

	cmd = ast_new_token(copy_token(scanner(RESET)));
	if (!cmd)
		return (NULL);
	cmd->index = mini_shell()->cmd_num++;
	while (scanner(READ) && scanner(READ)->type != piped)
	{
		if (scanner(READ)->type >= red_in && scanner(READ)->type <= red_hdoc)
			cmd = extend_command(cmd);
		else
			cmd->args = add_to_mat(cmd->args, ft_strdup(scanner(READ)->str));
		scanner(NEXT);
	}
	return (cmd);
}

t_a_s_tree	*extend_command(t_a_s_tree *command)
{
	t_a_s_tree	*redir;

	redir = ast_new_token(copy_token(scanner(READ)));
	if (!redir)
		return (NULL);
	scanner(NEXT);
	redir->args = add_to_mat(redir->args, ft_strdup(scanner(READ)->str));
	redir->left = command->left;
	command->left = redir;
	return (command);
}

t_a_s_tree	*extend_pipes(t_a_s_tree *ast, t_a_s_tree *command)
{
	t_a_s_tree	*root;

	root = ast_new_token(new_token(ft_strdup("|"), piped, false));
	if (!root)
		return (NULL);
	ast_insert(&root, ast, true);
	ast_insert(&root, command, false);
	return (root);
}

void	parser(void)
{
    scanner(RESET);
    mini_shell()->ast = parser_pipes();
}

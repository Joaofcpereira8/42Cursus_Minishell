/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:22:52 by jofilipe          #+#    #+#             */
/*   Updated: 2023/12/06 12:22:52 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "minishell.h"

/**
 * @brief Struct where will keep env variables
 *
 * @param type Name of the env.
 * @param info Info in each env variable.
 */
typedef struct s_env
{
	char	*type;
	char	*info;
}				t_env;

/**
 * @brief Creates a new node
 *
 * @param type Name of the env.
 * @param info Info in each env variable.
 */
t_env	*new_env(char *type, char *info);

t_env	*add_env();
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:23:33 by jofilipe          #+#    #+#             */
/*   Updated: 2023/12/06 12:24:58 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/env.h"

t_env	*new_env(char *type, char *info)
{
	t_env *env;

	env = ft_calloc(1, sizeof(t_env));
	if (!env)
		return (NULL);
	env->type = type;
	env->info = info;
	return (env);
}


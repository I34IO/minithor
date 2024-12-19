/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razouani <razouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:47:16 by enschnei          #+#    #+#             */
/*   Updated: 2024/12/18 15:07:34 by razouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int count_heredoc(t_token *token)
{
	int i;
	
	i  = 0;
	while(token->next)
	{
		if (ft_strcmp(token->type, "heredoc") == 0)
			i++;
		token = token->next;
	}
	return (i);
}

int is_builtin(t_minishell *minishell, t_token *token)
{
	if (ft_strcmp(token->value, "echo") == 0)
		ft_echo(token);
	else if (ft_strcmp(token->value, "cd") == 0)
		ft_cd(token, minishell->env);
	else if (ft_strcmp(token->value, "pwd") == 0)
		ft_pwd(token);
	else if (ft_strcmp(token->value, "env") == 0)
		ft_env(minishell);
	else if (ft_strcmp(token->value, "export") == 0)
		ft_export(minishell->env, token);
	else 
		return(0);
    return (1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razouani <razouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:54:39 by enschnei          #+#    #+#             */
/*   Updated: 2024/12/16 18:26:07 by razouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"
#include <signal.h>

int main(int ac, char **av, char **ev)
{
	(void) ac;
	(void) av;
	t_pipex pipex;
	t_token *token;
	t_minishell minishell;

	token = ft_calloc(sizeof(t_token), 1);
	pipex.ev = ev;
	creat_the_prompt(ev, &pipex, token, &minishell);
	return (EXIT_SUCCESS);
}


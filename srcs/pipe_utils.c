/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roane <roane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:53:42 by enschnei          #+#    #+#             */
/*   Updated: 2025/03/19 22:11:21 by roane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char	*find_the_path(char **ev, t_pipex *pipex)
{
	int	i;

	i = 0;
	pipex->ligne_path = NULL;
	while (ev[i])
	{
		if (ft_strncmp(ev[i], "PATH=", 5) == 0)
		{
			pipex->ligne_path = ev[i];
			break ;
		}
		i++;
	}
	if (access(pipex->command_1, F_OK | X_OK) == 0)
		check_permissions(pipex->command_1);
	return (pipex->ligne_path);
}

char	**split_the_path(t_pipex *pipex)
{
	if (!pipex->ligne_path)
		return (NULL);
	pipex->path = ft_split(pipex->ligne_path + 5, ':');
	if (!pipex->path)
	{
		ft_putstr_fd("3 No such file or directory\n", 2);
	}
	return (pipex->path);
}

char	*search_the_path(t_pipex *pipex, char *command)
{
	int		i;
	char	*tmp;
	char	*path;

	if (pipex->path == NULL)
		return (NULL);
	i = 0;
	tmp = ft_strjoin("/", command);
	if (!tmp)
		return (NULL);
	while (pipex->path[i])
	{
		path = ft_strjoin(pipex->path[i], tmp);
		if (!path)
			return (free(tmp), NULL);
		if (access(path, F_OK | X_OK) == 0)
			return (free(tmp), path);
		free(path);
		i++;
	}
	free(tmp);
	return (NULL);
}

char	*get_the_command(t_pipex *pipex)
{
	char	*path;
	
	if (!pipex->command_1)
	{
		ft_putstr_fd("Malloc error\n", 2);
		exit(EXIT_FAILURE);
	}
	if (!ft_strchr(pipex->command_1, '/') && pipex->command_1[0] != '.')
	{
		path = search_the_path(pipex, pipex->command_1);
		if (!path)
		{
			ft_putstr_fd("bash: ", 2);
			ft_putstr_fd(pipex->command_1, 2);
			ft_putstr_fd(": command not found\n", 2);
			return (NULL);
		}
		return (path);
	}
	if (access(pipex->command_1, F_OK | X_OK) != 0)
		return (pipex->command_1);
	return (NULL);
}

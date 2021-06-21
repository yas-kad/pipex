/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:27:57 by yait-kad          #+#    #+#             */
/*   Updated: 2021/06/13 19:28:00 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_path(char **env)
{
	char **env_paths;
	int i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH", env[i], 4) == 0)
		{
			env_paths = ft_split(env[i], '=');
			break;
		}
		i++;
	}
	return(ft_split(env_paths[1], ':'));
}

void	execution(char *comd, char **env)
{
	char **paths_env;
	char *path;
	char *tmp;
	char **cmd;

	paths_env = get_path(env);
	cmd = ft_split(comd, ' ');
	path = NULL;
	while (*paths_env)
	{
		tmp = ft_strjoin(ft_strjoin(*paths_env, "/"), cmd[0]);
		if (access(tmp, F_OK) == 0)
		{
			path = tmp;
			break;
		}
		paths_env++;
	}
	if (path == NULL)
	{
		puts("command not found");
		puts(cmd[0]);
	}
	else
		execve(path, cmd, env);
}

void	exec_cmd1(char *cmd, int fd[2], int fd_pipe[2], char **env)
{
	close(fd_pipe[0]);
	dup2(fd[0], 0);
	dup2(fd_pipe[1], 1);
	close(fd_pipe[1]);
	execution(cmd, env);
}

void	exec_cmd2(char *cmd, int fd[2], int fd_pipe[2], char **env)
{
	close(fd_pipe[1]);
	dup2(fd_pipe[0], 0);
	dup2(fd[1], 1);
	close(fd_pipe[0]);
	execution(cmd, env);
}

int	main(int ac, char **argv, char **env)
{
	int fd_pipe[2];
	int fd[2];
	pid_t id;

	if (ac != 5)
		ft_putstr_fd("error:./pipex file1 cmd1 cmd2 file2!!\n", 1);
	else if (pipe(fd_pipe) == -1)
		ft_putstr_fd("pipe error!!\n", 1);
	else if ((fd[0] = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr_fd("open infile error!!\n", 1);
		perror("error:");
	}
	else if ((fd[1] = open(argv[4], O_WRONLY | O_CREAT)) == -1)
		ft_putstr_fd("open outfile error!!\n", 1);
	else if ((id = fork()) < 0)
		ft_putstr_fd("fork error!!\n", 1);
	else if (id == 0)
		exec_cmd1(argv[2], fd, fd_pipe, env);
	else
		exec_cmd2(argv[3], fd, fd_pipe, env);
	close(fd[0]);
	close(fd[1]);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:45:17 by yait-kad          #+#    #+#             */
/*   Updated: 2021/06/13 19:45:19 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include "../libft/libft.h"

#define GREEN "\e[1;32m"
#define RESET "\e[0m"
#define RED "\e[1;91m"
#define CYAN "\e[1;36m"
#define YELLOW "\e[1;33m"
#define PURPLE "\e[1;35m"
#define BLUE "\e[1;34m"
#define Purple "\033[0;35m"
#define Cyan "\033[0;36m"

typedef	struct s_pipex
{
	char *file;
	char **cmd;
	struct s_pipex *next;
}	t_cmd;

// typedef struct s_command
// {
// 	char *file;
// 	char **cmd;
// 	struct s_command *next;
// }				t_command;

#endif

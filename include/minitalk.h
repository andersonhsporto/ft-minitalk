/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:18:12 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/17 15:35:06 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <fcntl.h>
# include "../ft-printf/includes/ft_printf.h"

enum e_bool
{
	false,
	true
};

typedef struct s_talk
{
	char	*string;
	int		len;
	int		pid;
}	t_talk;

typedef struct s_data
{
	char	x;
	int		i;
	int		client_pid;
}	t_data;

extern t_data g_data;

int		inspect_args(int argc, char **argv);
void	init_message(char **argv);
void	pick(int sig, siginfo_t *data, void *pointer __attribute__((unused)));

#endif
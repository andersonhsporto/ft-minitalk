/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-signal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 03:24:45 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/20 03:25:21 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler_sigusr(int signum);

void	init_message(char **argv)
{
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	send_bit(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
}

static  void	handler_sigusr(int signum)
{
	int	end;

	end = 0;
	if (signum == SIGUSR1)
		end = send_bit(0, 0);
	else if (signum == SIGUSR2)
		exit(EXIT_FAILURE);
	if (end)
		exit(EXIT_SUCCESS);
}

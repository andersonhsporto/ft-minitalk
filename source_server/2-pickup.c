/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-pickup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:41:56 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/20 03:22:03 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*print_free(char *message);
static char	*print_error(int pid, char *str);

void	pickup_handler(int signum, siginfo_t *info, void *context)
{
	static char	c = 0xFF;
	static char	*message = 0;
	static int	bits = 0;
	static int	pid = 0;

	(void)context;
	if (info->si_pid)
		pid = info->si_pid;
	if (signum == SIGUSR1)
		c ^= 0x80 >> bits;
	else if (signum == SIGUSR2)
		c |= 0x80 >> bits;
	if (++bits == 8)
	{
		if (c)
			message = add_char(message, c);
		else
			message = print_free(message);
		bits = 0;
		c = 0xFF;
	}
	if (kill(pid, SIGUSR1) == -1)
		print_error(pid, message);
}

static char	*print_free(char *message)
{
	ft_printf("%s\n", message);
	free(message);
	return (NULL);
}

static char	*print_error(int pid, char *str)
{
	if (str)
		free(str);
	ft_printf("minitalk: server error");
	kill(pid, SIGUSR2);
	exit(EXIT_FAILURE);
}

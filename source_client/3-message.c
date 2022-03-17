/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-message.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:19:58 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/17 14:56:34 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	deliver_message(t_talk	*data);
static void	deliver_byte(char byte, int pid);

void	init_message(char **argv)
{
	t_talk	data;

	data.string = argv[2];
	data.len = ft_strlen(argv[2]);
	data.pid = ft_atoi(argv[1]);
	deliver_message(&data);
}

static void	deliver_message(t_talk	*data)
{
	int	index;

	index = 0;
	while (data->string[index] != '\0')
	{
		deliver_byte(data->string[index], data->pid);
		index++;
	}
	return ;
}

static void	deliver_byte(char byte, int pid)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (byte >> bit & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
		bit--;
	}
}

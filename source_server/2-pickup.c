/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-pickup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:41:56 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/17 15:42:29 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reset_data(void)
{
	g_data.i = 0;
	g_data.x = 0;
	g_data.client_pid = 0;
}

void	pick(int sig, siginfo_t *data, void *pointer __attribute__((unused)))
{
	sig -= SIGUSR1;
	if (g_data.client_pid != data->si_pid)
		reset_data();
	g_data.x = g_data.x << 1 | sig;
	g_data.i++;
	if (g_data.i == 8)
	{
		write(1, &g_data.x, 1);
		reset_data();
	}
	g_data.client_pid = data->si_pid;
}
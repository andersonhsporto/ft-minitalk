/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-signal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:17:56 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/20 03:17:03 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	start_signals(void)
{
	struct sigaction	sa_signal;
	sigset_t			block_mask;

	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_mask = block_mask;
	sa_signal.sa_sigaction = pickup_handler;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	while (true)
		pause();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-signal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:17:56 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/17 15:32:10 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	start_signals(void)
{
	struct sigaction	talk;

	talk.sa_sigaction = &pick;
	talk.sa_flags = SA_SIGINFO;
	sigemptyset(&talk.sa_mask);
	sigaddset(&talk.sa_mask, SIGUSR1);
	sigaddset(&talk.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &talk, NULL);
	sigaction(SIGUSR2, &talk, NULL);
	while (true)
		sleep(1);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:18:12 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/20 03:26:46 by anhigo-s         ###   ########.fr       */
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

int		inspect_args(int argc, char **argv);
void	init_message(char **argv);
void	pickup_handler(int signum, siginfo_t *info, void *context);
void	start_signals(void);
char	*add_char(char *string, char ch);
int		send_bit(int pid, char *str);

#endif
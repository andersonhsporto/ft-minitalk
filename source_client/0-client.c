/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-client.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:14:09 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/20 03:16:15 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	if (inspect_args(argc, argv))
	{
		init_message(argv);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

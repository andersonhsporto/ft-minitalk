/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-inspect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:14:06 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/17 14:14:07 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	atoi_fchar(char *string);
static int	inspect_char(int c);

int	inspect_args(int argc, char **argv)
{
	if (argc == 3)
	{
		if (atoi_fchar(argv[1]) < 1)
		{
			ft_printf("minitalk: error: invalid pid\n");
			return (0);
		}
		return (1);
	}
	ft_printf("minitalk: error: wrong number of arguments\n");
	return (0);
}

static int	atoi_fchar(char *string)
{
	int	index;

	index = 0;
	if (ft_atoi(string) <= 0 || ft_atoi(string) > 99999)
		return (-1);
	while (string[index] != '\0')
	{
		if (inspect_char(string[index]))
		{
			return (-1);
		}
		index++;
	}
	return (ft_atoi(string));
}

static int	inspect_char(int c)
{
	if (ft_isdigit(c) || c == '-')
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

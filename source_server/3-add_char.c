/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-add_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 03:16:08 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/20 03:22:44 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*add_char_begins(char ch);
static char	*free_str(char *string);

char	*add_char(char *string, char ch)
{
	char	*temp;
	int		index;

	if (!ch)
		return (NULL);
	if (!string)
		return (add_char_begins(ch));
	temp = (char *)malloc(sizeof(char) * (ft_strlen(string) + 2));
	if (!temp)
		return (free_str(string));
	index = -1;
	while (string[++index])
		temp[index] = string[index];
	free(string);
	temp[index++] = ch;
	temp[index] = '\0';
	return (temp);
}

static char	*add_char_begins(char ch)
{
	char	*temp;

	temp = ft_strdup("1");
	temp[0] = ch;
	return (temp);
}

static char	*free_str(char *string)
{
	free(string);
	string = NULL;
	return (NULL);
}

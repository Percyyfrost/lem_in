/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpr_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:31:54 by vnxele            #+#    #+#             */
/*   Updated: 2018/07/16 08:09:57 by vuyaninxe        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_space(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

int		e_nbr(char *str)
{
	int	i;
	char **arr;

	i = 0;
	if (ft_strchr(str, '-'))
		arr = ft_strsplit(str, '-');
	else
		return (1);
	while (arr[i])
		i++;
	if (i != 2)
		return (1);
	return (0);
}

int		nbr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	if (!i)
		return (1);
	return (0);
}

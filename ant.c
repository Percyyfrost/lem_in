/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:30:00 by vnxele            #+#    #+#             */
/*   Updated: 2018/10/31 18:37:16 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ants(char **path, int len, t_input *db)
{
	int			i;
	int			j;

	i = 1;
	j = 1;
	while (j < db->ants + 1)
	{
		while (i < len)
		{
			ft_putstr("L");
			ft_putnbr(j);
			ft_putstr("->");
			ft_putendl(path[i]);
			i++;
		}
		i = 1;
		j++;
	}
}

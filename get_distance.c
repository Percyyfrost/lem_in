/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 03:01:18 by vnxele            #+#    #+#             */
/*   Updated: 2017/11/03 05:03:43 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		distance(int x, int x2, int y, int y2)
{
	int r;

	r = sqrt((x2 - x)^2 + (y2 - y)^2);
	return (r);
}

int		get_distance(char *str)
{
	int i;
	char **tmp;
	int x;
	int x2;
	int y;
	int y2;

	i = 0;
	while(str[i])
		i++;
	if(i >= 3)
	{
		tmp = ft_strsplit(str, ' ');
		if (ft_atoi(tmp[0]) == 0)
		{
			x = ft_atoi(tmp[0]);
		}
	}
}

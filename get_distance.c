/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 03:01:18 by vnxele            #+#    #+#             */
/*   Updated: 2017/11/03 16:17:42 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		distance(int x, int x2, int y, int y2)
{
	int r;

	r = sqrt((x2 - x)^2 + (y2 - y)^2);
	return (r);
}

int		get_distance(char **tmp)
{
	int i;
	char **temp;
	int x;
	int x2;
	int y;
	int y2;


	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 03:01:18 by vnxele            #+#    #+#             */
/*   Updated: 2017/11/15 09:49:06 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_coords     *insertCoords(t_coords *Coords, char *str)
{
	t_coords *tmp;

	tmp = (t_coords*)malloc(sizeof(t_coords));
	if (tmp)
	{
		tmp->vCoords = str;
		tmp->next = Coords;
	}
	return (tmp);
}

int		distance(int x, int x2, int y, int y2)
{
	int r;

	r = sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
	return (r);
}

int		get_distance(int v1, int v2, t_coords *db)
{
	int x;
	int x2;
	int y;
	int y2;
	int r;
	char ***vertexC;
	int i;
	int k;

	i = 0;
	k = db->EdgeCount;
	vertexC = (char ***)malloc(sizeof(char *) * (k));
	while (db)
	{
		vertexC[i] = ft_strsplit(db->vCoords, ' ');
		db = db->next;
		i++;
	}
	vertexC[k] = NULL;
	i = 0;
	while (vertexC[i])
	{
		if (v1 == ft_atoi(vertexC[i][0]))
		{
			x = ft_atoi(vertexC[i][1]);
			y = ft_atoi(vertexC[i][2]);
		 }
		if (v2 == ft_atoi(vertexC[i][0]))
		{
			x2 = ft_atoi(vertexC[i][1]);
			y2 = ft_atoi(vertexC[i][2]);
		}
		i++;
	}	
	if (x && x2)
	{
		r = distance(x, x2, y, y2);
		x = 0;
		x2 = 0;
		y = 0;
		y2 = 0;
	}
	return (r);
}

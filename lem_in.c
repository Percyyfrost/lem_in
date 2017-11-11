/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:17:27 by vnxele            #+#    #+#             */
/*   Updated: 2017/11/11 10:23:45 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int ac, char **av)
{
	t_input	*db;
	t_graph	*farm;
	t_edges	*Edge;

	if (ac == 3)
	{
		db = storage(0);
		farm = createGraph(db->vertices);
		Edge = ft_edges();
		while (Edge)
		{
			addEdge(farm, ft_atoi(&Edge->edges[0]), ft_atoi(&Edge->edges[2]), 6);
			Edge = Edge->next;
		}
		dijkstra(farm, ft_atoi(&db->start[0]));
	}
	else
		ft_putendl("Insert Lem_in Map");
	return (0);
}

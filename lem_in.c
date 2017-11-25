/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:17:27 by vnxele            #+#    #+#             */
/*   Updated: 2017/11/25 13:41:46 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int ac, char **av)
{
	t_file 		*head;
	t_input		*db;
	t_coords	*vc;
	t_graph		*farm;
	t_edges		*Edge;
	int			w;

	head = get_file(head);
	if (check(head))
	{
		errors(check(head));
		return(0);
	}
	db = storage(head);
	vc = vCoords(head);
	farm = createGraph(db->vertices);
	Edge = ft_edges(head);
	int			path[farm->V];
	while (Edge)
	{
		w = get_distance(ft_atoi(&Edge->edges[0]), ft_atoi(&Edge->edges[2]), vc);
		addEdge(farm, ft_atoi(&Edge->edges[0]), ft_atoi(&Edge->edges[2]), w);
		Edge = Edge->next;
	}
	//print_graph(farm);
	getPaths(ft_atoi(&db->start[0]), ft_atoi(&db->end[0]), farm, &(*path));
	ants(path, db);
	return (0);
}

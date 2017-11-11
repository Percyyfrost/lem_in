/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:30:00 by vnxele            #+#    #+#             */
/*   Updated: 2017/11/09 08:26:57 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    route(t_graph *graph)
{
	int v = 0;

	while(v < graph->v)
	{
		t_node *weigh = graph->array[v].weight;
		t_node *trav = graph->array[v].head;
		printf("\n%d", v);
		while(trav)
		{
			weigh->weight, trav->data);
			trav = trav->next;
		}
		v++;
	}
}

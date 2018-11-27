/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 11:42:53 by vnxele            #+#    #+#             */
/*   Updated: 2018/07/17 08:15:42 by vuyaninxe        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node		*add_node(int dest, int weight)
{
	t_node	*new_node;

	new_node = (t_node*)malloc(sizeof(t_node));
	new_node->dest = dest;
	new_node->weight = weight;
	new_node->next = NULL;
	return (new_node);
}

t_graph		*create_graph(t_input *db)
{
	t_graph *graph;
	int		i;

	graph = (t_graph*)malloc(sizeof(t_graph));
	graph->v_count = db->vertices;
	graph->array = (t_list*)malloc(sizeof(t_list) * graph->v_count);
	i = 0;
	while (i < graph->v_count)
	{
		graph->array[i].head = NULL;
		graph->array[i].name = db->names[i];
		i++;
	}
	return (graph);
}

void		add_edge(t_graph *graph, int src, int dest, int weight)
{
	t_node *new_node;

	if (src == -1)
		return ;
	new_node = add_node(dest, weight);
	new_node->next = graph->array[src].head;
	graph->array[src].head = new_node;
	new_node = add_node(src, weight);
	new_node->next = graph->array[dest].head;
	graph->array[dest].head = new_node;
}

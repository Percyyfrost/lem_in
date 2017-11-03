/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 11:42:53 by vnxele            #+#    #+#             */
/*   Updated: 2017/11/03 14:38:08 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node *c_node(int x)
{
	t_node *q = malloc(sizeof(t_node));

	q->data = x;
	q->next = NULL;
	return (q);
}

t_node *w_node(int x)
{
	t_node *q = malloc(sizeof(t_node));

	q->weight = x;
	q->next = NULL;
	return (q);
}

t_graph		*graph(int v)
{
	t_graph *graph = malloc(sizeof(t_graph));
	graph->v = v;
	graph->array = malloc(sizeof(t_list) * v);
	int i = 0;

	while (i < v)
	{
		graph->array[i].head = NULL;
		i++;
	}
	return (graph);
}

void	addedge(t_graph *graph, int src, int dest)
{
	t_node *temp;
	t_node *tmp;

	tmp = w_node(5);
	temp = c_node(dest);
	tmp->next = graph->array[src].weight;
	temp->next = graph->array[src].head;
	graph->array[src].head = temp;
	graph->array[src].weight = tmp;
}

void	print_graph(t_graph *graph)
{
	int v = 0;

	while(v < graph->v)
	{
		t_node *weigh = graph->array[v].weight;
		t_node *trav = graph->array[v].head;
		printf("\n%d", v);
		while(trav)
		{
			printf("--[%d]>>%d",weigh->weight, trav->data);
			trav = trav->next;
		}
		v++;
	}
}

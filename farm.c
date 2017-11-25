/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 11:42:53 by vnxele            #+#    #+#             */
/*   Updated: 2017/11/24 00:23:34 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node*     newAdjListNode(int dest, int weight)
{
	t_node* newNode =
		(t_node*) malloc(sizeof(t_node));
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

t_graph*    createGraph(int V)
{
	t_graph* graph = (t_graph*) malloc(sizeof(t_graph));
	graph->V = V;
	graph->array = (t_list*) malloc(V * sizeof(t_list));
	int i = 0;
	while(i < V)
	{
		graph->array[i].head = NULL;
		i++;
	}
	return graph;
}

void    addEdge(t_graph* graph, int src, int dest, int weight)
{
	t_node* newNode = newAdjListNode(dest, weight);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	newNode = newAdjListNode(src, weight);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}

void	print_graph(t_graph *graph)
{
	int v = 0;

	while(v < graph->V)
	{
		t_node *trav = graph->array[v].head;
		printf("\n%d", v);
		while(trav)
		{
			printf("->%d", trav->dest);
			trav = trav->next;
		}
		v++;
	}
}

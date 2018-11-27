/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:17:27 by vnxele            #+#    #+#             */
/* ************************************************************************** */

#include "lem_in.h"

void			print_map(t_file *head)
{
	while (head)
	{
		ft_putendl(head->data);
		head = head->next;
	}
	write(1, "\n", 1);
}

char			*match_room(char *str, int flag)
{
	char **arr;

	arr = ft_strsplit(str, '-');
	return (arr[flag]);
}

int			room_name(char *str, t_graph *graph, int flag)
{
	int	i;

	i = 0;

	while (i < (graph->v_count + 1))
	{
		if (ft_strequ(graph->array[i].name, match_room(str, flag)))
			return(i);
		i++;
	}
	return (-1);
}

void			addtoedge(t_file *head, t_graph *farm)
{
	t_edges		*edge;
	t_edges		*tmp;

	edge = ft_edges(head);
	while (edge)
	{
		add_edge(farm, room_name(edge->edges, farm, 0), room_name(edge->edges, farm, 1), 5);
		free(edge->edges);
		tmp = edge;
		edge = edge->next;
		free(tmp);
	}
}

void printGraph(t_graph  *graph)
{
    int v;
    for (v = 0; v < graph->v_count; ++v)
    {
        t_node* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %s\n head ", graph->array[v].name);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int				main(void)
{
	t_file		*head;
	t_input		*db;
	t_graph		*farm;

	head = NULL;
	head = get_file(head);
	if (check(head))
	{
		errors(check(head));
		return (1);
	}
	db = storage(head);
	farm = create_graph(db);
	print_map(head);
	addtoedge(head, farm);
	//printGraph(farm);
	get_paths(db, farm);
	return (0);
}

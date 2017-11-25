/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:14:01 by vnxele            #+#    #+#             */
/*   Updated: 2017/11/25 13:41:52 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_paths    *savePaths(t_paths *pathHead, int *path)
{
	t_paths *tmp;

	tmp = (t_paths*)malloc(sizeof(t_paths));
	if (tmp)
	{
		tmp->path = path;
		tmp->next = pathHead;
	}
	return (tmp);
}

void	pathRecurs(int s, int e, int *visited, int *path, int path_index, t_graph *graph)
{
	int i;
	path[path_index++] = s;

	if (s == e)
	{
		i = 0;
		while (i < path_index)
		{
			ft_putnbr(path[i]);
			i++;
		}
		write(1, "\n", 1);
	}
	else
	{
		t_node *trav = graph->array[s].head;
		while (trav)
		{
			if (!visited[s])
			{
				visited[s] = 1;
				s = trav->dest;
				pathRecurs(s, e, visited, path, path_index, graph);
			}
			trav = trav->next;
		}
	}
	path_index--;
	visited[s] = 0;
}

void    getPaths(int s, int e, t_graph *graph, int *path)
{
	int visited[graph->V];
	int path_index;
	int i;

	path_index = 0;
	i = 0;
	while (i < graph->V)
	{
		visited[i] = 0;
		i++;
	}
	pathRecurs(s, e, visited, path, path_index, graph);
}


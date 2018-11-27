/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:14:01 by vnxele            #+#    #+#             */
/*   Updated: 2018/11/27 15:52:01 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*room_name_rev(int i, t_graph *graph)
{
	char	*ret;

	ret = ft_strdup(graph->array[i].name);
	return (ret);
}

void		path_recurs(t_input *db, char **path, int pi, t_graph *graph)
{
	t_node		*trav;
	static	int i;

	trav = graph->array[db->istart].head;
	path[pi++] = room_name_rev(db->istart, graph);
	if (db->istart == db->iend && !i)
	{
		ants(path, pi, db);
		i++;
	}
	else
		while (trav)
		{
			if (!db->visited[db->istart])
			{
				db->visited[db->istart] = 1;
				db->istart = trav->dest;
				path_recurs(db, path, pi, graph);
			}
			trav = trav->next;
		}
	db->visited[db->istart] = 0;
}

void		freedb(t_input *db)
{
	t_input *tmp;

	while (db)
	{
		free(db->visited);
		free(db->end);
		free(db->edges);
		tmp = db;
		db = db->next;
		free(tmp);
	}
}
int                     init_point(char *str, t_graph *graph, int flag)
{
        int     i;

        i = 0;

        while(i < (graph->v_count + 1))
        {
                if (ft_strequ(graph->array[i].name, match_room(str, flag)))
                        return(i);
                i++;
        }
        return (i);
}

void		get_paths(t_input *db, t_graph *graph)
{
	int		pi;
	int		i;
	char		**path;

	pi = 0;
	i = 0;
	path = (char**)malloc(sizeof(char*) * graph->v_count);
	db->visited = (int*)malloc(sizeof(int) * graph->v_count);
	while (i < graph->v_count)
	{
		db->visited[i] = 0;
		i++;
	}
	db->istart = init_point(db->start, graph, 0);
	db->iend = init_point(db->end, graph, 0);
	path_recurs(db, path, pi, graph);
	freegraph(graph);
	freedb(db);
	free(path);
}

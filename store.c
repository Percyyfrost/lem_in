/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:00:35 by vnxele            #+#    #+#             */
/*   Updated: 2017/11/11 10:23:40 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_edges		*insertEdge(t_edges *edges, char *str)
{
	t_edges *tmp;

	tmp = (t_edges*)malloc(sizeof(t_edges));
	if (tmp)
	{
		tmp->edges = str;
		tmp->next = edges;
	}
	return (tmp);
}

void	print(t_edges *store)
{
	while(store)
	{
		ft_putendl(store->edges);
		store = store->next;
	}
}

t_edges		*ft_edges()
{
	int fd;
	t_edges *edges;
	char *line;

	edges = NULL;
	fd = open("map.txt", O_RDONLY);
	while(get_next_line(fd, &line))
	{
		if (ft_strchr(line, '-'))
			edges = (insertEdge(edges, line));
	}
	return (edges);
}

t_input		*storage(int fd)
{
	char *line;
	t_input *store;
	unsigned int i;
	int vertexnbr;

	i = 0;
	vertexnbr = 0;
	store = (t_input*)malloc(sizeof(t_input));
	while (get_next_line(fd, &line))
	{
		if (!i)
		{
			store->ants = ft_atoi(line);
			i++;
		}
		if (ft_strlen(line) >= 4 && line[0] != '#')
			vertexnbr++;
		if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
			i++;
		if (i == 2)
			store->start = line;
		if (i == 3 || i == 4)
		{
			store->end = line;
			i++;
		}
	}
	if (vertexnbr)
		store->vertices = vertexnbr;
	return(store);
}

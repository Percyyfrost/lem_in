/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:00:35 by vnxele            #+#    #+#             */
/*   Updated: 2017/11/16 23:38:27 by vnxele           ###   ########.fr       */
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

t_edges		*ft_edges(t_file *head)
{
	t_edges *edges;

	edges = NULL;
	while (head)
	{
		if (ft_strchr(head->data, '-'))
			edges = insertEdge(edges, head->data);
		head = head->next;
	}
	return (edges);
}

t_coords     *vCoords(t_file *head)
{
	t_coords	*vCo;
	int			i;

	i = 0;
	vCo = NULL;
	while (head)
	{
		if (ft_strchr(head->data, '-'))
			i++;
		if (ft_strlen(head->data) >= 4 && head->data[0] != '#')
			vCo = insertCoords(vCo, head->data);
		head = head->next;
	}
	if (i)
		vCo->EdgeCount = i;
	return (vCo);
}

t_input		*storage(t_file *head)
{
	t_input *store;
	unsigned int i;
	int vertexnbr;

	i = 0;
	vertexnbr = 0;
	store = (t_input*)malloc(sizeof(t_input));
	while (head)
	{
		if (!i)
		{
			store->ants = ft_atoi(head->data);
			i++;
		}
		if (ft_strlen(head->data) >= 4 && head->data[0] != '#')
			vertexnbr++;
		if (i == 2)
		{
			store->start = head->data;
			i++;
		}
		if (i == 4)
		{
			store->end = head->data;
			i++;
		}
		if (!ft_strcmp(head->data, "##start") || !ft_strcmp(head->data, "##end"))
			i++;
		head = head->next;
	}
	if (vertexnbr)
		store->vertices = vertexnbr;
	return(store);
}

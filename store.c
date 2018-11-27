/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:00:35 by vnxele            #+#    #+#             */
/*   Updated: 2018/07/17 08:17:13 by vuyaninxe        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*get_room(char *line)
{
	char 	**arr;

	arr = ft_strsplit(line, ' ');
	return(arr[0]);
}

t_edges		*ft_edges(t_file *head)
{
	t_edges *edges;

	edges = NULL;
	while (head)
	{
		if (ft_strchr(head->data, '-'))
			edges = insert_edge(edges, head->data);
		head = head->next;
	}
	return (edges);
}

t_input		*input(t_file *head, t_input *store, int i)
{
	store = (t_input*)malloc(sizeof(t_input));
	while (head)
	{

		if (!i)
		{
			store->ants = ft_atoi(head->data);
			i++;
		} 
		if (i == 2)
		{
			store->start = get_room(head->data);
			i++;
		}
		if (i == 4)
		{
			store->end = get_room(head->data);
			i++;
		}
		if (ft_strequ(head->data, "##start") ||
				ft_strequ(head->data, "##end"))
			i++;
		head = head->next;
	}
	return (store);
}

t_input		*storage(t_file *head)
{
	t_input			*store;
	t_file			*head2;
	unsigned int	i;
	int				vertexnbr;

	store = NULL;
	head2 = head;
	i = 0;
	vertexnbr = 0;
	store = input(head, store, i);
	while (head)
	{
		if (strcheck(head->data) == 3)
			vertexnbr++;
		head = head->next;
	}
	i = 0;
	store->names = (char**)malloc(sizeof(char*) * vertexnbr);
	while (head2)
	{
		if (strcheck(head2->data) == 3)
		{
			store->names[i] = (char*)malloc(sizeof(char) * ft_strlen(get_room(head2->data)));
			store->names[i] = get_room(head2->data);
			i++;
		}
		head2 = head2->next;
	}
	if (vertexnbr)
		store->vertices = vertexnbr;
	return (store);
}

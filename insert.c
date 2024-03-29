/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:19:03 by vnxele            #+#    #+#             */
/*   Updated: 2017/11/29 18:26:28 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				append(t_file **head_ref, char *new_data)
{
	t_file		*new_node;
	t_file		*last;

	new_node = (t_file*)malloc(sizeof(t_file));
	new_node->data = new_data;
	last = *head_ref;
	new_node->next = NULL;
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return (0);
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return (0);
}

t_edges			*insert_edge(t_edges *edges, char *str)
{
	t_edges		*tmp;

	tmp = (t_edges*)malloc(sizeof(t_edges));
	if (tmp)
	{
		tmp->edges = str;
		tmp->next = edges;
	}
	return (tmp);
}

t_file			*get_file(t_file *head)
{
	char		*line;

	while (get_next_line(0, &line))
		append(&head, line);
	return (head);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:08:27 by vnxele            #+#    #+#             */
/*   Updated: 2017/11/30 10:23:22 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	freelist(t_file *head)
{
	t_file	*tmp;

	while (head != NULL)
	{
		free(head->data);
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(head);
}

void	freegraph(t_graph *head)
{
	int i;

	i = 0;
	while (i < head->v_count)
	{
		free(head->array[i].head);
		i++;
	}
	free(head->array);
	free(head);
}

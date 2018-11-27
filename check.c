/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 10:24:30 by vnxele            #+#    #+#             */
/*   Updated: 2018/07/17 08:03:07 by vuyaninxe        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
int	strcheck(char *str)
{
	char **arr;
	int	i;

	i = 0;
	arr = ft_strsplit(str, ' ');
	while (arr[i])
		i++;
	return (i);
}

void	errors(int err)
{
	if (err == 1)
		ft_putendl("ant count invalid");
	if (err == 2)
		ft_putendl("invalid comment format");
	if (err == 3)
		ft_putendl("Missing start coordinates");
	if (err == 4)
		ft_putendl("Missing end coordinates");
	if (err == 5)
		ft_putendl("vertex error!");
	if (err == 6)
		ft_putendl("Trying to connect edge to non-existent vertex!");
	if (err == 7)
		ft_putendl("No edges");
	if (err == 8)
		ft_putendl("Incorrect Edge input");
	if (err == 9)
		ft_putendl("Don't know what to name it, it should never happen.");
}

int		connect_check(t_file *head, char *str)
{
	int i;
	int f;
	int s;

	f = 0;
	s = 0;
	while (head)
	{
		i = -1;
		while(i++ < 1)
			if (strcheck(head->data) == 3 && ft_strequ(get_room(head->data), match_room(str, i)))
				(!i)? f++ : s++;
		head = head->next;
	}
	if (!f || !s)
		return (1);
	return (0);
}

int		e_check(t_file *head)
{
	t_edges *edge;

	edge = ft_edges(head);
	if (!edge)
		return (7);
	while (edge)
	{
		if (e_nbr(edge->edges))
			return (8);
		if (connect_check(head, edge->edges))
			return (6);
		edge = edge->next;
	}
	return (0);
}

int		iter(t_file *head, int *s, int *e, int *vertexnbr)
{
	int i;

	i = 0;
	while (head)
	{
		if (!i)
		{
			if (nbr(head->data))
				return (1);
			i++;
		}
		if (strcheck(head->data) == 3)
			*vertexnbr = *vertexnbr + 1;
		if (!ft_strcmp(head->data, "##start"))
			*s = 1;
		if (!ft_strcmp(head->data, "##end"))
			*e = 1;
		head = head->next;
	}
	return (0);
}

int		check(t_file *head)
{
	int		s;
	int		e;
	int		vertexnbr;

	s = 0;
	e = 0;
	vertexnbr = 0;
	if (!head)
		return (9);
	if (iter(head, &s, &e, &vertexnbr))
		return (iter(head, &s, &e, &vertexnbr));
	if (!vertexnbr)
		return (5);
	if (e_check(head))
		return (e_check(head));
	if (!s)
		return (3);
	if (!e)
		return (4);
	return (0);
}

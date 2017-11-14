/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 10:24:30 by vnxele            #+#    #+#             */
/*   Updated: 2017/11/14 14:08:26 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lem_in.h"

int		is_space(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

int     Enbr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !(str[i] == '-'))
			return (1);
		i++;
	}
	return(0);
}

int		nbr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return(0);
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

int		edgeCheck(int max, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			if (ft_atoi(&str[i]) > max)
				return(1);
		i++;
	}
	return (0);
}

int		Echeck(int	vertexnbr, t_file *head)
{
	t_edges *Edge;

	Edge = ft_edges(head);
	if (!Edge)
		return(7);
	while (Edge)
	{
		if (Edge->edges[1] != '-' || Enbr(Edge->edges))
			return(8);
		if (edgeCheck(vertexnbr, Edge->edges))
			return(6);
		Edge = Edge->next;
	}
	return (0);
}

int		check(t_file *head)
{
	t_file	*head2;
	int		i;
	int		s;
	int		e;
	int		vertexnbr;

	s = 0;
	e = 0;
	i = 0;
	head2 = head;
	vertexnbr = 0;
	if (!head)
		return (9);
	while (head)
	{
		if (!i)
		{
			if (nbr(head->data))
				return(1);
			i++;
		}
		if (ft_strlen(head->data) >= 4 && head->data[0] != '#')
			vertexnbr++;
		if (head->data[0] == '#' && head->data[1] != '#')
			return (2);
		if (!ft_strcmp(head->data, "##start"))
			s = 1;
		if (!ft_strcmp(head->data, "##end"))
			e = 1;
		head = head->next;
	}
	if (!vertexnbr)
		return (5);
	if (Echeck(vertexnbr, head2))
		return(Echeck(vertexnbr, head2));
	if (!s)
		return (3);
	if (!e)
		return (4);
	return(0);
}

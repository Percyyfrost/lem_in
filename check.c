/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 10:24:30 by vnxele            #+#    #+#             */
/*   Updated: 2017/11/12 13:40:10 by vnxele           ###   ########.fr       */
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

int		Echeck(int	vertexnbr)
{
	t_edges *Edge;

	Edge = ft_edges();
	if (!Edge)
		return(7);
	while (Edge)
	{
		if (Edge->edges[1] != '-')
			return(8);
		if (Enbr(Edge->edges))
			return(8);
		if (edgeCheck(vertexnbr, Edge->edges))
			return(6);
		Edge = Edge->next;
	}
	return (0);
}

int		check()
{
	char	*line;
	int		i;
	int		s;
	int		e;
	int		vertexnbr;

	s = 0;
	e = 0;
	i = 0;
	vertexnbr = 0;
	while (get_next_line(0, &line))
	{
		if (!i)
		{
			if (nbr(line))
				return(1);
			i++;
		}
		if (ft_strlen(line) >= 4 && line[0] != '#')
			vertexnbr++;
		if (line[0] == '#' && line[1] != '#')
			return (2);
		if (!ft_strcmp(line, "##start"))
			s = 1;
		if (!ft_strcmp(line, "##end"))
			e = 1;
	}
	if (!vertexnbr)
		return (5);
	if (Echeck(vertexnbr))
		return(Echeck(vertexnbr));
	if (!s)
		return (3);
	if (!e)
		return (4);
	return(0);
}

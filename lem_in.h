/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 10:20:19 by vnxele            #+#    #+#             */
/*   Updated: 2017/11/03 14:39:52 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

typedef struct	s_node
{
	int		weight;
	int		data;
	struct s_node *next;
}				t_node;

typedef	struct	s_list
{
	t_node *weight;
	t_node *head;
}				t_list;

typedef	struct	s_graph
{
	int		v;
	t_list	*array;
}				t_graph;

void		addedge(t_graph *graph, int src, int dest);
t_graph		*graph(int v);
void		print_graph(t_graph *graph);
int			get_distance(char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 10:20:19 by vnxele            #+#    #+#             */
/*   Updated: 2017/11/15 08:40:23 by vnxele           ###   ########.fr       */
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
#include <limits.h>

typedef struct			s_file
{
	char				*data;
	struct  s_file		*next;
}						t_file;

typedef struct			s_input
{
	int					ants;
	int					vertices;
	char				*start;
	char				*end;
	char				*edges;
	struct s_input		*next;
}						t_input;

typedef struct			s_edges
{
	char				*edges;
	struct s_edges		*next;
}						t_edges;

typedef struct  		s_Coords
{
	int					EdgeCount;
	char    			*vCoords;
	struct s_Coords		*next;
}						t_coords;

typedef struct			AdjListNode
{
	int					dest;
	int					weight;
	struct AdjListNode*	next;
}						t_node;

typedef struct			AdjList
{
	struct AdjListNode	*head;
}						t_list;

typedef struct			Graph
{
	int					V;
	t_list*				array;
}						t_graph;

typedef struct			MinHeapNode
{
	int					v;
	int					dist;
}						t_heapN;

typedef struct			MinHeap
{
	int					size;
	int					capacity;
	int					*pos;
	t_heapN				**array;
}						t_heap;

t_input		*storage(t_file *head);
t_edges		*ft_edges(t_file *head);
void		addEdge(struct Graph* graph, int src, int dest, int weight);
t_graph*	createGraph(int V);
void		print_graph(t_graph *graph);
//int			get_distance(char **str);
void		dijkstra(t_graph *graph, int src);
t_node*		newAdjListNode(int dest, int weight);
void		print(t_edges *store);
int			check(t_file *head);
void		errors(int err);
t_file		*get_file(t_file *head);
void		insertAtEnd(char *data, int n, t_file **head);
t_coords	*vCoords(t_file *head);
t_coords	*insertCoords(t_coords *Coords, char *str);
int			get_distance(int v1, int v2, t_coords *db);

#endif

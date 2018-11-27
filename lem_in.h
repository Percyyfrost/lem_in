/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 10:20:19 by vnxele            #+#    #+#             */
/*   Updated: 2018/10/31 18:36:55 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>

typedef struct			s_file
{
	char				*data;
	struct s_file		*next;
}						t_file;

typedef struct			s_input
{
	int					*visited;
	int					ants;
	int					vertices;
	char				*start;
	int				istart;
	char				**names;
	char				*end;
	int				iend;
	char				*edges;
	int				i;
	char				**path;
	struct s_input		*next;
}						t_input;

typedef struct			s_edges
{
	char				*edges;
	struct s_edges		*next;
}						t_edges;

typedef struct			s_coords
{
	int					edge_count;
	char				*v_coords;
	struct s_coords		*next;
}						t_coords;

typedef struct			s_node
{
	int					dest;
	int					weight;
	struct s_node		*next;
}						t_node;

typedef struct			s_list
{
	t_node				*head;
	char				*name;
}						t_list;

typedef struct			s_graph
{
	int					v_count;
	t_list				*array;
}						t_graph;

typedef struct			s_paths
{
	int					*path;
	struct s_paths		*next;
}						t_paths;

t_input					*storage(t_file *head);
t_edges					*ft_edges(t_file *head);
t_edges					*insert_edge(t_edges *edges, char *str);
void					add_edge(t_graph *graph, int src, int dest, int weight);
t_graph					*create_graph(t_input *db);
void					print_graph(t_graph *graph);
int						check(t_file *head);
void					errors(int err);
t_file					*get_file(t_file *head);
t_coords				*insert_coords(t_coords *coords, char *str);
int						get_distance(int v1, int v2, t_coords *db);
void					get_paths(t_input *db, t_graph *graph);
void					ants(char **path, int len, t_input *db);
int						nbr(char *str);
int						e_nbr(char *str);
int						is_space(char c);
void					freelist(t_file *head);
void					freegraph(t_graph *head);
char					*get_room(char *line);
int					strcheck(char *str);
char					*match_room(char *str, int flag);
int					room_name(char *str, t_graph *graph, int flag);

#endif

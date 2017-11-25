
#include "lem_in.h"

int		append(t_file** head_ref, char *new_data)
{

	t_file	*new_node;
	t_file	*last;
	
	new_node = (t_file*) malloc(sizeof(t_file));
	new_node->data = new_data;
	last = *head_ref;
	new_node->next = NULL;
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return(0);
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return(0);
}

t_file		*get_file(t_file *head)
{
	char *line;
	int		i;

	i = 1;
	while (get_next_line(0, &line))
	{
		append(&head, line);
		i++;
	}
	return (head);
}

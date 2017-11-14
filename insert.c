
#include "lem_in.h"

void	insertAtEnd(char *data, int n, t_file **head)
{
	t_file	*temp1;
	t_file	*temp2;
	int		i;

	temp1 = (t_file*)malloc(sizeof(t_file));
	temp1->data = data;
	temp1->next = NULL;
	if (n == 1)
	{
		temp1->next = *head;
		*head = temp1;
		return;
	}
	temp2 = *head;
	i = 0;
	while (i < n - 2)
	{
		temp2 = temp2->next;
		i++;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}

t_file		*get_file(t_file *head)
{
	char *line;
	int		i;

	i = 1;
	while (get_next_line(0, &line))
	{
		insertAtEnd(line, i, &head);
		i++;
	}
	return (head);
}

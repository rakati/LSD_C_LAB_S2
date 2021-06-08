#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>

typedef struct			s_stack
{
	int			data;
	struct s_stack		*next;
}				t_stack;

/* ************************************************************************** */
/*                        STACK FUNCTIONS                                     */
/* ************************************************************************** */
t_stack                	*new_stack(int data);
int			is_empty(t_stack *head);
void        push(t_stack **head, int data);
int			pop(t_stack **head);
int         stack_len(t_stack *head);
int			peek_stack(t_stack *head);
void		print_stack(t_stack *head);
void		free_stack(t_stack*);

#endif
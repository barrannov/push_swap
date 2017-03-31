//
// Created by Aleksandr Baranov on 3/31/17.
//

#include "header.h"
void lst_add(t_ab **stk, int nbr)
{
	t_ab *new;
	t_ab *tmp;

	new = (t_ab *)malloc(sizeof(t_ab));
	new->num = nbr;
	new->next = NULL;
	if (*stk == NULL)
		(*stk) = new;
	else
	{
		tmp = *stk;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
}


void stack_add(t_ab **a, t_ab **b)
{
	if (*a)
		(*b)->next = (*a);
	*a = *b;
}

void pb(t_ab **a, t_ab **b, t_ab *moves)
{
	t_ab *tmp;
	printf("\npb");
	count++;
	(void) (*b);
	if (!(*a))
		return;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = NULL;
	stack_add(b, &tmp);
	lst_add(&moves, 5);
}


void pa(t_ab **a, t_ab **b, t_ab *moves)
{
	t_ab *tmp;
	printf("\npa");
	count++;
	(void) (*b);
	if (!(*a))
		return;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = NULL;
	stack_add(b, &tmp);
	lst_add(&moves, 4);
}


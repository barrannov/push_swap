//
// Created by Aleksandr Baranov on 3/31/17.
//
#include "header.h"


void rrb(t_ab **a, t_ab *moves)
{
	printf("\nrrb");
	count++;
	t_ab *tmp;
	t_ab *end;

	if (!(*a) || !(*a)->next)
		return;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	end = tmp->next;
	tmp->next = NULL;
	end->next = (*a);
	(*a) = end;
	lst_add(&moves, 10);
}

void rra(t_ab **a, t_ab *moves)
{
	printf("\nrra");
	count++;
	t_ab *tmp;
	t_ab *end;

	if (!(*a) || !(*a)->next)
		return;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	end = tmp->next;
	tmp->next = NULL;
	end->next = (*a);
	(*a) = end;
	lst_add(&moves, 9);
}

void rb(t_ab **strc, t_ab *moves)
{
	printf("\nrb");
	count++;
	t_ab *tmp;
	t_ab *end;

	if (*strc == NULL)
		return;
	if (!(*strc)->next)
		return;
	end = *strc;
	(*strc) = (*strc)->next;
	tmp = *strc;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = end;
	end->next = NULL;
	lst_add(&moves, 7);
}

void ra(t_ab **strc, t_ab *moves)
{
	printf("\nra");
	count++;
	t_ab *tmp;
	t_ab *end;

	if (*strc == NULL)
		return;
	if (!(*strc)->next)
		return;
	end = *strc;
	(*strc) = (*strc)->next;
	tmp = *strc;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = end;
	end->next = NULL;
	lst_add(&moves, 6);
}

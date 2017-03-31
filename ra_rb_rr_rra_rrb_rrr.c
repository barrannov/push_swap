#include "header.h"

void ra_rr(t_ab **strc)
{
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
}

void rr(t_ab **a, t_ab **b, t_ab *moves)
{
	count++;
	printf("\nrr");
	ra_rr(a);
	ra_rr(b);
	lst_add(&moves, 8);
}


void rrb_rrr(t_ab **a)
{

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
}

void rra_rrr(t_ab **a)
{
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
}

void rrr(t_ab **a, t_ab **b, t_ab *moves)
{
	count++;

	printf("\nrrr");

	rra_rrr(a);
	rrb_rrr(b);
	lst_add(&moves, 11);
}


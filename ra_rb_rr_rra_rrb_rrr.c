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

//void rr(t_ab *a, t_ab *b, t_ab *moves)
//{
//	count++;
//	printf("\nrr");
//	ra_rr(&a);
//	ra_rr(&b);
//	lst_add(&moves, 8);
//}

void rr(t_ab **a, t_ab **b, t_ab *moves)
{
	count++;
	printf("\nrr");
	ra_rr(a);
	//vizual(*a,*b);
	ra_rr(b);
	//vizual(*a,*b);
	lst_add(&moves, 8);
	//vizual(*a,*b);
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

//
//void rrr(t_ab *a, t_ab *b, t_ab *moves)
//{
//	count++;
//
//	printf("\nrrr");
//
//	rra_rrr(&a);
//	rrb_rrr(&b);
//	lst_add(&moves, 11);
//}

void delete_last(t_ab *head)
{
	t_ab *temp = head;
	t_ab *t;

	while (temp->next != NULL)
	{
		t = temp;
		temp = temp->next;
	}
	free(t->next);
	t->next = NULL;
}


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

#include "header.h"

void rr(t_ab *a, t_ab *b)
{
	count++;
	printf("\nq");
	ra(&a);
	rb(&b);

}


void rrr(t_ab *a, t_ab *b)
{
	count++;

	printf("\nrrr");

	rra(&a);
	rrb(&b);
}

void delete(t_ab *head)
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



void rrb(t_ab **a)
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
}

void rra(t_ab **a)
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
}

void rb(t_ab **strc)
{
	printf("\nrb");
	count++;
	t_ab *tmp;
	t_ab *end;

	if(*strc == NULL)
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

void ra(t_ab **strc)
{
	printf("\nra");
	count++;
	t_ab *tmp;
	t_ab *end;

	if(*strc == NULL)
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

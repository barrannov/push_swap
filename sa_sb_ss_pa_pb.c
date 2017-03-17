#include "header.h"


void deletefirst(t_ab **head)
{
	t_ab *tmp = *head;            // save old head for freeing.
	if (tmp == NULL) return;             // list empty? then do nothing.
	*head = tmp->next;                   // advance head to second node.
	//free (tmp);                          // free old head.
}

void stack_add(t_ab **a, t_ab **b)
{
	if (*a)
		(*b)->next = (*a);
	*a = *b;
}


void pa_pb(t_ab **a, t_ab **b)
{
	t_ab *tmp;

	(void) (*b);
	if (!(*a))
		return;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = NULL;
	stack_add(b, &tmp);
}

void sa_sb(t_ab **strc)
{
	int t;

	if ((*strc) != NULL && (*strc)->next != NULL)
	{
		t = (*strc)->next->num;
		(*strc)->next->num = (*strc)->num;
		(*strc)->num = t;
	}
}

void ss(t_ab *a, t_ab *b)
{
	sa_sb(a);
	sa_sb(b);
}

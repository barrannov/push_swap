#include "header.h"

void stack_add(t_ab **a, t_ab **b)
{
	if (*a)
		(*b)->next = (*a);
	*a = *b;
}

void pb(t_ab **a, t_ab **b)
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
}


void pa(t_ab **a, t_ab **b)
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
}


void sa(t_ab **strc)
{
	int t;
	printf("\nsa");
	count++;
	if ((*strc) != NULL && (*strc)->next != NULL)
	{
		t = (*strc)->next->num;
		(*strc)->next->num = (*strc)->num;
		(*strc)->num = t;
	}
}
void sb(t_ab **strc)
{
	int t;
	printf("\nsb");
	count++;
	if ((*strc) != NULL && (*strc)->next != NULL)
	{
		t = (*strc)->next->num;
		(*strc)->next->num = (*strc)->num;
		(*strc)->num = t;
	}
}
void ss(t_ab *a, t_ab *b)
{
	count++;
	printf("\nss");
	sa(&a);
	sb(&b);
}


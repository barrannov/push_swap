#include "header.h"

void	rr(t_ab *a, t_ab *b)
{
	ra_rb(&a);
	ra_rb(&b);
}


void	rrr(t_ab *a, t_ab *b)
{
	rra_rrb(&a);
	rra_rrb(&b);
}

void delete(t_ab *head)
{
	t_ab *temp =head;
	t_ab *t;
	while(temp->next != NULL)
	{
		t=temp;
		temp=temp->next;
	}
	free(t->next);
	t->next=NULL;
}

void rra_rrb(t_ab **strc)
{
	t_ab *newNode;

	if ((*strc) != NULL)
	{
		newNode = *strc;
		while (newNode->next != NULL)
			newNode = newNode->next;
		pa_pb(&newNode, strc);
	delete(*strc);
	}
}

void ra_rb(t_ab **strc)
{
	t_ab *newNode;
	int t;


	if ((*strc) != NULL)
	{
		t = (*strc)->num;
		(*strc) = (*strc)->next;
		newNode = *strc;
		while (newNode->next != NULL)
			newNode = newNode->next;
		newNode->next = (t_ab *) malloc(sizeof(t_ab));
		newNode->next->num = t;
		newNode->next->next = NULL;
	}
}
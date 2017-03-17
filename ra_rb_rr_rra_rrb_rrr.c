#include "header.h"

void rr(t_ab *a, t_ab *b)
{
	count++;
	printf("\nq");
	ra_rb(&a);
	ra_rb(&b);

}


void rrr(t_ab *a, t_ab *b)
{
	count++;

	printf("\nrrr");

	rra_rrb(&a);
	rra_rrb(&b);
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

//void rra_rrb(t_ab **strc)
//{
//	t_ab *newNode;
//	t_ab *temp;
//
//	if ((*strc) != NULL)
//	{
//		newNode = *strc;
//		while (newNode != NULL)
//		{
//			temp = newNode;
//			newNode = newNode->next;
//		}
//		pa_pb(&temp, strc);
//		delete(*strc);
//	}
//}

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

void rra_rrb(t_ab **a)
{
	printf("\nrra_rrb");
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
void ra_rb(t_ab **strc)
{
	printf("\nra_rb");
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
//void ra_rb(t_ab **strc)
//{
//	t_ab *newNode;
//	int t;
//
//
//	if ((*strc) != NULL)
//	{
//		t = (*strc)->num;
//		(*strc) = (*strc)->next;
//		newNode = *strc;
//		while (newNode->next != NULL)
//			newNode = newNode->next;
//		newNode->next = (t_ab *) malloc(sizeof(t_ab));
//		newNode->num = t;
//		newNode->next->next = NULL;
//	}
//}
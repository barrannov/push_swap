#include "header.h"

void pa_pb(t_ab **from, t_ab **to)
{
	t_ab *newNode;
	if ((*from) != NULL)
	{
		newNode = (t_ab *)malloc(sizeof(t_ab));
		newNode->num = (*from)->num;
		newNode->next = NULL;
		if (*to != NULL)
			newNode->next = *to;
		*to = newNode;
		*from = (*from)->next;
	}
}

void sa_sb(t_ab *strc)
{
	int t;

	if (strc != NULL && strc->next != NULL)
	{
		t = strc->next->num;
		strc->next->num = strc->num;
		strc->num = t;
	}
}

void ss(t_ab *a, t_ab *b)
{
	sa_sb(a);
	sa_sb(b);
}

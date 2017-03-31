#include "header.h"


void sa(t_ab **strc, t_ab *moves)
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
	lst_add(&moves, 1);

}

void sb(t_ab **strc, t_ab *moves)
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
	lst_add(&moves, 2);

}

void sa_ss(t_ab **strc)
{
	int t;

	if ((*strc) != NULL && (*strc)->next != NULL)
	{
		t = (*strc)->next->num;
		(*strc)->next->num = (*strc)->num;
		(*strc)->num = t;
	}
}

void sb_ss(t_ab **strc)
{
	int t;

	if ((*strc) != NULL && (*strc)->next != NULL)
	{
		t = (*strc)->next->num;
		(*strc)->next->num = (*strc)->num;
		(*strc)->num = t;

	}
}

void ss(t_ab *a, t_ab *b, t_ab *moves)
{
	count++;
	printf("\nss");
	sa_ss(&a);
	sb_ss(&b);
	lst_add(&moves, 3);
}

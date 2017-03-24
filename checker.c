//
// Created by Aleksandr Baranov on 3/21/17.
//

#include "header.h"


void pb_ch(t_ab **a, t_ab **b)
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


void pa_ch(t_ab **a, t_ab **b)
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

void sa_ch(t_ab **strc)
{
	int t;

	if ((*strc) != NULL && (*strc)->next != NULL)
	{
		t = (*strc)->next->num;
		(*strc)->next->num = (*strc)->num;
		(*strc)->num = t;
	}
}

void sb_ch(t_ab **strc)
{
	int t;

	if ((*strc) != NULL && (*strc)->next != NULL)
	{
		t = (*strc)->next->num;
		(*strc)->next->num = (*strc)->num;
		(*strc)->num = t;
	}
}

void rrb_ch(t_ab **a)
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

void rra_ch(t_ab **a)
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

void rb_ch(t_ab **strc)
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

void ss_ch(t_ab *a, t_ab *b)
{
	sa_ch(&a);
	sb_ch(&b);
}

void ra_ch(t_ab **strc)
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


void rrr_ch(t_ab *a, t_ab *b)
{
	rra_ch(&a);
	rrb_ch(&b);
}

void rr_ch(t_ab *a, t_ab *b)
{
	ra_ch(&a);
	rb_ch(&b);
}


//Работает правильно
void check_moves(t_ab *moves, t_ab **a)
{
	t_ab *temp;
	t_ab *b;

	b = NULL;
	temp = moves;
	int i;

	i = amount_list_el(temp);
	while (temp)
	{
		//printf("\n%d\n", temp->num);
		if (temp->num == 1)
		{
			printf("\nsa");
			sa_ch(a);
		}
		else if (temp->num == 2)
		{
			printf("\nsb");

			sb_ch(&b);
		}
		else if (temp->num == 3)
		{
			printf("\nss");

			ss_ch(*a, b);

		}
		else if (temp->num == 4)
		{
			printf("\npa");

			pa_ch(&b, a);

		}
		else if (temp->num == 5)
		{
			printf("\npb");

			pb_ch(a, &b);
		}
		else if (temp->num == 6)
		{

			printf("\nra");
			ra_ch(a);
		}
		else if (temp->num == 7)
		{

			printf("\nrb");
			rb_ch(&b);
		}
		else if (temp->num == 8)
		{
			printf("\nrr");
			rr_ch(*a, b);
		}
		else if (temp->num == 9)
		{
			printf("\nrra");
			rra_ch(a);
		}
		else if (temp->num == 10)
		{
			printf("\nrrb");
			rrb_ch(&b);
		}
		else if (temp->num == 11)
		{
			printf("\nrrr");
			rrr_ch(*a, b);
		}
		else
		{
			printf("Error");
			break;
		}
		//vizual(*a, b);
		temp = temp->next;
	}
	//pa_ch(&a, &b);
	vizual(*a, b);

	if (chacker(*a))
		ft_putstr("\nchecker: OK");
	else
		ft_putstr("\nchecker: KO");
}

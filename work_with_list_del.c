//
// Created by Aleksandr Baranov on 3/31/17.
//

#include "header.h"
 void rra_sp(t_ab **a)
{
	t_ab *tmp;
	t_ab *end;
	int i;

	if (!(*a) || !(*a)->next)
		return;
	tmp = *a;
	i = amount_list_el(tmp) - 2;
	while (i--)
		tmp = tmp->next;
	end = tmp->next;
	tmp->next = NULL;
	end->next = (*a);
	(*a) = end;
}



void delete_pa_pb(t_ab *moves)
{
	t_ab *cur;
	int i;

	cur = moves;
	int j;
	int cou;

	i = 0;
	cou = amount_list_el(moves);
	j = 0;
	while (i < cou)
	{
		cou = amount_list_el(cur);
		if (cur->num == 6 && cur->next->num == 9 || cur->num == 9 && cur->next->num == 6)
		{
			deletefirst(&cur);
			deletefirst(&cur);
			while (j--)
				rra_sp(&cur);
			j = 0;
			i = 0;
		}
		else
		{
			j++;
			ra_sp(&cur);
		}
		i++;
	}
	while (j--)
		rra_sp(&cur);
}


void delete_6_5_9(t_ab **moves)
{
	t_ab *cur;
	t_ab *temp;
	cur = *moves;

	if (amount_list_el(*moves) < 3)
		return;
	while ((cur)->next->next->next)
	{
		if (cur->next->num == 6 && cur->next->next->num == 5 && cur->next->next->next->num == 9)
		{
			temp = cur->next;
			cur->next = temp->next;
			free(temp);
			cur->next->num = 1;
			cur->next->next->num = 5;
		}
		else if (cur->next->num == 7 && cur->next->next->num == 4 && cur->next->next->next->num == 10)
		{
			temp = cur->next;
			cur->next = temp->next;
			free(temp);
			cur->next->num = 2;
			cur->next->next->num = 4;
		}
		else
			cur = (cur)->next;
	}
}

void delete_1_6_5(t_ab **moves)
{
	t_ab *cur;
	t_ab *temp;
	cur = *moves;

	if (amount_list_el(*moves) < 3)
		return;
	while ((cur)->next->next->next)
	{
		if (cur->next->num == 1 && cur->next->next->num == 6 && cur->next->next->next->num == 5)
		{
			temp = cur->next;
			cur->next = temp->next;
			free(temp);
			cur->next->num = 5;
			cur->next->next->num = 6;
		}
		else if (cur->next->num == 9 && cur->next->next->num == 1 && cur->next->next->next->num == 5)
		{
			temp = cur->next;
			cur->next = temp->next;
			free(temp);
			cur->next->num = 5;
			cur->next->next->num = 9;
		}
		else
			cur = (cur)->next;
	}
}


void delete_ra_rb(t_ab **moves)
{
	t_ab *cur;
	t_ab *temp;
	cur = *moves;

	if (amount_list_el(*moves) < 3)
		return;
	while ((cur)->next->next)
	{
		if (cur->next->num == 6 && cur->next->next->num == 7)
		{
			temp = cur->next;
			cur->next = temp->next;
			cur->next->num = 8;
			free(temp);
		}
		else
			cur = (cur)->next;
	}
}

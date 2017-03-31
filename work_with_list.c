#include "header.h"

//
// Created by Aleksandr Baranov on 3/20/17.
//

void ra_sp(t_ab **strc)
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


void remove_pa_pb(t_ab **moves)
{
	t_ab *cur;
	t_ab *temp;
	cur = *moves;

	if (amount_list_el(*moves) < 3)
		return;
	while ((cur)->next->next)
	{
		if (cur->next->num == 4 && cur->next->next->num == 5
			|| cur->next->num == 5 && cur->next->next->num == 4)
		{
			temp = cur->next;
			cur->next = temp->next;
			free(temp);
			temp = cur->next;
			cur->next = temp->next;
			free(temp);
			cur = *moves;
		}
		else
			cur = (cur)->next;
	}
}


void remove_ra_rrb(t_ab **moves)
{
	t_ab *cur;
	t_ab *temp;
	cur = *moves;

	if (amount_list_el(*moves) < 3)
		return;
	while ((cur)->next->next)
	{
		if (cur->next->num == 7 && cur->next->next->num == 10
			|| cur->next->num == 10 && cur->next->next->num == 7)
		{
			temp = cur->next;
			cur->next = temp->next;
			free(temp);
			temp = cur->next;
			cur->next = temp->next;
			free(temp);
		}
		else
			cur = (cur)->next;
	}
}

void remove_6_9(t_ab **moves)
{
	t_ab *cur;
	t_ab *temp;
	cur = *moves;

	if (amount_list_el(*moves) < 3)
		return;
	while ((cur)->next->next)
	{
		if (cur->next->num == 6 && cur->next->next->num == 9
			|| cur->next->num == 9 && cur->next->next->num == 6)
		{
			temp = cur->next;
			cur->next = temp->next;
			free(temp);
			temp = cur->next;
			cur->next = temp->next;
			free(temp);
		}
		else
			cur = (cur)->next;
	}
}

void delete_spare(t_ab **moves)
{
	delete_6_5_9(moves);
	remove_6_9(moves);
	remove_ra_rrb(moves);
	delete_ra_rb(moves);
	remove_pa_pb(moves);
	delete_1_6_5(moves);
	delete_pa_pb(*moves);
}

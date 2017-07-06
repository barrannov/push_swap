/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:47:52 by abaranov          #+#    #+#             */
/*   Updated: 2017/04/05 17:47:58 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				remove_pa_pb(t_ab **moves)
{
	t_ab		*cur;
	t_ab		*temp;

	cur = *moves;
	if (amount_list_el(*moves) < 3)
		return ;
	while ((cur)->next->next)
	{
		if ((cur->next->num == 4 && cur->next->next->num == 5)
				|| (cur->next->num == 5 && cur->next->next->num == 4))
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

void				remove_rb_rrb(t_ab **moves)
{
	t_ab *cur;
	t_ab *temp;

	cur = *moves;
	if (amount_list_el(*moves) < 3)
		return ;
	while ((cur)->next->next)
	{
		if ((cur->next->num == 7 && cur->next->next->num == 10)
				|| (cur->next->num == 10 && cur->next->next->num == 7))
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

void				remove_6_9(t_ab **moves)
{
	t_ab *cur;
	t_ab *temp;

	cur = *moves;
	while ((cur)->next->next)
		if ((cur->next->num == 6 && cur->next->next->num == 9)
				|| (cur->next->num == 9 && cur->next->next->num == 6))
		{
			temp = cur->next;
			cur->next = temp->next;
			free(temp);
			temp = cur->next;
			cur->next = temp->next;
			free(temp);
		}
		else if ((cur->next->num == 6 && cur->next->next->num == 9)
				|| (cur->next->num == 9 && cur->next->next->num == 6))
		{
			temp = cur->next->next;
			cur->next->next = temp->next;
			free(temp);
		}
		else
			cur = (cur)->next;
}

void				delete_spare(t_ab **moves)
{
	if (amount_list_el(*moves) > 2)
	{
		delete_6_5_9(moves);
		remove_6_9(moves);
	}
	remove_rb_rrb(moves);
	delete_ra_rb(moves);
	delete_1_6_5(moves);
	remove_pa_pb(moves);
	delete_9_1_5(moves);
}

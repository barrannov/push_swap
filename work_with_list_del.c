/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_list_del.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:23:05 by abaranov          #+#    #+#             */
/*   Updated: 2017/04/05 17:43:48 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				delete_6_5_9(t_ab **moves)
{
	t_ab	*cur;
	t_ab	*temp;

	cur = *moves;
	while ((cur)->next->next->next)
		if (cur->next->num == 6 && cur->next->next->num == 5
				&& cur->next->next->next->num == 9)
		{
			temp = cur->next;
			cur->next = temp->next;
			free(temp);
			cur->next->num = 1;
			cur->next->next->num = 5;
		}
		else if (cur->next->num == 7 && cur->next->next->num == 4
				&& cur->next->next->next->num == 10)
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

void				delete_9_1_5(t_ab **moves)
{
	t_ab		*cur;
	t_ab		*temp;

	cur = *moves;
	if (amount_list_el(*moves) < 3)
		return ;
	while ((cur)->next->next->next)
	{
		if (cur->next->num == 9 &&
				cur->next->next->num == 1 && cur->next->next->next->num == 5)
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

void				delete_1_6_5(t_ab **moves)
{
	t_ab		*cur;
	t_ab		*temp;

	cur = *moves;
	if (amount_list_el(*moves) < 3)
		return ;
	while ((cur)->next->next->next)
	{
		if (cur->next->num == 1 &&
				cur->next->next->num == 6 && cur->next->next->next->num == 5)
		{
			temp = cur->next;
			cur->next = temp->next;
			free(temp);
			cur->next->num = 5;
			cur->next->next->num = 6;
		}
		else
			cur = (cur)->next;
	}
}

void				delete_ra_rb(t_ab **moves)
{
	t_ab		*cur;
	t_ab		*temp;

	cur = *moves;
	if (amount_list_el(*moves) < 3)
		return ;
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

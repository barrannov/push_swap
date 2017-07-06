/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:28:39 by abaranov          #+#    #+#             */
/*   Updated: 2017/04/06 15:28:40 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				pb_ch(t_ab **a, t_ab **b)
{
	t_ab *tmp;

	(void)(*b);
	if (!(*a))
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = NULL;
	stack_add(b, &tmp);
}

void				pa_ch(t_ab **a, t_ab **b)
{
	t_ab *tmp;

	(void)(*b);
	if (!(*a))
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = NULL;
	stack_add(b, &tmp);
}

void				sa_ch(t_ab **strc)
{
	int t;

	if ((*strc) != NULL && (*strc)->next != NULL)
	{
		t = (*strc)->next->num;
		(*strc)->next->num = (*strc)->num;
		(*strc)->num = t;
	}
}

void				sb_ch(t_ab **strc)
{
	int t;

	if ((*strc) != NULL && (*strc)->next != NULL)
	{
		t = (*strc)->next->num;
		(*strc)->next->num = (*strc)->num;
		(*strc)->num = t;
	}
}

void				rrb_ch(t_ab **a)
{
	t_ab *tmp;
	t_ab *end;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	end = tmp->next;
	tmp->next = NULL;
	end->next = (*a);
	(*a) = end;
}

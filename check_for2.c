/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:30:49 by abaranov          #+#    #+#             */
/*   Updated: 2017/04/06 15:30:51 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				rra_ch(t_ab **a)
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

void				rb_ch(t_ab **strc)
{
	t_ab *tmp;
	t_ab *end;

	if (*strc == NULL)
		return ;
	if (!(*strc)->next)
		return ;
	end = *strc;
	(*strc) = (*strc)->next;
	tmp = *strc;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = end;
	end->next = NULL;
}

void				ra_ch(t_ab **strc)
{
	t_ab *tmp;
	t_ab *end;

	if (*strc == NULL)
		return ;
	if (!(*strc)->next)
		return ;
	end = *strc;
	(*strc) = (*strc)->next;
	tmp = *strc;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = end;
	end->next = NULL;
}

void				ss_ch(t_ab *a, t_ab *b)
{
	sa_ch(&a);
	sb_ch(&b);
}

void				rrr_ch(t_ab **a, t_ab **b)
{
	rra_ch(a);
	rrb_ch(b);
}

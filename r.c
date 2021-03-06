/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 19:16:08 by abaranov          #+#    #+#             */
/*   Updated: 2017/04/05 19:16:09 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				rrb(t_ab **a, t_ab *moves)
{
	t_ab	*tmp;
	t_ab	*end;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	end = tmp->next;
	tmp->next = NULL;
	end->next = (*a);
	(*a) = end;
	lst_add(&moves, 10);
}

void				rra(t_ab **a, t_ab *moves)
{
	t_ab	*tmp;
	t_ab	*end;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	end = tmp->next;
	tmp->next = NULL;
	end->next = (*a);
	(*a) = end;
	lst_add(&moves, 9);
}

void				rb(t_ab **strc, t_ab *moves)
{
	t_ab	*tmp;
	t_ab	*end;

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
	lst_add(&moves, 7);
}

void				ra(t_ab **strc, t_ab *moves)
{
	t_ab	*tmp;
	t_ab	*end;

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
	lst_add(&moves, 6);
}

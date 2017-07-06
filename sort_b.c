/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 18:40:22 by abaranov          #+#    #+#             */
/*   Updated: 2017/04/05 18:40:27 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					partition_b(t_ab **a, t_ab **b, int size, t_ab *moves)
{
	int med;
	int count;
	int j;

	j = 0;
	count = 0;
	med = find_med(*a, size);
	while (more_then_med(*a, med))
	{
		if ((*a)->num > med)
		{
			pa(a, b, moves);
			count++;
		}
		else
		{
			j++;
			rb(a, moves);
		}
	}
	b_back_rb_rrb(j, a, moves);
	return (count);
}

void				move_back_b(t_ab **a, t_ab **b, int size, t_ab *moves)
{
	int i;

	i = 0;
	while (i < size)
	{
		pb(b, a, moves);
		i++;
	}
}

t_ab				*easy_sort_b(t_ab *a, t_ab *moves)
{
	if (a->num < a->next->num && a->next->num < a->next->next->num)
	{
		sb(&a, moves);
		rb(&a, moves);
	}
	if (a->num < a->next->num
		&& a->next->num > a->next->next->num && a->num > a->next->next->num)
		sb(&a, moves);
	if (a->num < a->next->num
		&& a->next->num > a->next->next->num && a->num < a->next->next->num)
		rb(&a, moves);
	if (a->num > a->next->num
		&& a->next->num < a->next->next->num && a->num < a->next->next->num)
		rrb(&a, moves);
	if (a->num < a->next->num
		&& a->next->num > a->next->next->num && a->num < a->next->next->num)
		rb(&a, moves);
	if (a->num > a->next->num
		&& a->next->num < a->next->next->num && a->num > a->next->next->num)
	{
		rrb(&a, moves);
		sb(&a, moves);
	}
	return (a);
}

int					sort_up_b(t_ab *a)
{
	if (a->num > a->next->num && a->next->num > a->next->next->num)
		return (1);
	return (0);
}

int					more_then_med(t_ab *a, int med)
{
	t_ab *na;

	if (a == NULL)
		return (0);
	na = a;
	while (na)
	{
		if (na->num > med)
			return (1);
		na = na->next;
	}
	return (0);
}

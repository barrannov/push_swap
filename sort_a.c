/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 18:56:59 by abaranov          #+#    #+#             */
/*   Updated: 2017/04/05 18:57:00 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ft_push_swap(t_ab **a, t_ab **b, int size, t_ab *moves)
{
	int n_pushed;

	if (size > 3)
	{
		n_pushed = partition_a(a, b, size, moves);
		ft_push_swap(a, b, size - n_pushed, moves);
		ft_push_swapb(b, a, n_pushed, moves);
		move_back_a(a, b, n_pushed, moves);
	}
	else if (size > 1)
		sort_by_hand(a, b, size, moves);
}

void				move_back_a(t_ab **a, t_ab **b, int size, t_ab *moves)
{
	int i;

	i = 0;
	while (i < size)
	{
		pa(b, a, moves);
		i++;
	}
}

int					sort_up_a(t_ab *a)
{
	if (a->num < a->next->num && a->next->num < a->next->next->num)
		return (1);
	return (0);
}

t_ab				*easy_sort_a(t_ab *a, t_ab *moves)
{
	if ((a)->num > (a)->next->num
		&& (a)->next->num > (a)->next->next->num)
	{
		sa(&a, moves);
		rra(&a, moves);
	}
	if (a->num > a->next->num &&
			a->next->num < a->next->next->num && a->num < a->next->next->num)
		sa(&a, moves);
	else if (a->num > a->next->num &&
			a->next->num < a->next->next->num && a->num > a->next->next->num)
		ra(&a, moves);
	else if (a->num < a->next->num &&
			a->next->num > a->next->next->num && a->num > a->next->next->num)
		rra(&a, moves);
	else if (a->num > a->next->num &&
			a->next->num < a->next->next->num && a->num > a->next->next->num)
		ra(&a, moves);
	return (a);
}

int					partition_a(t_ab **a, t_ab **b, int size, t_ab *moves)
{
	int		med;
	int		count;
	int		j;
	int		f;

	f = 0;
	j = 0;
	count = 0;
	med = find_med(*a, size);
	if (amount_list_el(*b) != 0)
		f = 1;
	while (less_then_med(*a, med))
		if ((*a)->num <= med)
		{
			pb(a, b, moves);
			count++;
		}
		else
		{
			j++;
			ra(a, moves);
		}
	a_back_ra_rra(f, j, a, moves);
	return (count);
}

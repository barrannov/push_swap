/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_han.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:53:41 by abaranov          #+#    #+#             */
/*   Updated: 2017/04/05 17:53:43 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				sort_3_a(t_ab *a, t_ab *b, t_ab *moves)
{
	if (a->next->num < a->next->next->num)
	{
		if (amount_list_el(b) > 2)
			if ((b)->next->num > (b)->next->next->num)
			{
				rr(&a, &b, moves);
				ss(a, b, moves);
				rrr(&a, &b, moves);
			}
			else
			{
				rb(&a, moves);
				if ((b)->num > (b)->next->num)
					ss(a, b, moves);
				else
					sb(&a, moves);
				rrb(&a, moves);
			}
		else
		{
			rb(&a, moves);
			sb(&a, moves);
			rrb(&a, moves);
		}
	}
}

int					sort_by_hand_b(t_ab **a, t_ab **b, int size, t_ab *moves)
{
	t_ab		*na;
	t_ab		*nb;

	nb = *b;
	na = *a;
	if (amount_list_el(*a) == 3)
		*a = easy_sort_b(*a, moves);
	else
	{
		if (na->num < na->next->num)
		{
			if (amount_list_el(nb) > 1 && (nb)->num > (nb)->next->num)
				ss(na, nb, moves);
			else
				sb(&na, moves);
		}
		if (size == 3)
			sort_3_a(na, nb, moves);
		if (size == 3 && !sort_up_b(na))
			sort_by_hand_b(a, b, size, moves);
	}
	return (0);
}

void				sort_3_b(t_ab *na, t_ab *nb, t_ab *moves)
{
	if (na->next->num > na->next->next->num)
	{
		if (amount_list_el(nb) > 2)
			if ((nb)->next->num < (nb)->next->next->num)
			{
				rr(&na, &nb, moves);
				ss(na, nb, moves);
				rrr(&na, &nb, moves);
			}
			else
			{
				ra(&na, moves);
				if ((nb)->num < (nb)->next->num)
					ss(na, nb, moves);
				else
					sa(&na, moves);
				rra(&na, moves);
			}
		else
		{
			ra(&na, moves);
			sa(&na, moves);
			rra(&na, moves);
		}
	}
}

void				sort_by_hand(t_ab **a, t_ab **b, int size, t_ab *moves)
{
	t_ab		*na;

	na = *a;
	if (amount_list_el(*a) == 3)
	{
		if (((*a)->num < (*a)->next->num) && (*a)->next->num >
		(*a)->next->next->num && (*a)->num < (*a)->next->next->num)
		{
			rra(a, moves);
			sa(a, moves);
		}
		else
			easy_sort_a(*a, moves);
	}
	else
	{
		if (na->num > na->next->num)
		{
			(amount_list_el(*b) > 1 &&
			(*b)->num < (*b)->next->num) ? ss(na, *b, moves) : sa(&na, moves);
		}
		(size == 3) ? sort_3_b(na, *b, moves) : 0;
		if (size == 3 && !sort_up_a(na))
			return (sort_by_hand(&na, b, size, moves));
	}
}

int					less_then_med(t_ab *a, int med)
{
	t_ab		*na;

	if (a == NULL)
		return (0);
	na = a;
	while (na != NULL)
	{
		if (na->num <= med)
			return (1);
		na = na->next;
	}
	return (0);
}

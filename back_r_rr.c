/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_r_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:45:00 by abaranov          #+#    #+#             */
/*   Updated: 2017/04/06 15:45:01 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				b_back_rb_rrb(int j, t_ab **a, t_ab *moves)
{
	if (j > amount_list_el(*a) / 2)
	{
		j = amount_list_el(*a) - j;
		while (j--)
			rb(a, moves);
	}
	else
		while (j--)
			rrb(a, moves);
}

void				a_back_ra_rra(int f, int j, t_ab **a, t_ab *moves)
{
	if (f == 1)
	{
		if (j > amount_list_el(*a) / 2)
		{
			j = amount_list_el(*a) - j;
			while (j--)
				ra(a, moves);
		}
		else
			while (j--)
				rra(a, moves);
	}
}

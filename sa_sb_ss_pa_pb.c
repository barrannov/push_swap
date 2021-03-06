/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_pa_pb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 19:08:23 by abaranov          #+#    #+#             */
/*   Updated: 2017/04/05 19:08:24 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				sa(t_ab **strc, t_ab *moves)
{
	int t;

	if ((*strc) != NULL && (*strc)->next != NULL)
	{
		t = (*strc)->next->num;
		(*strc)->next->num = (*strc)->num;
		(*strc)->num = t;
	}
	lst_add(&moves, 1);
}

void				sb(t_ab **strc, t_ab *moves)
{
	int t;

	if ((*strc) != NULL && (*strc)->next != NULL)
	{
		t = (*strc)->next->num;
		(*strc)->next->num = (*strc)->num;
		(*strc)->num = t;
	}
	lst_add(&moves, 2);
}

void				sa_ss(t_ab **strc)
{
	int t;

	if ((*strc) != NULL && (*strc)->next != NULL)
	{
		t = (*strc)->next->num;
		(*strc)->next->num = (*strc)->num;
		(*strc)->num = t;
	}
}

void				sb_ss(t_ab **strc)
{
	int t;

	if ((*strc) != NULL && (*strc)->next != NULL)
	{
		t = (*strc)->next->num;
		(*strc)->next->num = (*strc)->num;
		(*strc)->num = t;
	}
}

void				ss(t_ab *a, t_ab *b, t_ab *moves)
{
	sa_ss(&a);
	sb_ss(&b);
	lst_add(&moves, 3);
}

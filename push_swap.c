/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:45:22 by abaranov          #+#    #+#             */
/*   Updated: 2017/04/07 13:13:52 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					main(int arg, char *argv[])
{
	t_ab *a;
	t_ab *b;
	t_ab *moves;

	moves = NULL;
	b = NULL;
	lst_add(&moves, 1);
	if (arg > 1)
	{
		if (!is_valid(argv))
			return (0);
		a = create_numbers(argv, arg);
		if (!check_the_same(a))
			return (0);
		if (amount_list_el(a) == 2)
			a->num > a->next->num ? sa(&a, moves) : 0;
		(!chacker(a) && arg > 1) ?
		ft_push_swap(&a, &b, amount_list_el(a), moves) : 0;
		delete_spare(&moves);
		deletefirst(&moves);
		print_moves(&moves);
		ft_del_list(&a);
		ft_del_list(&moves);
	}
	while(1);
	return (0);
}

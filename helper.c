/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 19:42:29 by abaranov          #+#    #+#             */
/*   Updated: 2017/04/05 19:42:30 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ft_del_list(t_ab **head)
{
	t_ab *crawler;
	t_ab *prev;

	crawler = *head;
	while (crawler)
	{
		prev = crawler;
		crawler = crawler->next;
		ft_bzero(prev, sizeof(prev));
		free(prev);
	}
	*head = NULL;
	return ;
}

t_ab				*create_numbers(char **numb, int argc)
{
	int		i;
	t_ab	*temp;
	t_ab	*a;

	temp = (t_ab *)malloc(sizeof(t_ab));
	a = temp;
	i = 1;
	while (i < argc)
	{
		temp->num = (int)ft_atoi(numb[i]);
		i++;
		if (numb[i])
		{
			temp->next = (t_ab *)malloc(sizeof(t_ab));
			temp = temp->next;
			temp->next = NULL;
		}
		temp->next = NULL;
	}
	return (a);
}

void				ft_push_swapb(t_ab **a, t_ab **b, int size, t_ab *moves)
{
	int n_pushed;

	if (size > 3)
	{
		n_pushed = partition_b(a, b, size, moves);
		ft_push_swap(b, a, n_pushed, moves);
		ft_push_swapb(a, b, size - n_pushed, moves);
		move_back_b(a, b, n_pushed, moves);
	}
	else if (size > 1)
		sort_by_hand_b(a, b, size, moves);
}

void				print_moves(t_ab **moves)
{
	t_ab *temp;

	temp = *moves;
	while (temp)
	{
		((temp)->num == 1) ? ft_putstr("sa\n") : 0;
		(temp->num == 2) ? ft_putstr("sb\n") : 0;
		(temp->num == 3) ? ft_putstr("ss\n") : 0;
		(temp->num == 4) ? ft_putstr("pa\n") : 0;
		(temp->num == 5) ? ft_putstr("pb\n") : 0;
		(temp->num == 6) ? ft_putstr("ra\n") : 0;
		(temp->num == 7) ? ft_putstr("rb\n") : 0;
		(temp->num == 8) ? ft_putstr("rr\n") : 0;
		(temp->num == 9) ? ft_putstr("rra\n") : 0;
		(temp->num == 10) ? ft_putstr("rrb\n") : 0;
		(temp->num == 11) ? ft_putstr("rrr\n") : 0;
		temp = temp->next;
	}
}

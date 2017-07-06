/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_helpers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 19:10:21 by abaranov          #+#    #+#             */
/*   Updated: 2017/04/05 19:10:22 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				lst_add(t_ab **stk, int nbr)
{
	t_ab	*new;
	t_ab	*tmp;

	new = (t_ab *)malloc(sizeof(t_ab));
	new->num = nbr;
	new->next = NULL;
	if (*stk == NULL)
		(*stk) = new;
	else
	{
		tmp = *stk;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
}

void				stack_add(t_ab **a, t_ab **b)
{
	if (*a)
		(*b)->next = (*a);
	*a = *b;
}

void				addfirs(t_ab **list, int value)
{
	t_ab *new_node;

	new_node = (t_ab *)malloc(sizeof(t_ab));
	new_node->num = value;
	new_node->next = *list;
	*list = new_node;
}

void				pb(t_ab **a, t_ab **b, t_ab *moves)
{
	t_ab	*tmp;

	(void)(*b);
	if (!(*a))
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = NULL;
	stack_add(b, &tmp);
	lst_add(&moves, 5);
}

void				pa(t_ab **a, t_ab **b, t_ab *moves)
{
	t_ab	*tmp;

	(void)(*b);
	if (!(*a))
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = NULL;
	stack_add(b, &tmp);
	lst_add(&moves, 4);
}

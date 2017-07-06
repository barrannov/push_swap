/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 21:12:55 by abaranov          #+#    #+#             */
/*   Updated: 2017/04/07 13:07:23 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					check_the_same(t_ab *list)
{
	t_ab	*cur;
	t_ab	*temp;
	int		i;
	int		j;

	i = 0;
	cur = list;
	while (cur)
	{
		temp = list;
		j = 0;
		while (temp)
		{
			if (cur->num == temp->num && i != j)
			{
				ft_putstr(RED"Error\n"RED);
				return (0);
			}
			temp = temp->next;
			j++;
		}
		i++;
		cur = cur->next;
	}
	return (1);
}

int					amount_list_el(t_ab *list)
{
	t_ab	*n;
	int		i;

	i = 0;
	if (list != NULL)
	{
		n = list;
		while (n->next != NULL)
		{
			i++;
			n = n->next;
		}
	}
	i++;
	return (i);
}

int					is_valid(char **str)
{
	int			i;
	int			j;
	intmax_t	t;

	j = 0;
	i = 1;
	while (str[i])
	{
		if (str[i][j] == '-')
			j++;
		while (str[i][j])
		{
			t = ft_atoi(str[i]);
			if ((t > 2147483647 || t < -2147483648)
				|| (str[i][j] < 48 || str[i][j] > 57))
			{
				ft_putstr(RED"Error\n"RED);
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

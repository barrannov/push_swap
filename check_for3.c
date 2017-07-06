/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:33:30 by abaranov          #+#    #+#             */
/*   Updated: 2017/04/06 15:33:31 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				rr_ch(t_ab **a, t_ab **b)
{
	ra_ch(a);
	rb_ch(b);
}

int					is_digit(char *d)
{
	int i;

	i = 0;
	if (d[i] == '-')
		i++;
	while (d[i])
	{
		if (d[i] < 48 || d[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

t_ab				*create_numbers_for_check(char **numb, int argc, int val)
{
	int		i;
	t_ab	*temp;
	t_ab	*a;
	int		len;

	len = 0;
	temp = (t_ab *)malloc(sizeof(t_ab));
	a = temp;
	while (numb[len])
		len++;
	i = val;
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

int					is_valid_for_check(char **str, int val)
{
	int			i;
	int			j;
	intmax_t	t;

	j = 0;
	i = val;
	while (str[i])
	{
		if (str[i][j] == '-')
			j++;
		while (str[i][j])
		{
			t = ft_atoi(str[i]);
			if ((t > 2147483647 || t < -2147483648)
				|| ((str[i][j] < 48 || str[i][j] > 57)))
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

int					count_numbers(char **argv)
{
	int		i;
	int		c;

	c = 0;
	i = 0;
	while (argv[i])
	{
		if (is_digit(argv[i]))
			c++;
		i++;
	}
	return (c);
}

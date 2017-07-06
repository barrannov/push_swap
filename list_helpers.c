/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 21:29:32 by abaranov          #+#    #+#             */
/*   Updated: 2017/04/05 21:29:33 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					continue_funct(int *med, int size, int max)
{
	int i;
	int j;
	int t;

	j = 0;
	i = 0;
	while (i < max)
	{
		while (j < max - i)
		{
			if (med[j] > med[j + 1])
			{
				t = med[j];
				med[j] = med[j + 1];
				med[j + 1] = t;
				i = 0;
			}
			j++;
		}
		j = 0;
		i++;
	}
	free(med);
	return (size % 2 == 0) ? med[size / 2] : med[size / 2 + 1];
}

int					find_med(t_ab *a, int size)
{
	int		*med;
	int		max;
	t_ab	*temp;

	max = 0;
	temp = a;
	med = (int *)malloc((size * sizeof(int) + 1) + 1);
	while (max < size)
	{
		med[max] = temp->num;
		temp = temp->next;
		max++;
	}
	return (continue_funct(med, size, max));
}

void				deletefirst(t_ab **head)
{
	t_ab *tmp;

	tmp = *head;
	if (tmp == NULL)
		return ;
	*head = tmp->next;
	free(tmp);
}

void				vizual(t_ab *a, t_ab *b)
{
	t_ab *na;
	t_ab *nb;

	na = a;
	nb = b;
	while (na != NULL || nb != NULL)
	{
		if (na != NULL)
		{
			ft_putnbr(na->num);
			na = na->next;
		}
		if (nb != NULL)
		{
			printf("                %d", nb->num);
			nb = nb->next;
		}
		printf("\n");
	}
	printf("---            ---\n");
	printf(" a              b\n");
}

int					chacker(t_ab *list)
{
	t_ab	*new;
	int		temp;

	new = list;
	if (list != NULL)
	{
		while (new->next != NULL)
		{
			temp = new->num;
			new = new->next;
			if (temp > new->num)
				return (0);
		}
	}
	return (1);
}

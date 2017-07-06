/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 21:45:46 by abaranov          #+#    #+#             */
/*   Updated: 2017/04/07 14:05:21 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int					create_flags(t_flags *fl, char **argv)
{
	int i;

	i = 1;
	if (ft_strcmp(argv[1], "-v") == 0)
	{
		i++;
		fl->v = 1;
		if (ft_strcmp(argv[2], "-n") == 0)
		{
			fl->n = 1;
			i++;
		}
	}
	else if (ft_strcmp(argv[1], "-n") == 0)
	{
		i++;
		fl->n = 1;
		if (ft_strcmp(argv[2], "-v") == 0)
		{
			fl->v = 1;
			i++;
		}
	}
	return (i);
}

void				print_op(int am)
{
	ft_putstr(CYAN"OPERATIONS: "CYAN);
	ft_putnbr(am);
	ft_putstr("\n");
}

int					comp(t_ab **a, t_ab **b, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		sa_ch(a);
	else if (ft_strcmp(line, "sb") == 0)
		sb_ch(b);
	else if (ft_strcmp(line, "ss") == 0)
		ss_ch(*a, *b);
	else if (ft_strcmp(line, "pa") == 0)
		pa_ch(b, a);
	else if (ft_strcmp(line, "pb") == 0)
		pb_ch(a, b);
	else if (ft_strcmp(line, "ra") == 0)
		ra_ch(a);
	else if (ft_strcmp(line, "rb") == 0)
		rb_ch(b);
	else if (ft_strcmp(line, "rr") == 0)
		rr_ch(a, b);
	else if (ft_strcmp(line, "rra") == 0)
		rra_ch(a);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb_ch(b);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr_ch(a, b);
	else
		return (0);
	return (1);
}

int					continue_main(t_flags *flags, t_ab *a)
{
	char	*line;
	t_ab	*b;
	int		j;

	j = 0;
	b = NULL;
	while (get_next_line(0, &line))
	{
		if (!comp(&a, &b, line))
		{
			ft_putstr(RED"Error\n"RED);
			free(line);
			return (0);
		}
		flags->v == 1 ? vizual(a, b) : 0;
		free(line);
		j++;
	}
	free(line);
	chacker(a) ? ft_putstr(GREEN "OK\n" GREEN) : ft_putstr(RED"KO\n"RED);
	(flags->n == 1) ? print_op(j) : 0;
//	ft_del_list(&a);
	ft_del_list(&b);
	return (1);
}

int					main(int argc, char *argv[])
{
	int		val;
	t_ab	*a;
	t_flags	*flags;

	flags = (t_flags *)malloc(sizeof(t_flags) + 1);
	if (argc > 1 && count_numbers(argv) > 0)
	{
		val = create_flags(flags, argv);
		if (!is_valid_for_check(argv, val))
			return (0);
		a = create_numbers_for_check(argv, argc, val);
		if (!check_the_same(a))
			return (0);
		if (!continue_main(flags, a))
			return (0);
	}
	free(flags);
	ft_del_list(&a);
	while(1);
	return (0);
}

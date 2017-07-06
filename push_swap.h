/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:39:05 by abaranov          #+#    #+#             */
/*   Updated: 2017/04/06 15:39:06 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdlib.h"
# include "stdio.h"
# include "libft/libft.h"

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define CYAN    "\x1b[36m"

typedef struct		s_ab
{
	int			num;
	struct s_ab	*next;
}					t_ab;

typedef struct		s_flags
{
	int			v;
	int			n;
}					t_flags;

void				ft_del_list(t_ab **head);
void				delete_9_1_5(t_ab **moves);
int					check_the_same(t_ab *list);
int					is_valid(char **str);
t_ab				*create_numbers(char **numb, int argc);
void				ss(t_ab *a, t_ab *b, t_ab *moves);
void				rrr(t_ab **a, t_ab **b, t_ab *moves);
void				rr(t_ab **a, t_ab **b, t_ab *moves);
void				stack_add(t_ab **a, t_ab **b);
void				rb(t_ab **strc, t_ab *moves);
void				ra(t_ab **strc, t_ab *moves);
void				rra(t_ab **strc, t_ab *moves);
void				rrb(t_ab **strc, t_ab *moves);
void				sa(t_ab **strc, t_ab *moves);
int					is_valid_for_check(char **str, int val);
int					count_numbers(char **argv);
void				b_back_rb_rrb(int j, t_ab **a, t_ab *moves);
void				a_back_ra_rra(int f, int j, t_ab **a, t_ab *moves);
void				sb(t_ab **strc, t_ab *moves);
void				pa(t_ab **from, t_ab **to, t_ab *moves);
void				pb(t_ab **from, t_ab **to, t_ab *moves);
void				move_back_a(t_ab **a, t_ab **b, int size, t_ab *moves);
void				lst_add(t_ab **move, int ind);
int					partition_b(t_ab **a, t_ab **b, int size, t_ab *moves);
int					sort_by_hand_b(t_ab **a, t_ab **b, int size, t_ab *moves);
void				delete_spare(t_ab **moves);
int					chacker(t_ab *list);
int					less_then_med(t_ab *a, int med);
int					more_then_med(t_ab *a, int med);
t_ab				*easy_sort_b(t_ab *a, t_ab *moves);
int					sort_up_a(t_ab *a);
int					sort_up_b(t_ab *a);
void				move_back_b(t_ab **a, t_ab **b, int size, t_ab *moves);
int					find_med(t_ab *a, int size);
t_ab				*easy_sort_a(t_ab *a, t_ab *moves);
void				deletefirst(t_ab **a);
void				ft_push_swap(t_ab **a, t_ab **b, int size, t_ab *moves);
void				delete_6_5_9(t_ab **moves);
void				delete_ra_rb(t_ab **moves);
void				delete_1_6_5(t_ab **moves);
void				print_moves(t_ab **moves);
void				ft_push_swapb(t_ab **a, t_ab **b, int size, t_ab *moves);
void				addfirs(t_ab **list, int value);
int					partition_a(t_ab **a, t_ab **b, int size, t_ab *moves);
int					amount_list_el(t_ab *list);
void				sort_by_hand(t_ab **a, t_ab **b, int size, t_ab *moves);
void				vizual(t_ab *a, t_ab *b);
void				pb_ch(t_ab **a, t_ab **b);
void				pa_ch(t_ab **a, t_ab **b);
void				sa_ch(t_ab **strc);
void				sb_ch(t_ab **strc);
void				rrb_ch(t_ab **a);
void				rb_ch(t_ab **strc);
void				ra_ch(t_ab **strc);
void				rra_ch(t_ab **a);
void				ss_ch(t_ab *a, t_ab *b);
void				rrr_ch(t_ab **a, t_ab **b);
t_ab				*create_numbers_for_check(char **numb, int argc, int val);
int					is_digit(char *d);
void				rr_ch(t_ab **a, t_ab **b);

#endif

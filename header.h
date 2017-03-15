#ifndef PUSH_SWAP_HEADER_H
#define PUSH_SWAP_HEADER_H

# include "stdlib.h"
# include "stdio.h"
# include "libft/libft.h"

typedef struct s_ab {
	int num;
	struct s_ab *next;
} t_ab;

/*
 * tools_f
 */
void sa_sb(t_ab *strc);

void pa_pb(t_ab **from, t_ab **to);

void ss(t_ab *a, t_ab *b);

void ra_rb(t_ab **strc);

void rra_rrb(t_ab **strc);

void rrr(t_ab *a, t_ab *b);

void rr(t_ab *a, t_ab *b);

void delete(t_ab *head);

void stack_add(t_ab **a, t_ab **b);

/*
 * sort_helpers_f
 */

int amount_list_el(t_ab *list);
int is_sorted_list(t_ab *list);
int is_sorted_list_rev(t_ab *list);
int sort_by_hand(t_ab **a, t_ab *b, int size);
void vizual(t_ab *a, t_ab *b);



#endif

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

int count;

void sa_sb(t_ab **strc, t_ab *moves);

void pa_pb(t_ab **from, t_ab **to, t_ab *moves);

void ss(t_ab *a, t_ab *b, t_ab *moves);

void ra_rb(t_ab **strc, t_ab *moves);

void rra_rrb(t_ab **strc, t_ab *moves);

void rrr(t_ab **a, t_ab **b, t_ab *moves);

void rr(t_ab **a, t_ab **b, t_ab *moves);

void delete(t_ab *head);

void stack_add(t_ab **a, t_ab **b);

void rb(t_ab **strc, t_ab *moves);
void ra(t_ab **strc, t_ab *moves);
void rra(t_ab **strc, t_ab *moves);
void rrb(t_ab **strc, t_ab *moves);
void sa(t_ab **strc, t_ab *moves);
void sb(t_ab **strc, t_ab *moves);
void pa(t_ab **from, t_ab **to, t_ab *moves);
void pb(t_ab **from, t_ab **to, t_ab *moves);

void lst_add(t_ab **move, int ind);

void delete_spare(t_ab **moves);
void delete_first(t_ab **a);
int chacker(t_ab *list);
void check_moves(t_ab *moves, t_ab **a);

int sort_up(t_ab *a);
int sort_up_b(t_ab *a);

/*
 * sort_helpers_f
 */

int amount_list_el(t_ab *list);
int is_sorted_list(t_ab *list);
int is_sorted_list_rev(t_ab *list);
int sort_by_hand(t_ab **a, t_ab **b, int size, t_ab *moves);
void vizual(t_ab *a, t_ab *b);



#endif

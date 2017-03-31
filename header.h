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
void ss(t_ab *a, t_ab *b, t_ab *moves);
void rrr(t_ab **a, t_ab **b, t_ab *moves);
void rr(t_ab **a, t_ab **b, t_ab *moves);
void stack_add(t_ab **a, t_ab **b);
void rb(t_ab **strc, t_ab *moves);
void ra(t_ab **strc, t_ab *moves);
void rra(t_ab **strc, t_ab *moves);
void rrb(t_ab **strc, t_ab *moves);
void sa(t_ab **strc, t_ab *moves);
void sb(t_ab **strc, t_ab *moves);
void pa(t_ab **from, t_ab **to, t_ab *moves);
void pb(t_ab **from, t_ab **to, t_ab *moves);
void move_back_a(t_ab **a, t_ab **b, int size, t_ab *moves);
void lst_add(t_ab **move, int ind);
int partition_b(t_ab **a, t_ab **b, int size, t_ab *moves);
int sort_by_hand_b(t_ab **a, t_ab **b, int size, t_ab *moves);
void delete_spare(t_ab **moves);
int chacker(t_ab *list);
void check_moves(t_ab *moves, t_ab **a);
int less_then_med(t_ab *a, int med);
int more_then_med(t_ab *a, int med);
void easy_sort_b(t_ab *a, t_ab *moves);
int sort_up_a(t_ab *a);
int sort_up_b(t_ab *a);
void move_back_b(t_ab **a, t_ab **b, int size, t_ab *moves);
int find_med(t_ab *a, int size);
void easy_sort_a(t_ab *a, t_ab *moves);
void deletefirst(t_ab **a);
void rra_sp(t_ab **a);
void delete_pa_pb(t_ab *moves);
void delete_6_5_9(t_ab **moves);
void delete_ra_rb(t_ab **moves);
void delete_1_6_5(t_ab **moves);
void ra_sp(t_ab **strc);
/*
 * sort_helpers_f
 */

int partition_a(t_ab **a, t_ab **b, int size, t_ab *moves);

int amount_list_el(t_ab *list);
int sort_by_hand(t_ab **a, t_ab **b, int size, t_ab *moves);
void vizual(t_ab *a, t_ab *b);



#endif

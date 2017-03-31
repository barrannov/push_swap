//
// Created by Aleksandr Baranov on 3/31/17.
//

#include "header.h"

int partition_b(t_ab **a, t_ab **b, int size, t_ab *moves)
{
	int med;
	int count;
	int j;
	int f;
	j = 0;
	count = 0;
	f = 0;
	med = find_med(*a, size);
//	if (size == 3)
//	{
//		if ()
//	}
//	else
	int t = amount_list_el(*a);
//	if(t > 3)
//		f = 1;
	while (more_then_med(*a, med))
	{
		//	vizual(*a, *b);
		if ((*a)->num >= med)
		{
			pa(a, b, moves);
			count++;
		}
		else
		{
			j++;
			rb(a, moves);
		}
	}


	if (j > amount_list_el(*a) / 2)
	{
		j = amount_list_el(*a) - j;
		while (j--)
			rb(a, moves);
	}
	else
		while (j--)
			rrb(a, moves);
	return (count);
}
void move_back_b(t_ab **a, t_ab **b, int size, t_ab *moves)
{
	int i;

	i = 0;
	while (i < size)
	{
		pb(b, a, moves);
		i++;
	}
}


void easy_sort_b(t_ab *a, t_ab *moves)
{
	if (sort_up_b(a))
		return;
	if (sort_up_a(a))
	{
		sb(&a, moves);
		rb(&a, moves);
	}
	if (a->num < a->next->num && a->next->num > a->next->next->num && a->num > a->next->next->num)
		sb(&a, moves);
	if (a->num < a->next->num && a->next->num > a->next->next->num && a->num < a->next->next->num)
		rb(&a, moves);
	else if (a->num > a->next->num && a->next->num < a->next->next->num && a->num < a->next->next->num)
		rra(&a, moves);
	if (a->num < a->next->num && a->next->num> a->next->next->num && a->num < a->next->next->num)
		rb(&a, moves);
	if (a->num > a->next->num && a->next->num< a->next->next->num && a->num > a->next->next->num)
	{
		rrb(&a, moves);
		sb(&a, moves);
	}

}

int sort_up_b(t_ab *a)
{
	int w = a->num;
	int y = a->next->num;
	int u = a->next->next->num;
	if (w > y && y > u)
		return (1);
	return (0);
}

int more_then_med(t_ab *a, int med)
{
	t_ab *newNode;


	if (a == NULL)
		return (0);
	newNode = a;
	while (newNode)
	{
		if (newNode->num >= med)
			return (1);
		newNode = newNode->next;
	}
	return (0);
}

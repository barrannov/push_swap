//
// Created by Aleksandr Baranov on 3/31/17.
//

#include "header.h"

void move_back_a(t_ab **a, t_ab **b, int size, t_ab *moves)
{
	int i;

	i = 0;
	while (i < size)
	{
		pa(b, a, moves);
		i++;
	}
}

int sort_up_a(t_ab *a)
{
	int w = a->num;
	int y = a->next->num;
	int u = a->next->next->num;
	if (w < y && y < u)
		return (1);
	return (0);
}


void easy_sort_a(t_ab *a, t_ab *moves)
{


	if (sort_up_a(a))
		return;
	else if (sort_up_b(a))
	{
		sa(&a, moves);
		rra(&a, moves);
	}
	else if (a->num > a->next->num && a->next->num < a->next->next->num && a->num < a->next->next->num)
		sa(&a, moves);
	else if (a->num > a->next->num && a->next->num < a->next->next->num && a->num > a->next->next->num)
		ra(&a, moves);
	else if (a->num < a->next->num && a->next->num > a->next->next->num && a->num > a->next->next->num)
		rra(&a, moves);
	else if (a->num > a->next->num && a->next->num < a->next->next->num && a->num > a->next->next->num)
		ra(&a, moves);
	else if (a->num < a->next->num && a->next->num > a->next->next->num && a->num < a->next->next->num)
	{
		rra(&a, moves);
		sa(&a, moves);
	}

}

int less_then_med(t_ab *a, int med)
{
	t_ab *newNode;


	if (a == NULL)
		return (0);
	newNode = a;
	while (newNode != NULL)
	{
		if (newNode->num <= med)
			return (1);
		newNode = newNode->next;
	}
	return (0);
}



int partition_a(t_ab **a, t_ab **b, int size, t_ab *moves)
{
	int med;
	int count;
	int j;
	int f;

	f = 0;
	j = 0;
	count = 0;
	med = find_med(*a, size);
	if (amount_list_el(*b) != 0)
		f = 1;
	while (less_then_med(*a, med))
	{
//		if(amount_list_el(*a) == 3)
//			break;

		if ((*a)->num <= med)
		{
			pb(a, b, moves);
			count++;
		}
		else
		{
			j++;
			ra(a, moves);
		}
	}
	vizual(*a, *b);
	if (f == 1)
	{
		if (j > amount_list_el(*a) / 2)
		{
			j = amount_list_el(*a) - j;
			while (j--)
				ra(a, moves);
		}
		else
			while (j--)
				rra(a, moves);
	}
	return (count);
}


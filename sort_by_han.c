//
// Created by Aleksandr Baranov on 3/31/17.
//


#include "header.h"

int sort_by_hand_b(t_ab **a, t_ab **b, int size, t_ab *moves)
{
	t_ab *newNode;
	t_ab *newNodeb;

	newNodeb = *b;
	newNode = *a;

	vizual(*a, *b);

	if (amount_list_el(*a) == 3)

		easy_sort_b(*a, moves);

	else
	{
		if (size >= 2)
		{
			if (newNode->num < newNode->next->num)
			{
				if (amount_list_el(newNodeb) > 1)
				{
					if ((newNodeb)->num > (newNodeb)->next->num)
						ss(newNode, newNodeb, moves);
					else
						sb(&newNode, moves);
				}
				else
					sb(&newNode, moves);
			}
		}
		if (size == 3)
		{
			if (newNode->next->num < newNode->next->next->num)
			{
				if (amount_list_el(newNodeb) > 2)
				{
					if ((*b)->next->num > (*b)->next->next->num)
					{
						rr(&newNode, &newNodeb, moves);
						ss(newNode, newNodeb, moves);
						rrr(&newNode, &newNodeb, moves);

					}
					else
					{
						rb(&newNode, moves);
						//	ft_putstr("ra\n");
						if ((newNodeb)->num > (newNodeb)->next->num)
							ss(newNode, newNodeb, moves);
						else
							sb(&newNode, moves);
						//	ft_putstr("sa\n");
						rrb(&newNode, moves);
					}
				}
				else
				{
					rb(&newNode, moves);
					//	ft_putstr("ra\n");
					if ((newNodeb)->num > (newNodeb)->next->num)
						ss(newNode, newNodeb, moves);
					else
						sb(&newNode, moves);
					//	ft_putstr("sa\n");
					rrb(&newNode, moves);
					//	ft_putstr("rra\n");
					//vizual(*a, b);
				}
			}
			if (!sort_up_b(newNode))
				sort_by_hand_b(a, b, size, moves);
		}
	}
	return (0);
}

int sort_by_hand(t_ab **a, t_ab **b, int size, t_ab *moves)
{
	t_ab *newNode;
	t_ab *newNodeb;

	newNodeb = *b;
	newNode = *a;

	//vizual(*a, *b);
	if (amount_list_el(*a) == 3)
		easy_sort_a(*a, moves);
	else
	{
		if (size >= 2)
		{
			if (newNode->num > newNode->next->num)
			{
				if (amount_list_el(newNodeb) > 1)
				{
					if ((newNodeb)->num < (newNodeb)->next->num)
						ss(newNode, newNodeb, moves);
					else
						sa(&newNode, moves);
				}
				else
					sa(&newNode, moves);
			}
		}
		if (size == 3)
		{
			if (newNode->next->num > newNode->next->next->num)
			{
				if (amount_list_el(newNodeb) > 2)
				{
					if ((*b)->next->num < (*b)->next->next->num)
					{
						rr(&newNode, &newNodeb, moves);
						ss(newNode, newNodeb, moves);
						rrr(&newNode, &newNodeb, moves);

					}
					else
					{
						ra(&newNode, moves);
						//	ft_putstr("ra\n");
						if ((newNodeb)->num < (newNodeb)->next->num)
							ss(newNode, newNodeb, moves);
						else
							sa(&newNode, moves);
						rra(&newNode, moves);
					}
				}
				else
				{
					ra(&newNode, moves);
					//	ft_putstr("ra\n");
					if (amount_list_el(newNodeb) > 2)
					{

						if ((newNodeb)->num < (newNodeb)->next->num)
							ss(newNode, newNodeb, moves);
						else
							sa(&newNode, moves);
					}
					sa(&newNode, moves);
					//sa(&newNode, moves);
					//	ft_putstr("sa\n");
					rra(&newNode, moves);
				}//	ft_putstr("rra\n");
			}
			if (!sort_up_a(newNode))
				return sort_by_hand(&newNode, b, size, moves);
		}
	}
	return (0);
}
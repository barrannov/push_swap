#include "header.h"


int amount_list_el(t_ab *list)
{
	t_ab *newNode;
	int i;

	i = 0;
	if (list != NULL)
	{
		newNode = list;
		while (newNode->next != NULL)
		{
			i++;
			newNode = newNode->next;
		}
	}
	i++;
	return (i);
}


int is_sorted_list(t_ab *list)
{
	t_ab *newNode;
	int i;

	if (list != NULL)
	{
		newNode = list;
		while (newNode->next->next != NULL)
		{
			i = newNode->num;
			newNode = newNode->next;
			if (i > newNode->num)
				return (0);
		}
	}
	return (1);
}

int is_sorted_list_three(t_ab *list)
{
	t_ab *newNode;
	int i;

	if (list != NULL)
	{
		if (list->num < list->next->num && list->next->num < list->next->next->next->num)
			return (1);
	}
	return (0);
}


int is_sorted_list_rev(t_ab *list)
{
	t_ab *newNode;
	int i;

	if (list != NULL)
	{
		newNode = list;
		while (newNode->next->next != NULL)
		{
			i = newNode->num;
			newNode = newNode->next;
			if (i < newNode->num)
				return (0);
		}
	}
	return (1);
}

//void list_to_array(t_ab *list)
//{
//	t_ab *newNode;
//	int i;
//	int *res;
//
//	res = (int)malloc()
//	i = 0;
//	if (list != NULL)
//	{
//		newNode = list;
//		while (newNode->next != NULL)
//		{
//			newNode = newNode->next;
//		}
//	}
//}
//

int sort_up(t_ab *a)
{
	int w = a->num;
	int y = a->next->num;
	int u = a->next->next->num;
	if (w < y && y < u)
		return (1);
	return (0);
}

void easy_sort(t_ab *a, t_ab *moves)
{


	if (sort_up(a))
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

int sort_by_hand(t_ab **a, t_ab **b, int size, t_ab *moves)
{
	t_ab *newNode;
	t_ab *newNodeb;

	newNodeb = *b;
	newNode = *a;

	//vizual(*a, *b);
	if (amount_list_el(*a) == 3)
		easy_sort(*a, moves);
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
			if (!sort_up(newNode))
				return sort_by_hand(&newNode, b, size, moves);
		}
	}
	return (0);
}


/*

int sort_by_hand(t_ab **a, t_ab **b, int size, t_ab *moves)
{
	t_ab *newNode;

	newNode = *a;
	if (size >= 2)
	{
		if (newNode->num > newNode->next->num)
		{
			//vizual(*a, *a);

			sa(&newNode, moves);
			//	ft_putstr("sa\n");
		}
	}
	if (size == 3)
	{
		if (newNode->next->num > newNode->next->next->num)
		{
			ra(&newNode, moves);
			//	ft_putstr("ra\n");
			sa(&newNode, moves);
			//	ft_putstr("sa\n");
			rra(&newNode, moves);
			//	ft_putstr("rra\n");
		}
		if (!sort_up(newNode))
			return sort_by_hand(a, b, size, moves);
	}
	return (0);
}*/

#include "header.h"


int amount_list_el(t_ab *list)
{
	t_ab *newNode;
	int i;

	i = 0;
	if (list != NULL)
	{
		newNode = list;
		while (newNode != NULL)
		{
			i++;
			newNode = newNode->next;
		}
	}
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

int sort_by_hand(t_ab **a, t_ab **b, int size, t_ab *moves)
{
	t_ab *newNode;

	newNode = *a;
	if (size >= 2)
	{
		if (newNode->num > newNode->next->num)
		{
			//vizual(*a, *a);

//			if (amount_list_el(*b) > 1)
//			{
//				if ((*b)->num < (*b)->next->num)
//					ss(*a, *b, moves);
//			}
//			else
				sa(&newNode, moves);
			//	ft_putstr("sa\n");
		}
	}
	if (size == 3)
	{
		if (newNode->next->num > newNode->next->next->num)
		{
//			if ((*b)->next->num < (*b)->next->next->num)
//			{
//				rr(*a, *b, moves);
//				ss(*a, *b, moves);
//				rr(*a, *b, moves);
//
//			}
//			else
//			{
			ra(&newNode, moves);
			//	ft_putstr("ra\n");
			sa(&newNode, moves);
			//	ft_putstr("sa\n");
			rra(&newNode, moves);
		}//	ft_putstr("rra\n");
		//}
		if (!sort_up(newNode))
			return sort_by_hand(a, b, size, moves);
	}
	return (0);
}
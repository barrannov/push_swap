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
	if (a->num < a->next->num && a->num < a->next->next->num)
		return (1);
	return (0);
}

int sort_by_hand(t_ab **a, t_ab *b)
{
	t_ab *newNode;

	newNode = *a;
	if (newNode->num > newNode->next->num)
	{
		//vizual(*a, *a);
		sa_sb(newNode);
		ft_putstr("sa\n");
	}
	if (amount_list_el(*a) == 3)
		if (newNode->next->num > newNode->next->next->num)
		{
			ra_rb(&newNode);
			ft_putstr("ra\n");
			sa_sb(newNode);
			ft_putstr("sa\n");
			rra_rrb(&newNode);
			ft_putstr("rra\n");
		}
	if (!is_sorted_list(newNode))
		return sort_by_hand(a, b);
	return (0);
}
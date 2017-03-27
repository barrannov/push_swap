#include "header.h"

//
// Created by Aleksandr Baranov on 3/20/17.
//

static void ra_sp(t_ab **strc)
{
	t_ab *tmp;
	t_ab *end;

	if (*strc == NULL)
		return;
	if (!(*strc)->next)
		return;
	end = *strc;
	(*strc) = (*strc)->next;
	tmp = *strc;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = end;
	end->next = NULL;
}

static void pa_sp(t_ab **a, t_ab **b)
{
	t_ab *tmp;
	(void) (*b);
	if (!(*a))
		return;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = NULL;
	stack_add(b, &tmp);
}

int spare(t_ab *moves)
{
	t_ab *temp;
	int i;
	int t;
	int c;

	temp = moves;
	i = 0;
	c = amount_list_el(moves);
	while (i < c)
	{
		t = temp->num;
		ra_sp(&temp);
		if (temp->num == 1 && temp->next->num == 2 || temp->num == 2 && temp->next->num == 1)
			return (1);
		i++;
	}
	return (0);
}


static void rra_sp(t_ab **a)
{
	t_ab *tmp;
	t_ab *end;
	int i;

	if (!(*a) || !(*a)->next)
		return;
	tmp = *a;
	i = amount_list_el(tmp) - 2;
	while (i--)
		tmp = tmp->next;
	end = tmp->next;
	tmp->next = NULL;
	end->next = (*a);
	(*a) = end;
}


void deletefirst(t_ab **a)
{
	t_ab *tmp;
	if (!(*a))
		return;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = NULL;
}
//void deletefirst(t_ab **head)
//{
//	t_ab *tmp = *head;            // save old head for freeing.
//	if (tmp == NULL) return;             // list empty? then do nothing.
//	*head = tmp->next;                   // advance head to second node.
//	free(tmp);                          // free old head.
//}

int amount(t_ab *list)
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
			if (newNode->next == NULL)
				break;
			newNode = newNode->next;
		}
	}
	return (i);
}

//void delete_pa_pb(t_ab *moves)
//{
//	t_ab *cur;
//	int i;
//
//	cur = moves;
////	vizual(cur, cur);
//	int j;
//	int cou;
//
//	i = 0;
//	cou = amount_list_el(moves);
//	j = 0;
//	while (i < cou)
//	{
//		cou = amount_list_el(cur);
////		if (cur->num == 4 && cur->next->num == 5 || cur->num == 5 && cur->next->num == 4)
////		{
////			deletefirst(&cur);
////			deletefirst(&cur);
////			while (j--)
////				rra_sp(&cur);
////			j = 0;
////			i = 0;
////		}
////		else if (cur->num == 6 && cur->next->num == 9 || cur->num == 9 && cur->next->num == 6)
////		{
////			deletefirst(&cur);
////			deletefirst(&cur);
////			while (j--)
////				rra_sp(&cur);
////			j = 0;
////			i = 0;
////		}
////		else if (cur->num == 1 && cur->next->num == 2 || cur->num == 2 && cur->next->num == 1)
////		{
////			deletefirst(&cur);
////			cur->num = 3;
////			while (j--)
////				rra_sp(&cur);
////			j = 0;
////			i = 0;
////		}
////		else if (cur->num == 7 && cur->next->num == 10 || cur->num == 10 && cur->next->num == 7)
////		{
////			deletefirst(&cur);
////			deletefirst(&cur);
////			while (j--)
////				rra_sp(&cur);
////			j = 0;
////			i = 0;
////		}
////		else if (cur->num == 7 && cur->next->num == 4 && cur->next->next->num == 10)
////		{
////			deletefirst(&cur);
////			cur->num = 2;
////			cur->next->num = 4;
////			while (j--)
////				rra_sp(&cur);
////			j = 0;
////			i = 0;
////		}
////		else if (cur->num == 6 && cur->next->num == 5 && cur->next->next->num == 9)
////		{
////			deletefirst(&cur);
////			cur->num = 1;
////			cur->next->num = 5;
////			while (j--)
////				rra_sp(&cur);
////			j = 0;
////			i = 0;
////		}
//		//else
//		{
//			j++;
//			ra_sp(&cur);
//		}
//		i++;
//	}
//	while (j--)
//		rra_sp(&cur);
//}






void delete_6_5_9(t_ab **moves)
{
	t_ab *cur;
	t_ab *temp;
	cur = *moves;

	while ((cur)->next->next->next)
	{
		if (cur->next->num == 6 && cur->next->next->num == 5 && cur->next->next->next->num == 9)
		{
			temp = cur->next;
			cur->next = temp->next;
			free(temp);
			cur->next->num = 1;
			cur->next->next->num = 5;
		}
		else if (cur->next->num == 7 && cur->next->next->num == 4 && cur->next->next->next->num == 10)
		{
			temp = cur->next;
			cur->next = temp->next;
			free(temp);
			cur->next->num = 2;
			cur->next->next->num = 4;
		}
		else
			cur = (cur)->next;
	}
}





void delete_ra_rb(t_ab **moves)
{
	t_ab *cur;
	t_ab *temp;
	cur = *moves;

	while ((cur)->next->next)
	{
		if (cur->next->num == 6 && cur->next->next->num == 7)
		{
			temp = cur->next;
			cur->next = temp->next;
			cur->next->num = 8;
			free(temp);
		}
		else
			cur = (cur)->next;
	}
}


void remove_pa_pb(t_ab **moves)
{
	t_ab *cur;
	t_ab *temp;
	cur = *moves;

	while ((cur)->next->next)
	{
		if (cur->next->num == 4 && cur->next->next->num == 5
			|| cur->next->num == 5 && cur->next->next->num == 4)
		{
			temp = cur->next;
			cur->next = temp->next;
			free(temp);
			temp = cur->next;
			cur->next = temp->next;
			free(temp);
			cur = *moves;
		}
		else
			cur = (cur)->next;
	}
}

void replace_sa_sb(t_ab **moves)
{
	t_ab *cur;
	t_ab *temp;
	cur = *moves;

	while ((cur)->next->next)
	{
		if (cur->next->num == 1 && cur->next->next->num == 2
			|| cur->next->num == 2 && cur->next->next->num == 1)
		{
			temp = cur->next;
			cur->next = temp->next;
			cur->next->num = 3;
			free(temp);
		}
		else
			cur = (cur)->next;
	}
}

void remove_ra_rrb(t_ab **moves)
{
	t_ab *cur;
	t_ab *temp;
	cur = *moves;

	while ((cur)->next->next)
	{
		if (cur->next->num == 7 && cur->next->next->num == 10
			|| cur->next->num == 10 && cur->next->next->num == 7)
		{
			temp = cur->next;
			cur->next = temp->next;
			free(temp);
			temp = cur->next;
			cur->next = temp->next;
			free(temp);
		}
		else
			cur = (cur)->next;
	}
}
void remove_6_9(t_ab **moves)
{
	t_ab *cur;
	t_ab *temp;
	cur = *moves;

	while ((cur)->next->next)
	{
		if (cur->next->num == 6 && cur->next->next->num == 9
			|| cur->next->num == 9 && cur->next->next->num == 6)
		{
			temp = cur->next;
			cur->next = temp->next;
			free(temp);
			temp = cur->next;
			cur->next = temp->next;
			free(temp);
		}
		else
			cur = (cur)->next;
	}
}

void delete_spare(t_ab **moves)
{
	remove_pa_pb(moves);
	//replace_sa_sb(moves);
	delete_6_5_9(moves);
	remove_6_9(moves);
	remove_ra_rrb(moves);
	delete_ra_rb(moves);






//	while ((cur)->next->next)
//	{
//		if (cur->next->num == 4 && cur->next->next->num == 5
//			|| cur->next->num == 5 && cur->next->next->num == 4)
//		{
//			temp = cur->next;
//			cur->next = temp->next;
//			free(temp);
//			temp = cur->next;
//			cur->next = temp->next;
//			free(temp);
//			cur = *moves;
//		}
////		if ((cur)->num == 6 && cur->next->num == 7)
////		{
////			deletefirst(&cur);
////			(cur)->num = 8;
////		}
////		else if ((cur)->num == 7 && cur->next->num == 6)
////		{
////			deletefirst(&cur);
////			(cur)->num = 8;
////		}
//		else
//			cur = (cur)->next;
//	}
//	*moves = rewrite(cur);
}

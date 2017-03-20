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

	if (!(*a) || !(*a)->next)
		return;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	end = tmp->next;
	tmp->next = NULL;
	end->next = (*a);
	(*a) = end;
}

//
//void delete_first(t_ab **a)
//{
//	t_ab *tmp;
//	if (!(*a))
//		return;
//	tmp = (*a);
//	(*a) = (*a)->next;
//	tmp->next = NULL;
//}
void deletefirst(t_ab **head)
{
	t_ab *tmp = *head;            // save old head for freeing.
	if (tmp == NULL) return;             // list empty? then do nothing.
	*head = tmp->next;                   // advance head to second node.
	free(tmp);                          // free old head.
}

void delete_pa_pb(t_ab *moves)
{
	t_ab *cur;
	int i;

	cur = moves;
//	vizual(cur, cur);
	int j;
	int cou;

	i = 0;
	cou = amount_list_el(moves);
	j = 0;
	while (i < cou)
	{
		if (cur->num == 4 && cur->next->num == 5 || cur->num == 5 && cur->next->num == 4)
		{
//			cur->num = -1;
//			cur = cur->next;
//			cur->num = -1;
			deletefirst(&cur);
			deletefirst(&cur);
			//while (j--)
			//	rra_sp(&cur);
			j = 0;
			i = 0;
			//	vizual(cur, cur);
		}
		else
		{
			j++;
			ra_sp(&cur);
		}
		i++;

		//printf("\ncount list: %d", amount_list_el(moves));
	}
	while (j--)
		rra_sp(&cur);
}

void delete_spare(t_ab **moves)
{
	int i;
	t_ab *garb;
	t_ab *cur;
	int j;

	j = 0;
	cur = *moves;
	garb = NULL;
	i = 0;
	delete_pa_pb(*moves);

//	while (spare(*moves))
//	{
//		if (cur->num == 1 && cur->next->num == 2 || cur->num == 2 && cur->next->num == 1)
//		{
//			if (cur->next->num > cur->num)
//			{
//				pa_sp(&cur, &garb);
//				cur->num += 1;
//			}
//			else if (cur->num > cur->next->num)
//			{
//				pa_sp(&cur, &garb);
//				cur->num += 2;
//			}
//		}
//		else
//		{
//			j++;
//			ra_sp(&cur);
//		}
//		i++;
//	}
//	while(j--)
//		rra_sp(&cur);
}

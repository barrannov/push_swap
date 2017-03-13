#include "header.h"

int is_valid(char **str)
{
	int i;
	int j;

	j = 0;
	i = 1;
	while (str[i])
	{
		while (str[i][j])
		{
			if (str[i][j] < 48 || str[i][j] > 57)
				return (0);

			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

t_ab *create_numbers(char **numb, int argc)
{
	int i;
	t_ab *temp;
	t_ab *a;
	int len;

	temp = (t_ab *) malloc(sizeof(t_ab));
	a = temp;
	i = 1;
	while (i  < argc)
	{
		temp->num = ft_atoi(numb[i]);
		i++;
		if (numb[i])
		{
			temp->next = (t_ab *) malloc(sizeof(t_ab));
			temp = temp->next;
		temp->next = NULL;
		}
		temp->next = NULL;
	}
	printf("NULL: %d\n", temp->num);
	//free(temp);
//	temp->next = NULL;

	return (a);
}

void vizual(t_ab *a, t_ab *b)
{
	t_ab *na;
	t_ab *nb;

	na = a;
	nb = b;
	printf("\n/////////////////////////////////////////////////\n");
	printf("//     %5s %20s           //\n//                                             //\n", "Stack A:", "Stack B:");
	while (na != NULL || nb != NULL)
	{
		printf("//");

		printf("            ");
		if (na != NULL)
		{
			printf("%d", na->num);
			na = na->next;
		}
		if (nb != NULL)
		{
			printf("               %d//", nb->num);
			nb = nb->next;
		}
		else
			printf("%20s", "//");

		printf("\n");
	}

	printf("/////////////////////////////////////////////////");
}

int find_max(t_ab *a)
{
	t_ab *newNode;
	int max;
	int cur;

	if (a == NULL)
		return (0);
	newNode = a;
	max = newNode->num;
	while (newNode->next != NULL)
	{
		cur = newNode->num;
		if (cur > max)
			max = cur;
		newNode = newNode->next;
	}
	return max;
}

int find_min(t_ab *a)
{
	t_ab *newNode;
	int min;
	int cur;


	if (a == NULL)
		return (0);
	newNode = a;
	min = newNode->num;
	while (newNode->next != NULL)
	{
		cur = newNode->num;
		if (cur < min)
			min = cur;
		newNode = newNode->next;
	}
	return min;
}


int find_med(t_ab *a)
{
	int med;
	int min;
	int max;

	max = find_max(a);
	min = find_min(a);
	med = (max + min) / 2;
	return (med);
}


int less_then_med(t_ab *a, int med)
{
	t_ab *newNode;


	if (a == NULL)
		return (0);
	newNode = a;
	while (newNode->next != NULL)
	{
		if (newNode->num <= med)
			return (1);
		newNode = newNode->next;
	}
	return (0);
}


void move_back(t_ab **a, t_ab **b, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		pa_pb(b, a);
		i++;
	}
}

int partition(t_ab **a, t_ab **b, int size)
{
	int med;
	int count;

	count = 0;
	med = find_med(*a);
	while (less_then_med(*a, med))
	{
		ra_rb(a);
		if ((*a)->num <= med)
		{
			pa_pb(a, b);
			count++;
		}
	}
	return (count);
}

void ft_push_swapb(t_ab **a, t_ab **b, int size)
{
	int n_pushed;

	printf("\n%d", size);
	if (size > 3)
	{
		n_pushed = partition(a, b, size);
		vizual(*a, *b);
		ft_push_swapb(b, a, n_pushed);
		move_back(a, b, n_pushed);
	}
	else
	{
		sort_by_hand(b, *a);

	}
}

void ft_push_swap(t_ab **a, t_ab **b, int size)
{
	int n_pushed;

	printf("\n%d", size);
	if (size > 3)
	{
		n_pushed = partition(a, b, size);
		vizual(*a, *b);
		ft_push_swap(a, b, size - n_pushed);
		vizual(*a, *b);
		ft_push_swapb(b, a, n_pushed);
		move_back(a, b, n_pushed);
	}
	else
	{
		sort_by_hand(a, *b);

	}
}


int main(int arg, char *argv[])
{
	t_ab *a;
	t_ab *b;
	int res;
	int size;

	int med;

	res = 0;
	b = NULL;
	//b->num = 106789567;
	//b->next = NULL;
	if (!is_valid(argv))
	{
		ft_putstr("Error\n");
		return (0);
	}
	a = create_numbers(argv, arg);
	vizual(a, b);

	size = amount_list_el(a);
	ft_push_swap(&a, &b, size);
	//vizual(a, b);

	vizual(a, b);
	printf("%d\n", a->num);

//	list = (t_ab *) malloc(sizeof(t_ab));;
//	list->next = (t_ab*)malloc(sizeof(t_ab));
//
//	list->num = 1;
//	list->next->num = 2;
//
//	list = (t_ab *) malloc(sizeof(t_ab));;
//	list->next = (t_ab *) malloc(sizeof(t_ab));
//	list->next->next = (t_ab *) malloc(sizeof(t_ab));
//	list->next->next->next = (t_ab *) malloc(sizeof(t_ab));
//
//
//	list->num = 1;
//	list->next->num = 2;
//	list->next->next->num = 3;
//	list->next->next->next->num = 4;
//	list->next->next->next->next = NULL;
//
//
//
//	t_ab *list2;
//	list2 = (t_ab *) malloc(sizeof(t_ab));;
//	list2->next = (t_ab *) malloc(sizeof(t_ab));
//	list2->next->next = (t_ab *) malloc(sizeof(t_ab));
//	list2->next->next->next = (t_ab *) malloc(sizeof(t_ab));
//
//
//	list2->num = 5;
//	list2->next->num = 6;
//	list2->next->next->num = 7;
//	list2->next->next->next->num = 8;
//	list2->next->next->next->next = NULL;
//
//	//printf("%d\n",list.num);
//	//printf("%d\n",list.next->num);
//	printf("%d\n", list2->num);
//	printf("%d\n", list2->next->num);
//	printf("%d\n", list2->next->next->num);
//	printf("%d\n", list2->next->next->next->num);
//
//	printf("\n");
//	pa_pb(&list, &list2);
//	rra_rrb(&list2);
//
//	printf("%d\n", list2->num);
//	printf("%d\n", list2->next->num);
//	printf("%d\n", list2->next->next->num);
//	printf("%d\n", list2->next->next->next->num);
////	printf("%d\n", list2->next->next->next->next->num);
//
//	printf("\n");
//	rra_rrb(&list2);
//
//	printf("%d\n", list2->num);
//	printf("%d\n", list2->next->num);
//	printf("%d\n", list2->next->next->num);
//	printf("%d\n", list2->next->next->next->num);
//
//
//	printf("\n");
//	rra_rrb(&list2);
//
//	printf("%d\n", list2->num);
//	printf("%d\n", list2->next->num);
//	printf("%d\n", list2->next->next->num);
//	printf("%d\n", list2->next->next->next->num);
//
//
//	printf("\n");
//	rra_rrb(&list2);
//
//	printf("%d\n", list2->num);
//	printf("%d\n", list2->next->num);
//	printf("%d\n", list2->next->next->num);
//	printf("%d\n", list2->next->next->next->num);
//
//
//	printf("\n");
//	rra_rrb(&list2);
//
//	printf("%d\n", list2->num);
//	printf("%d\n", list2->next->num);
//	printf("%d\n", list2->next->next->num);
//	printf("%d\n", list2->next->next->next->num);



//	printf("%d\n", list2->next->next->next->next->num);
//	printf("%d\n", list2->next->next->next->next->next->num);
	return (0);
}

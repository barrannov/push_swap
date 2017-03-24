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
	while (i < argc)
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
	//printf("NULL: %d\n", temp->num);
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

int find_max(t_ab *a, int size)
{
	t_ab *newNode;
	int max;
	int cur;
	int i;

	i = 0;
	if (a == NULL)
		return (0);
	newNode = a;
	max = newNode->num;
	while (i < size && newNode->next != 0)
	{
		cur = newNode->num;
		if (cur > max)
			max = cur;
		newNode = newNode->next;
		i++;
	}
	return max;
}

int find_min(t_ab *a, int size)
{
	t_ab *newNode;
	int min;
	int cur;
	int i;

	i = 0;
	if (a == NULL)
		return (0);
	newNode = a;
	min = newNode->num;
	while (i < size)
	{
		cur = newNode->num;
		if (cur < min)
			min = cur;
		newNode = newNode->next;
		i++;
	}
	return min;
}

int *bulb(int *ar)
{
	int temp;
	int i;
	int t;
	int j;

	j = 0;
	i = 1;

	return ar;
}

int find_med(t_ab *a, int size)
{
	int med[size];
	int max;
	t_ab *temp;
	int i;
	int j;
	int t;
	int len;
	j = 0;
	i = 0;
	max = 0;
	len = 0;
	temp = a;

	while (max < size)
	{
		med[max] = temp->num;
		temp = temp->next;
		max++;
	}

	len = max;
	while (i < len)
	{
		while (j < len - i)
		{
			if (med[j] > med[j + 1])
			{
				t = med[j];
				med[j] = med[j + 1];
				med[j + 1] = t;
				i = 0;
			}
			j++;
		}
		j = 0;
		i++;
	}
	//res = bulb(med);
	//max = find_max(a, size);
	//min = find_min(a, size);
	//med = (max + min) / 2;
	int md = med[max / 2];
	return (md);
}

//int find_med(t_ab *a, int size)
//{
//	int med;
//	int min;
//	int max;
//
//	max = find_max(a, size);
//	min = find_min(a, size);
//	med = (max + min) / 2;
//	return (med);
//}

int more_then_med(t_ab *a, int med)
{
	t_ab *newNode;


	if (a == NULL)
		return (0);
	newNode = a;
	while (newNode)
	{
		if (newNode->num > med)
			return (1);
		newNode = newNode->next;
	}
	return (0);
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

//
//void move_back(t_ab **a, t_ab **b, int size)
//{
//	int i;
//
//	i = 0;
//	while (i < size)
//	{
//		ra_rb(b);
//		//	vizual(*a, *b);
//		i++;
//	}
//
//	while (i--)
//	{
//		rra_rrb(b);
//		pa_pb(b, a);
//		//	if(i + 1)
//		//	vizual(*a, *b);
//		//	i--;
//	}
//}

int partition(t_ab **a, t_ab **b, int size, t_ab *moves)
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

int partitionB(t_ab **a, t_ab **b, int size, t_ab *moves)
{
	int med;
	int count;
	int j;

	j = 0;
	count = 0;
	med = find_med(*a, size);
//	if (size == 3)
//	{
//		if ()
//	}
//	else
	{
		while (more_then_med(*a, med))
		{
			//	vizual(*a, *b);
			if ((*a)->num >= med)
			{
				count++;
				pa(a, b, moves);
			}
			else
			{
				j++;
				rb(a, moves);
			}
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

void ft_push_swap(t_ab **a, t_ab **b, int size, t_ab *moves);

int sort_up_b(t_ab *a)
{
	int w = a->num;
	int y = a->next->num;
	int u = a->next->next->num;
	if (w > y && y > u)
		return (1);
	return (0);
}

int chacker(t_ab *list)
{
	t_ab *new;
	int temp;

	new = list;
	if (list != NULL)
	{
		while (new->next != NULL)
		{
			temp = new->num;
			new = new->next;
			if (temp > new->num)
				return 0;
		}
	}
	return (1);
}


int sort_by_hand_b(t_ab **a, t_ab **b, int size, t_ab *moves)
{
	t_ab *newNode;
	t_ab *newNodeb;

	newNodeb = *b;
	newNode = *a;
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
			rb(&newNode, moves);
			//	ft_putstr("ra\n");
			sb(&newNode, moves);
			//	ft_putstr("sa\n");
			rrb(&newNode, moves);
			//	ft_putstr("rra\n");
			//vizual(*a, b);
		}
		if (!sort_up_b(newNode))
			sort_by_hand_b(a, b, size, moves);
	}
	return (0);
}

void ft_push_swapb(t_ab **a, t_ab **b, int size, t_ab *moves)
{
	int n_pushed;

	//printf("\n%d", size);
	if (size > 3)
	{
		n_pushed = partitionB(a, b, size, moves);
		//vizual(*a, *b);
		ft_push_swapb(a, b, size - n_pushed, moves);
		//vizual(*a, *b);
		ft_push_swap(b, a, n_pushed, moves);
		//vizual(*a, *b);
		move_back_b(a, b, n_pushed, moves);
		//vizual(*a, *b);
	}
	else
		sort_by_hand_b(a, b, size, moves);
}

void ft_push_swap(t_ab **a, t_ab **b, int size, t_ab *moves)
{
	int n_pushed;

//	printf("\n%d", size);
	if (size > 3)
	{
		n_pushed = partition(a, b, size, moves);
		//vizual(*a, *b);
		ft_push_swap(a, b, size - n_pushed, moves);
		//vizual(*a, *b);
		ft_push_swapb(b, a, n_pushed, moves);
		//vizual(*a, *b);
		move_back_a(a, b, n_pushed, moves);
		//vizual(*a, *b);

	}
	else
		sort_by_hand(a, b, size, moves);

}


int main(int arg, char *argv[])
{

	t_ab *a;
	t_ab *b;
	int size;
	t_ab *moves;
	t_ab *temp_for_num;

	moves = NULL;

	lst_add(&moves, 5);
//	lst_add(&moves, 6);
	//lst_add(&moves, 7);
	b = NULL;
	if (!is_valid(argv))
	{
		ft_putstr("Error\n");
		return (0);
	}
	a = create_numbers(argv, arg);
	temp_for_num = create_numbers(argv, arg);

	printf("sorted: ");
	if (chacker(a))
		printf("YES");
	else
		printf("NO");

//	vizual(a, b);
	size = amount_list_el(a);

	if (!chacker(a))
		ft_push_swap(&a, &b, size, moves);
	vizual(a, b);

	printf("\nsorted: ");

	if (chacker(a))
	{
		printf("YES");
	}
	else
		printf("NO");
//	//Костыль который редактирует баг при котором в лист не добавляются движения если в нем ничего нет
	moves = moves->next;
	//vizual(moves, moves);

	delete_spare(&moves);

//	vizual(a, b);
//	delete_first(&a);
//	vizual(a, b);

	printf("\namount numbers: %d", size);
	printf("\ncount: %d", count);
	printf("\ncount list: %d\n", amount_list_el(moves));
	t_ab *temp;

	temp = moves;
//	while (temp)
//	{
//
//		ft_putnbr(temp->num);
//
//			temp = temp->next;
//			ft_putstr("\n");
//	}
	//vizual(moves, moves);
//	vizual(temp_for_num, temp_for_num);
	check_moves(moves, &temp_for_num);
	return (0);
}

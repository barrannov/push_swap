#include "header.h"

void ft_push_swap(t_ab **a, t_ab **b, int size, t_ab *moves);
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
	return (a);
}






void ft_push_swapb(t_ab **a, t_ab **b, int size, t_ab *moves)
{
	int n_pushed;

	//printf("\n%d", size);
//	vizual(*b, *a);

	if (size > 3)
	{
		n_pushed = partition_b(a, b, size, moves);
		//vizual(*a, *b);
		ft_push_swap(b, a, n_pushed, moves);
		//vizual(*a, *b);
		ft_push_swapb(a, b, size - n_pushed, moves);
		//vizual(*a, *b);
		move_back_b(a, b, n_pushed, moves);
	}
	else
		sort_by_hand_b(a, b, size, moves);
}

void ft_push_swap(t_ab **a, t_ab **b, int size, t_ab *moves)
{
	int n_pushed;

//	printf("\n%d", size);
//	vizual(*a, *b);

	if (size > 3)
	{
		n_pushed = partition_a(a, b, size, moves);
		//vizual(*a, *b);
		ft_push_swap(a, b, size - n_pushed, moves);
		//vizual(*a, *b);
		ft_push_swapb(b, a, n_pushed, moves);
		//vizual(*a, *b);
		move_back_a(a, b, n_pushed, moves);
		//vizual(*a, *b);

	}
	else
	{
		sort_by_hand(a, b, size, moves);

	}

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
	if(amount_list_el(moves) != 0)
	check_moves(moves, &temp_for_num);
	return (0);
}

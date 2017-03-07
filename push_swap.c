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

void create_numbers(char **numb, t_ab **a)
{
	int i;
	t_ab *temp;

	*a = (t_ab *)malloc(sizeof(t_ab));
	temp = *a;
	i = 1;
	while(numb[i])
	{

		temp = (t_ab *)malloc(sizeof(t_ab));
		temp->num = ft_atoi(numb[i]);
		//printf("%d", temp->num);
		temp->next = (t_ab *)malloc(sizeof(t_ab));
		i++;
		temp = temp->next;

	}
	temp->next = NULL;
	*a = temp;
}

int main(int arg, char *argv[])
{
	t_ab *a;
	t_ab *b;

	if (!is_valid(argv))
	{
		ft_putstr("Error\n");
		return (0);
	}
	create_numbers(argv, &a);
	printf("%d", a->num);



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

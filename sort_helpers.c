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
//
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
//
//			newNode = newNode->next;
//		}
//	}
//}
//
//void sort_three(t_ab **a)
//{
//	t_ab *newNode;
//
//
//}
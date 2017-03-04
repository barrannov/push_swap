#include "header.h"

void sa_sb(t_ab *strc)
{
	int t;

	if(strc != NULL && strc->next != NULL)
	{
		t = strc->next->num;
		strc->next->num = strc->num;
		strc->num = t;
	}
}

void ss(t_ab *a, t_ab *b)
{
	sa_sb(a);
	sa_sb(b);
}

int main()
{
	t_ab list2;
	list2.num = 5;
	list2.next->num = 6;

	t_ab list;
	t_ab nextlist;
	nextlist.num = 6;
	list.num = 5;
	list.next = &nextlist;

	ss(&list, &list2);
	printf("%d\n",list.num);
	printf("%d\n",list.next->num);
	printf("%d\n",list2.num);
	printf("%d\n",list2.next->num);

	return (0);
}

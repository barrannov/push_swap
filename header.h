#ifndef PUSH_SWAP_HEADER_H
#define PUSH_SWAP_HEADER_H

# include "stdlib.h"
# include "stdio.h"

typedef struct s_ab
{
	int num;
	struct s_ab *next;
}				t_ab;

void sa_sb(t_ab *strc);

#endif

NAME = checker

SECOND = push_swap

LIB = -L./libft -lft

FLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c \
	  r.c\
	  ra_rb_rr_rra_rrb_rrr.c\
	  sa_sb_ss_pa_pb.c\
	  s_helpers.c\
	  sort_a.c\
	  sort_b.c\
	  sort_by_han.c\
	  work_with_list.c\
	  work_with_list_del.c\
	  list_helpers.c\
	  valid.c \
	  helper.c \
	  check_for1.c\
      check_for2.c\
      check_for3.c \
	  back_r_rr.c

BINS = $(SRC:.c=.o)
O1 = checker.o
O2 = push_swap.o

all: $(NAME) $(SECOND)

$(NAME): $(BINS) $(O1)
	make -C libft/
	gcc $(LIB) $(FLAGS) -o $(NAME) $(O1) $(BINS)
$(SECOND): $(BINS) $(O2)
	make -C libft/
	gcc $(LIB) $(FLAGS) -o $(SECOND) $(O2) $(BINS)
%.o: %.c
	gcc -c -o $@ $< $(FLAGS)
clean:
	make -C libft/ clean
	rm -f $(BINS) $(O1) $(O2)
fclean: clean
	make -C libft/ fclean
	rm -f $(SECOND) $(NAME)
re: fclean all


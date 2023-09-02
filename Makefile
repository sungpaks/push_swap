SRCS = push_swap_main.c push_swap_deque.c push_swap_method.c\
 push_swap_sort_00.c push_swap_sort_01.c push_swap_sort_02.c\
 push_swap_utils_00.c
OBJS = $(SRCS:.c=.o)
CFLAG = -Wall -Wextra -Werror
LIBNAME = libpushswap.a
FILENAME = push_swap
INCLUDE = -I. -I./libft
LINK = -L./libft

all : $(FILENAME)

$(FILENAME) : $(OBJS)
		@make -C ./libft all
		cp libft/libft.a $(LIBNAME)
		ar rc $(LIBNAME) $^
		gcc $(CFLAG) $(INCLUDE) $(LIBNAME) -o $(FILENAME)

%.o : %.c
		gcc $(CFLAG) $(INCLUDE) -c $< -o $@

clean : 
		@make -C ./libft/ clean
		@rm -rf $(OBJS)

fclean :
		@make -C ./libft/ fclean
		@rm -rf $(OBJS) $(FILENAME) $(LIBNAME)

re : fclean all

.PHONY : all libft clean fclean re
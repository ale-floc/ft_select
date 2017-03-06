NAME = ft_select

SRC = main.c ft_list_utils.c print_arg.c signal_select.c key_select.c init_list_circ.c\
		init_all.c check_and_print.c delete_maillon.c misc.c

OBJ = $(SRC:.c=.o)

//FLAG = -Wall -Werror -Wextra -ggdb3

LIBFT = libft -lft -lncurses

INCLUDES = -I libft/includes

.PHONY : libft.a

all: libft.a  $(NAME)

libft.a:
		@$(MAKE) -C ./libft

$(NAME): $(OBJ) 
		gcc $(FLAG) $(OBJ) $(INCLUDES) -L$(LIBFT) -o $(NAME)

%.o: %.c
		gcc $(FLAG) $(INCLUDES) -c $^

clean :
		@make clean -C ./libft
			rm -f $(OBJ)

fclean : clean
		rm -f libft.a
			rm -f $(NAME)

re : fclean all

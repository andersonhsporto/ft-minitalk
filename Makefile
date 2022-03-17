NAME	= client
NAME_S	= server

CC		= gcc

CFLAGS	= -Wall #-g #-Wextra -Werror

INCLUDE =	-I ./include

HEADER	= ./include/minitalk.h

LIBFT	= -L ./libft/ -lft

SRC		=		$(addprefix ./source_client/, \
		0-client.c \
)

SRC_S	=		$(addprefix ./source_server/, \
		0-server.c \
)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

OBJ			= $(SRC:%.c=%.o)
OBJ_S		= $(SRC_S:%.c=%.o)

all: $(NAME) $(NAME_S)

$(NAME): $(HEADER) $(OBJ)
	make all -C ./libft
	rm -rf $(NAME)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)


$(NAME_S): $(HEADER) $(OBJ_S)
	make all -C ./libft
	rm -rf $(NAME_S)
	$(CC) $(CFLAGS) $(OBJ_S) $(LIBFT) -o $(NAME_S)


clean:
	make clean -C ./libft
	rm -rf $(OBJ) $(OBJ_S)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME) $(NAME_S)

re: fclean all

.PHONY: all bonus clean fclean re

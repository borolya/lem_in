CC = cc -Wall -Wextra -Werror -g
SRC = read.c \
			read_room.c \
			main.c \
			check.c \
			read_data.c \
			rb_tree.c 

INCLUDES = -I ./libft/includes \
			-I .

OBJ_LIST = $(SRC:.c=.o)
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))
LIB = libft/libft.a\

all: lemin

lemin: $(LIB) $(OBJ_DIR) $(OBJ)
	$(CC) -o lemin $(OBJ) $(INCLUDES) -L ./libft/ -lft

$(LIB):
	make -C ./libft
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o: %.c lemin.h
	$(CC) -c $< $(INCLUDES)  -o $@

clean:
	make -C libft fclean
	rm -rf $(OBJ_DIR)
fclean: clean
	make -C libft fclean
	rm -rf checker
	rm -rf push_swap
re: fclean all%
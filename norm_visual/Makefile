NAME = visual
CC = cc -Wall -Wextra -Werror -g
SRC = visual.c \
			read.c \
			read_room.c \
			initial.c \
			read_link.c \
			check.c \
			hex_image.c \
			free.c \
			draw_line.c \
			dinamic.c \
			step_init.c 
INCLUDES = -I . \
			-I ./libft/includes/ \
			-I ./minilibx_macos

OBJ_LIST = $(SRC:.c=.o)
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

LIB = ./libft/libft.a\
	./minilibx_macos/mlx.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ_DIR) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(INCLUDES) -L ./libft/ -lft -L ./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

$(LIB):
	make -C ./minilibx_macos
	make -C ./libft

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c lemin.h visu.h
	$(CC) -c $< $(INCLUDES)  -o $@

clean:
	make -C ./minilibx_macos clean
	make -C ./libft fclean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C ./minilibx_macos fclean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all

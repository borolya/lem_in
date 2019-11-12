# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 15:14:49 by crenly-b          #+#    #+#              #
#    Updated: 2019/10/08 15:28:59 by crenly-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADERS = $(addprefix -I , includes/)
FLAGS = -Wall -Wextra -Werror

LIST_LIBFT = find_ch ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii \
	ft_isdigit ft_isprint ft_itoa ft_memalloc ft_memccpy ft_memdel \
	ft_memmove ft_memset ft_putchar_fd ft_putchar ft_putendl_fd \
	ft_putendl ft_putnbr_fd ft_putnbr ft_putstr_fd ft_putstr \
	ft_strcat ft_strchr ft_strclr ft_strcmp ft_strcpy ft_strdel \
	ft_strdup ft_strequ ft_striter ft_striteri ft_strjoin \
	ft_strlcat ft_strlen ft_strmap ft_strmapi ft_strncat ft_strncmp \
	ft_strncpy ft_strnequ ft_strnew ft_strnstr ft_strrchr \
	ft_strsplit ft_strstr ft_strsub ft_strtrim ft_tolower ft_toupper \
	length_int super_check ft_memcpy ft_memchr ft_memcmp get_next_line\
	ft_str2del ft_lstadd ft_lstnew ft_lstdelone ft_lstdel ft_lstiter \
	ft_lstmap ft_intstrdel\

LIST_PRINTF = ft_atoi_printf ft_convert1016 ft_convertdigits ft_convertoctal \
	ft_convertunsi ft_dexeptions ft_dznak ft_fexepbig ft_memory \
	ft_printf ft_recconver ft_record1 ft_record2 ft_supfun1 \
	ft_supfun1f ft_supfun2 ft_supfun2f ft_supprint1d ft_supprint1f \
	ft_supprint1o ft_supprint1s ft_supprint1x ft_supprint2d \
	ft_supprint2f ft_supprint2s ft_supprint2x ft_supprint3d \
	ft_supprint3f ft_supprint4d ft_supprint4f ft_supprint5f \
	ft_supprintadr ft_supprintox ft_uexeption \


OBJ_LIBFT = $(addprefix obj/, $(addsuffix .o, $(LIST_LIBFT)))
OBJ_PRINTF = $(addprefix obj/, $(addsuffix .o, $(LIST_PRINTF)))

.PHONY: all clean fclean re obj

all: $(NAME)

obj/%.o: src/%.c
	gcc $(FLAGS) -o $@ -c $< $(HEADERS)

$(NAME): obj $(OBJ_LIBFT) $(OBJ_PRINTF)
	@ar -rc $(NAME) $(OBJ_LIBFT) $(OBJ_PRINTF)
	@echo 📖libft compiled!

obj:
	@mkdir obj  2> /dev/null || true

clean:
	@rm -rf ./obj/
	@echo 🛀 🛀 🛀

fclean: clean
	@rm -f $(NAME)

re: fclean all

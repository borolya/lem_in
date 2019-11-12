# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/25 01:00:32 by crenly-b          #+#    #+#              #
#    Updated: 2019/10/07 23:30:16 by crenly-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Wextra -Werror -g
HEADER = -I includes -I libft/includes
LIB		= -L libft/ -lft

LIST = main validation atoilemin roomsfinder validation_errors savelinks savelinks2 \
	solution work_with_memory work_with_memory2 initial sup_lem_in print_way \
	olya_suurballe olya_split olya_write olya_new_add bfs_help1 bfs_help2 bfs_help3 \
	print1 print1_sup1 surb_sup surb_dup_farm sup

OBJS = $(addprefix objs/, $(addsuffix .o, $(LIST)))

all: $(NAME)

objs/%.o: srcs/%.c includes/lemin.h
		gcc $(FLAGS) -c $< -o $@ $(HEADER)

$(NAME): objs make_lib $(OBJS) libft/libft.a 
		@gcc -o $(NAME) $(OBJS) $(LIB)
		@echo ✅lem-in compiled!

make_lib:
	@make -C libft

objs:
		@mkdir objs 2> /dev/null || true

clean:
		@make -C libft/ clean
		@rm -rf ./objs/

fclean: clean
		@make -C libft/ fclean
		@rm -f $(NAME)

re: 	fclean all

.PHONY: clean fclean re all

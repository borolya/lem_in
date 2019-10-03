/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:56:47 by bharmund          #+#    #+#             */
/*   Updated: 2019/10/03 19:56:51 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_room
{
	int			ind;
	char		*name;
	t_point		crd;
	int			start;
	int			finish;
	int			*links_array;
	int			aunts;
}				t_room;

typedef struct	s_farm
{
	int			count_aunts;
	int			*array_aunts;
	int			count_rooms;
	t_list		*room_list;
	t_room		*(*array_rooms);
	t_point		min_crd;
	t_point		max_crd;
}				t_farm;

typedef struct	s_command
{
	int			start;
	int			end;
}				t_command;

void			read_data(int fd, t_farm *farm);
int				check_comment(char *str);
int				check_link(char *str);
int				check_command(char *str);
int				check_room(char *str);
void			ft_error(char *error_name);
void			initial_farm_array_rooms(t_farm *farm);
t_room			*add_room_to_list(t_farm *farm, char *str);
void			find_link(char *str, t_farm *farm);
void			take_command(int fd, t_command *command,
									char *str, t_farm *farm);
void			take_links(int fd, t_farm *farm, t_command *command);
void			ft_lstfree(t_list **alst);
void			ft_lstcontentfree(t_list **alst);
#endif

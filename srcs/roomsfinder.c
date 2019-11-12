/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roomsfinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:46:02 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/05 15:07:46 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_new_roominitial(t_map *map)
{
	t_room *new;

	if (!(new = (t_room *)malloc(sizeof(t_room))))
		exit(-1);
	new->name = ft_strdup(map->str[0]);
	new->x = ft_atoi(map->str[1]);
	new->y = ft_atoi(map->str[2]);
	map->max_x = (new->x >= map->max_x) ? new->x : map->max_x;
	map->max_y = (new->y >= map->max_y) ? new->y : map->max_y;
	new->pos = ++map->q_rooms - map->s - map->e + 1;
	new->paint_mark = -1;
	map->new_room = new;
	new = NULL;
	ft_str2del(&map->str);
}

t_list		*ft_elem_of_rooms(t_map *map)
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		exit(-1);
	new->content = (void *)map->new_room;
	new->content_size = (size_t)(sizeof(map->new_room));
	new->next = NULL;
	map->new_room = NULL;
	return (new);
}

void		ft_check_rooms(t_map *map)
{
	t_list	*temp;
	t_room	*last_room;
	t_room	*curr_room;

	temp = map->rooms;
	map->rooms = map->rooms->next;
	last_room = (t_room *)temp->content;
	while (map->rooms != NULL)
	{
		curr_room = (t_room *)map->rooms->content;
		if ((ft_strequ(last_room->name, curr_room->name) == 1)
			|| (last_room->x == curr_room->x && last_room->y == curr_room->y))
		{
			ft_putstr_fd("Error(Names or coors of rooms).\n", 2);
			exit(-1);
		}
		else
		{
			map->rooms = map->rooms->next;
			curr_room = NULL;
		}
	}
	map->rooms = temp;
	temp = NULL;
}

void		ft_find_start_room(char **line, t_map *map)
{
	t_list *temp;

	map->str = ft_strsplit(*line, ' ');
	if (!map->str[0] || !map->str[1] || !map->str[2] || map->str[3] != NULL
		|| map->str[0][0] == 'L' || (ft_strchr(&(*map->str[0]), 45) != NULL))
		ft_lem_error("Error(start room) = \0", line);
	ft_atoicoor(&(*map->str[1]));
	ft_atoicoor(&(*map->str[2]));
	ft_new_roominitial(map);
	map->new_room->pos = 0;
	temp = ft_elem_of_rooms(map);
	ft_lstaddend(&map->rooms, temp);
	map->sf = 0;
	temp = NULL;
}

void		ft_find_curr_room(char **line, t_map *map)
{
	map->str = ft_strsplit(*line, ' ');
	if (!map->str[0] || !map->str[1] || !map->str[2] || map->str[3] != NULL
		|| map->str[0][0] == 'L' || (ft_strchr(&(*map->str[0]), 45) != NULL))
		ft_lem_error("Error(curr room) = \0", line);
	ft_atoicoor(&(*map->str[1]));
	ft_atoicoor(&(*map->str[2]));
	ft_new_roominitial(map);
	ft_lstadd(&map->rooms, ft_elem_of_rooms(map));
	ft_check_rooms(map);
}

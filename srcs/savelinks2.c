/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savelinks2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 14:01:20 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/26 23:43:38 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	ft_fiil_in_links_sup1(t_list **temp, t_map *map, t_room **curr_room,
	int *nameandlink)
{
	if (*nameandlink == 1)
	{
		map->temp_x = (*curr_room)->pos;
		map->rooms = map->rooms->next;
		*curr_room = NULL;
	}
	else if (*nameandlink == 2)
	{
		map->temp_y = (*curr_room)->pos;
		map->rooms = *temp;
		*temp = NULL;
		return (1);
	}
	return (0);
}

static void	ft_fiil_in_links_sup2(t_map *map, t_farm *farm)
{
	int i;

	i = 0;
	while (farm->arr[map->temp_x]->link[i] != -1)
		i++;
	farm->arr[map->temp_x]->link[i] = map->temp_y;
	i = 0;
	while (farm->arr[map->temp_y]->link[i] != -1)
		i++;
	farm->arr[map->temp_y]->link[i] = map->temp_x;
}

static void	ft_fiil_in_links_sup3(t_map *map, t_room **curr_room)
{
	map->rooms = map->rooms->next;
	*curr_room = NULL;
}

void		ft_fiil_in_links(t_map *map, t_farm *farm)
{
	t_list	*temp;
	t_room	*curr_room;
	int		namel;

	namel = 0;
	temp = map->rooms;
	while (map->rooms != NULL)
	{
		curr_room = (t_room *)map->rooms->content;
		if (ft_strequ(map->str[0], curr_room->name)
			|| ft_strequ(map->str[1], curr_room->name))
		{
			namel++;
			if (ft_fiil_in_links_sup1(&temp, map, &curr_room, &namel) == 1)
			{
				ft_fiil_in_links_sup2(map, farm);
				return ;
			}
		}
		else
			ft_fiil_in_links_sup3(map, &curr_room);
	}
	map->rooms = temp;
	temp = NULL;
}

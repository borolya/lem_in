/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_memory2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 13:19:02 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/07 23:17:01 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_str_of_names(t_map *map)
{
	t_list	*temp;
	t_room	*curr_room;
	int		i;

	i = map->q_rooms - 1;
	if (!(map->str = (char**)malloc(sizeof(char*) * (map->q_rooms + 1))))
		exit(-1);
	map->str[map->q_rooms] = NULL;
	temp = map->rooms;
	while (map->rooms != NULL)
	{
		curr_room = (t_room *)map->rooms->content;
		map->str[i] = ft_strdup(curr_room->name);
		map->rooms = map->rooms->next;
		i--;
	}
	map->rooms = temp;
	temp = NULL;
}

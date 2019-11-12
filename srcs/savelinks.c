/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savelinks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:21:17 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/26 23:42:17 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	ft_create_array_rooms(t_farm *farm, t_map *map)
{
	t_list	*temp;
	int		i;
	int		j;

	temp = map->rooms;
	if (!(farm->arr =
		(t_room **)malloc(sizeof(t_room *) * map->q_rooms)))
		exit(-1);
	j = map->q_rooms - 1;
	while (temp != NULL)
	{
		farm->arr[j] = (t_room *)temp->content;
		if (!(farm->arr[j]->link =
			(int *)malloc(sizeof(int) * map->q_rooms)))
			exit(-1);
		i = -1;
		while (++i < map->q_rooms)
			farm->arr[j]->link[i] = -1;
		temp = temp->next;
		j--;
	}
	temp = NULL;
}

static void	ft_savelinks_sup1(char **line, t_map *map, t_farm *farm)
{
	if (map->str[0] != NULL && map->str[1] != NULL && map->str[2] == NULL
		&& ft_strequ(map->str[0], map->str[1]) == 0)
	{
		ft_fiil_in_links(map, farm);
		ft_str2del(&map->str);
		map->temp_x = 0;
		map->temp_y = 0;
	}
	else
		ft_lem_error("Error(links) = \0", line);
}

void		ft_savelinks(char **line, t_map *map, t_farm *farm)
{
	if (map->lf == 0)
	{
		map->lf++;
		ft_create_array_rooms(farm, map);
	}
	if (*line && *line[0] != '-' && ft_strchr(*line, 45) != NULL)
	{
		map->str = ft_strsplit(*line, ' ');
		if (map->str[0] != NULL && map->str[1] == NULL)
		{
			ft_str2del(&map->str);
			map->str = ft_strsplit(*line, '-');
			ft_savelinks_sup1(line, map, farm);
		}
		else
			ft_lem_error("Error(links) = \0", line);
	}
	else
		ft_lem_error("Error(links) = \0", line);
}

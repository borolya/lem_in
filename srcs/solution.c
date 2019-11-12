/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:06:44 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/08 12:26:29 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_free_split(t_farm *split)
{
	int		i;
	t_room	*room;

	ft_intstr2del(&split->wl, 10000);
	ft_memdel((void**)&(split->bfs));
	ft_memdel((void**)&(split->line));
	i = 0;
	while (i < split->cnt * 2)
	{
		room = split->arr[i];
		ft_memdel((void**)&(room->link));
		ft_memdel((void**)&(room));
		i++;
	}
	ft_memdel((void**)&(split->arr));
}

void	ft_free_pfarm(t_farm *pfarm)
{
	int i;

	i = 0;
	while (i < pfarm->cnt)
	{
		ft_memdel((void**)&(pfarm->arr[i]->link));
		ft_memdel((void**)&(pfarm->arr[i]));
		i++;
	}
	ft_memdel((void**)&(pfarm->arr));
}

void	ft_solution(t_map *map, t_farm *farm)
{
	t_path *answer;
	t_farm split;
	t_farm pfarm;

	answer = NULL;
	ft_str_of_names(map);
	farm->cnt = map->q_rooms;
	ft_farm_initial(&split, map);
	init_split(farm, &split);
	ft_create_ways_lines(&split);
	ft_create_line(&split);
	ft_bfs(split.arr, split.cnt, &split);
	ft_dup_clear_farm(&pfarm, farm->cnt);
	if (split.bfs_flag == 0)
		ft_cant_find_way_error();
	else if (split.mpw == 1 || map->ants == 1)
		ft_print_way1(map, &split);
	else
	{
		answer = ft_suurballe(farm, &split, &pfarm, map->ants);
		ft_print_result(answer, map, farm->cgp, map->ants);
	}
	ft_free_split(&split);
	ft_free_pfarm(&pfarm);
	ft_memdel((void**)&(answer));
}

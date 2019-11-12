/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 12:43:47 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/05 21:31:36 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_mapinitial(t_map *map)
{
	map->rooms = NULL;
	map->new_room = NULL;
	map->str = NULL;
	map->q_rooms = 0;
	map->ants = 0;
	map->s = 0;
	map->e = 0;
	map->lf = 0;
	map->sf = 0;
	map->ef = 0;
	map->temp_x = 0;
	map->temp_y = 0;
	map->max_x = 0;
	map->max_y = 0;
}

void	ft_farm_initial(t_farm *farm, t_map *map)
{
	farm->cnt = map->q_rooms;
	farm->arr = NULL;
	farm->wl = NULL;
	farm->bfs = NULL;
	farm->bfs_flag = 0;
	farm->mpw = 0;
	farm->lwl = 0;
	farm->p = -1;
}

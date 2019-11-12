/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surb_sup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:24:50 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/08 12:25:51 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_fill_path(t_path *path, int *bfs, int size)
{
	int i;

	path->size = size;
	i = 0;
	while (i < path->size)
	{
		path->bfs[i] = bfs[i];
		i++;
	}
}

void	ft_clean_links(t_farm *farm)
{
	int		i;
	t_room	*room;

	i = 0;
	while (i < farm->cnt)
	{
		room = farm->arr[i];
		room->link[0] = -1;
		i++;
	}
}

void	all_split(t_path *good, int k, t_farm *split)
{
	int i;

	i = 0;
	while (i < k)
	{
		split_rev(&good[i], split);
		i++;
	}
}

void	dup_link(int *dest_link, int *src_link)
{
	int i;

	i = 0;
	while (src_link[i] != -1)
	{
		dest_link[i] = src_link[i];
		i++;
	}
	dest_link[i] = src_link[i];
}

void	back_to_origin(t_farm *farm, t_farm *orgn)
{
	int i;

	i = 0;
	while (i < orgn->cnt * 2)
	{
		if (i < orgn->cnt)
			dup_link(farm->arr[i]->link, orgn->arr[i]->link);
		else
			farm->arr[i]->link[0] = -1;
		i++;
	}
}

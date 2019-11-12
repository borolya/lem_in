/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surb_dup_farm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:23:08 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/08 12:24:21 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	init_split(t_farm *orgn, t_farm *new)
{
	int		i;
	t_room	*room;

	if (!(new->arr = malloc(sizeof(t_room*) * orgn->cnt * 2)))
		exit(-1);
	new->cnt = orgn->cnt;
	i = 0;
	while (i < orgn->cnt * 2)
	{
		if (!(new->arr[i] = ft_memalloc(sizeof(t_room))))
			exit(-1);
		room = new->arr[i];
		room->paint_mark = -1;
		if (!(room->link = malloc(sizeof(int) * orgn->cnt)))
			exit(-1);
		room->pos = i;
		if (i < orgn->cnt)
			ft_memcpy(room->link, orgn->arr[i]->link, orgn->cnt * 4);
		else
			room->link[0] = -1;
		i++;
	}
}

void	ft_dup_clear_farm(t_farm *pfarm, int cnt)
{
	int		i;
	t_room	*room;

	if (!(pfarm->arr = malloc(sizeof(t_room*) * cnt)))
		exit(-1);
	pfarm->cnt = cnt;
	i = 0;
	while (i < cnt)
	{
		if (!(pfarm->arr[i] = malloc(sizeof(t_room))))
			exit(-1);
		room = pfarm->arr[i];
		room->pos = i;
		room->paint_mark = -1;
		if (!(room->link = malloc(sizeof(int) * cnt)))
			exit(-1);
		room->link[0] = -1;
		i++;
	}
}

void	cpy_paint_mark(t_farm *split, t_farm *pfarm, int *change, int num)
{
	int i;

	i = 0;
	while (i < pfarm->cnt)
	{
		split->arr[i]->paint_mark = pfarm->arr[i]->paint_mark;
		i++;
	}
	*change = num;
}

void	ft_path_cpy(t_path *save, t_path *good, int k)
{
	int i;
	int j;

	i = 0;
	while (i < k + 1)
	{
		save[i].size = good[i].size;
		j = 0;
		while (j < save[i].size)
		{
			save[i].bfs[j] = good[i].bfs[j];
			j++;
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   olya_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:27:47 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/08 13:18:21 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	write_room(t_room *room)
{
	int i;

	if (room->link[0] == -1)
		return ;
	ft_printf("name = %s, pos = %d color = %d line ",
		room->name, room->pos, room->paint_mark);
	i = 0;
	while (room->link[i] != -1)
	{
		ft_printf("%d ", room->link[i]);
		i++;
	}
	ft_printf("%d ", room->link[i]);
	ft_printf("\n");
}

void	olya_write_dfarm(t_farm *farm)
{
	int i;

	i = 0;
	while (i < farm->cnt * 2)
	{
		write_room(farm->arr[i]);
		i++;
	}
}

void	olya_write_good(t_path *good, int cgp)
{
	int i;

	i = 0;
	while (i < cgp)
	{
		olya_write_path(good[i]);
		i++;
	}
	ft_printf("\n");
}

void	olya_write_path(t_path path)
{
	int i;

	i = 0;
	while (i < path.size)
	{
		ft_printf(" %d ", path.bfs[i]);
		i++;
	}
	ft_printf("\n");
}

void	olya_write_name_path(t_path *save, int k, t_farm *orgn)
{
	int		i;
	t_path	path;
	int		j;

	i = 0;
	while (i < k)
	{
		path = save[i];
		j = 0;
		while (j < path.size)
		{
			ft_printf(" %s ", orgn->arr[path.bfs[j]]->name);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_memory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:39:39 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/08 15:22:07 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_create_ways_lines(t_farm *farm)
{
	int i;

	if (!(farm->wl = (int **)ft_memalloc(sizeof(int *) * 10000)))
		exit(-1);
	i = -1;
	while (++i < 10000)
	{
		if (!(farm->wl[i] = (int *)ft_memalloc(sizeof(int) * 10000)))
			exit(-1);
	}
}

int			ft_fiil_in_ways_lines(t_farm *farm)
{
	int i;

	farm->wl[0][0] = 0;
	farm->wl[0][1] = -1;
	farm->mpw = 0;
	i = -1;
	while (farm->arr[0]->link[++i] != -1)
	{
		farm->wl[1][i] = farm->arr[0]->link[i];
		farm->mpw++;
	}
	farm->wl[1][i] = -1;
	if (i == 0 && farm->wl[1][0] == -1)
	{
		farm->bfs_flag = 0;
		return (1);
	}
	return (0);
}

void		ft_create_line(t_farm *farm)
{
	if (!(farm->line = (int *)malloc(sizeof(int) * 10000)))
		exit(-1);
}

static void	ft_fiil_in_line_sup1(t_farm *farm, int i)
{
	farm->bfs[0] = 0;
	farm->bfs[1] = 1;
	farm->mpw = i + 1;
	farm->bfs_flag = 1;
	farm->lwl = 2;
}

void		ft_fiil_in_line(t_farm *farm)
{
	int i;

	farm->bfs_flag = 0;
	farm->line[0] = 0;
	farm->line[1] = -1;
	if (farm->bfs == NULL)
	{
		if (!(farm->bfs = (int *)malloc(sizeof(int) * 10000)))
			exit(-1);
	}
	i = -1;
	while (farm->wl[1][++i] != -1)
	{
		if (farm->wl[1][i] == 1)
		{
			ft_fiil_in_line_sup1(farm, i);
			return ;
		}
	}
	i = -1;
	while (farm->arr[0]->link[++i] != -1)
		farm->line[i + 1] = farm->arr[0]->link[i];
	farm->line[i + 1] = -1;
}

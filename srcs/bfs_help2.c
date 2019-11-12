/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_help2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 13:52:10 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/05 15:03:26 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		ft_bfs_sup1(t_farm *farm, int *i)
{
	*i = 1;
	if (ft_fiil_in_ways_lines(farm) == 1)
		return (1);
	ft_fiil_in_line(farm);
	if (farm->bfs_flag == 1)
		return (1);
	return (0);
}

static void		ft_bfs_sup2(t_farm *farm, int *j)
{
	*j = -1;
	farm->p = -1;
}

static void		ft_bfs_sup3(t_farm *farm, int *i)
{
	farm->lwl = *i + 1;
	ft_bfs_finder(farm);
}

static int		ft_bfs_sup4(t_farm *farm, int i)
{
	if (farm->bfs_flag == 1)
	{
		ft_bfs_sup3(farm, &i);
		return (1);
	}
	return (0);
}

void			ft_bfs(t_room **ar_r, int q_rooms, t_farm *farm)
{
	int i;
	int j;
	int z;

	if (ft_bfs_sup1(farm, &i) == 1)
		return ;
	while (++i < q_rooms)
	{
		ft_bfs_sup2(farm, &j);
		while (farm->wl[i - 1][++j] != -1)
		{
			z = -1;
			while (ar_r[farm->wl[i - 1][j]]->link[++z] != -1)
			{
				if (j > farm->cnt)
					return ;
				ft_check_and_right_to_wl(farm, farm->wl[i - 1][j], i);
				if (ft_bfs_sup4(farm, i) == 1)
					return ;
			}
		}
		farm->mpw = (farm->p < farm->mpw) ? farm->p + 1 : farm->mpw;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_help3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 13:59:10 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/08 13:24:38 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_bfs_finder_sup1(t_farm *farm, int *i, int *flag)
{
	*flag = 0;
	*i = farm->lwl;
	farm->bfs[0] = 0;
	farm->bfs[*i - 1] = 1;
	farm->bfs[*i] = -1;
}

static void		ft_bfs_finder_sup2(int *j, int *flag)
{
	*j = -1;
	*flag = 0;
}

static int		ft_bfs_finder_sup3(t_farm *farm, int *i, int *j, int *flag)
{
	farm->bfs[*i - 1] = farm->arr[farm->wl[*i - 1][*j]]->pos;
	farm->wl[*i - 1][0] =
		farm->arr[farm->wl[*i - 1][*j]]->pos;
	*flag = 1;
	return (1);
}

static int		ft_bfs_finder_sup4(t_farm *farm, int *i, int *j)
{
	if (farm->wl[*i - 1][*j] == -1)
	{
		farm->bfs_flag = 0;
		return (1);
	}
	return (0);
}

void			ft_bfs_finder(t_farm *farm)
{
	int i;
	int j;
	int z;
	int flag;

	ft_bfs_finder_sup1(farm, &i, &flag);
	while (--i > 0)
	{
		ft_bfs_finder_sup2(&j, &flag);
		while (farm->wl[i - 1][++j] != -1)
		{
			z = -1;
			while (farm->arr[farm->wl[i - 1][j]]->link[++z] != -1)
			{
				if (farm->wl[i][0] == farm->arr[farm->wl[i - 1][j]]->link[z])
					if (ft_bfs_finder_sup3(farm, &i, &j, &flag) == 1)
						break ;
			}
			if (flag == 1)
				break ;
		}
		if (ft_bfs_finder_sup4(farm, &i, &j) == 1)
			return ;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_help1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 13:48:46 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/02 14:13:40 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_crwl_sup1(int *z, int *flag)
{
	*z = -1;
	*flag = 0;
}

static void		ft_crwl_sup2(t_farm *farm, int *z, int *number, int *j)
{
	farm->line[*z] = farm->arr[*number]->link[*j];
	farm->line[*z + 1] = -1;
}

static void		ft_crwl_sup3(t_farm *farm, int *pos, int *number, int *j)
{
	farm->wl[*pos][++farm->p] = farm->arr[*number]->link[*j];
	farm->wl[*pos][farm->p + 1] = -1;
}

static void		ft_crwl_sup4(t_farm *farm, int pos)
{
	farm->wl[pos][0] = 1;
	farm->wl[pos][1] = -1;
	farm->bfs_flag = 1;
}

void			ft_check_and_right_to_wl(t_farm *farm, int number, int pos)
{
	int j;
	int z;
	int flag;

	j = -1;
	while (farm->arr[number]->link[++j] != -1)
	{
		ft_crwl_sup1(&z, &flag);
		while (farm->line[++z] != -1)
			if (farm->arr[number]->link[j] == farm->line[z])
			{
				flag = 1;
				break ;
			}
		if (flag == 0)
		{
			ft_crwl_sup2(farm, &z, &number, &j);
			ft_crwl_sup3(farm, &pos, &number, &j);
			if (farm->wl[pos][farm->p] == 1)
			{
				ft_crwl_sup4(farm, pos);
				return ;
			}
		}
	}
}

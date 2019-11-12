/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:15:58 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/05 15:02:21 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	ft_oppr_sup1(t_path *ans, t_map *map, int i, int j)
{
	ft_printf("L%d-%s ", ans[i].p[j], map->str[ans[i].bfs[j + 1]]);
	ans[i].p[j] = 0;
	ans[i].p[j + 1]++;
}

static void	ft_oppr_sup2(t_path *ans, t_map *map, int i, int j)
{
	ft_printf("L%d-%s ", ans[i].p[j], map->str[ans[i].bfs[j + 1]]);
	ans[i].p[j + 1] = ans[i].p[j];
	ans[i].p[j] = 0;
}

static void	ft_oppr_sup3(t_path *ans, t_map *map, int i, int j)
{
	ft_printf("L%d-%s ", ans[i].p[j], map->str[ans[i].bfs[j + 1]]);
	ans[i].p[j + 1] = ans[i].p[j];
	ans[i].p[j] = 0;
}

static int	ft_oppr_sup(t_path *ans, t_map *map, int i, int j)
{
	if (j == ans[i].size - 2 && ans[i].p[j] != 0 && j != 0)
	{
		ft_oppr_sup1(ans, map, i, j);
		return (1);
	}
	else if (j == ans[i].size - 2 && j == 0 && ans[i].p[j] != 0)
	{
		ft_oppr_sup2(ans, map, i, j);
		return (1);
	}
	else if (j != 0 && ans[i].p[j + 1] == 0 && ans[i].p[j] != 0)
	{
		ft_oppr_sup3(ans, map, i, j);
		return (1);
	}
	return (0);
}

void		ft_one_path_print(t_path *ans, t_map *map, int i, int nant)
{
	int j;

	j = ans[i].size - 2;
	if (ans[i].p[j + 1] != ans[i].a_h)
	{
		while (j >= 0)
		{
			if (ft_oppr_sup(ans, map, i, j) == 1)
			{
			}
			else if (j == 0 && ans[i].p[j + 1] == 0 && ans[i].p[j] != 0)
			{
				ft_printf("L%d-%s ", nant, map->str[ans[i].bfs[j + 1]]);
				ans[i].p[j + 1] = nant;
				ans[i].p[j]--;
			}
			j--;
		}
	}
	if (ans[i].p[ans[i].size - 1] == ans[i].a_h)
	{
		map->e++;
		ft_intstrdel(&ans[i].p);
		return ;
	}
}

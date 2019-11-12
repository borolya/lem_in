/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print1_sup1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 13:30:20 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/05 15:06:34 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	fill_in_path(t_path *ans, int i, int *mod, int ariw)
{
	int j;

	j = 0;
	if (*mod != 0)
	{
		ans[i].a_h = ariw + 1 - ans[i].size;
		(*mod)--;
	}
	else
		ans[i].a_h = ariw - ans[i].size;
	if (!(ans[i].p = (int *)malloc(sizeof(int) * ans[i].size)))
		exit(-1);
	while (j < ans[i].size)
		ans[i].p[j++] = 0;
	ans[i].p[0] = ans[i].a_h;
}

void		ft_preparations_for_print(t_path *ans, int cgp, int ants)
{
	int i;
	int ariw;
	int mod;

	i = -1;
	ariw = 0;
	(void)ants;
	while (++i < cgp)
		ariw += ans[i].size;
	mod = (ariw + ants) % cgp;
	ariw = (ariw + ants) / cgp;
	i = -1;
	while (++i < cgp)
		fill_in_path(ans, i, &mod, ariw);
}

void		ft_print_result(t_path *ans, t_map *map, int cgp, int ants)
{
	int i;
	int nant;

	nant = 0;
	map->e = 0;
	ft_preparations_for_print(ans, cgp, ants);
	while (1)
	{
		i = -1;
		while (++i < cgp)
		{
			if (ans[i].p != NULL)
			{
				if (ans[i].p[0] != 0)
					nant++;
				ft_one_path_print(ans, map, i, nant);
			}
		}
		if (map->e == cgp)
			return ;
		ft_printf("\n");
	}
}

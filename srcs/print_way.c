/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:34:03 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/03 12:32:04 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_pws_sup1(t_map *map, int *z, int *j)
{
	*j = -1;
	*z = 0;
	map->ef = 0;
}

static void		ft_pws_sup2(t_map *map, t_farm *farm, int *z, int *num_ant)
{
	while (*z > 0 && *num_ant < map->ants)
	{
		ft_printf("L%d-%s ", *num_ant, map->str[farm->bfs[*z + 1]]);
		(*z)--;
		(*num_ant)++;
	}
	ft_printf("L%d-%s\n", *num_ant, map->str[farm->bfs[*z + 1]]);
}

void			ft_print_way1(t_map *map, t_farm *farm)
{
	int i;
	int j;
	int z;
	int num_ant;

	i = map->ants + (farm->lwl - 1) - 1;
	ft_pws_sup1(map, &z, &j);
	while (i-- > 0)
	{
		z = ++j;
		if (z < farm->lwl - 1)
			num_ant = 1;
		else
		{
			z = --j;
			num_ant = ++map->ef + 1;
		}
		ft_pws_sup2(map, farm, &z, &num_ant);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   olya_suurballe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:37:37 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/08 12:39:24 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		worse(t_path *old, t_path *new, int k, int aunts)
{
	int old_sum;
	int new_sum;
	int i;

	i = -1;
	old_sum = 0;
	new_sum = 0;
	while (++i < k)
	{
		old_sum += old[i].size;
		new_sum += new[i].size;
	}
	new_sum += new[i].size;
	old_sum += aunts;
	new_sum += aunts;
	old_sum = old_sum % k > 0 ? (old_sum / k + 1) : old_sum / k;
	k++;
	new_sum = new_sum % k > 0 ? (new_sum / k + 1) : new_sum / k;
	i = 0;
	while (++i < k)
	{
		if (new_sum <= new[i].size)
			return (1);
	}
	return (old_sum < new_sum);
}

int		init_suurv(t_path **good, t_path **save, t_farm *pfarm, t_farm *split)
{
	int		max;
	t_path	path;

	max = split->mpw;
	if (!(*good = ft_memalloc(sizeof(t_path) * max)))
		exit(-1);
	if (!(*save = ft_memalloc(sizeof(t_path) * max)))
		exit(-1);
	ft_fill_path(&path, split->bfs, split->lwl);
	*good[0] = path;
	add_path(*good, pfarm, 0, split);
	ft_path_cpy(*save, *good, 0);
	return (max);
}

t_path	*ft_ret(t_path *fr, t_path *rtn)
{
	free(fr);
	return (rtn);
}

t_path	*ft_suurballe(t_farm *orgn, t_farm *split, t_farm *pfarm, int aunts)
{
	t_path	*good;
	t_path	path;
	t_path	*save;
	int		max_p;
	int		i;

	max_p = init_suurv(&good, &save, pfarm, split);
	i = 1;
	while (i < max_p && i < aunts)
	{
		cpy_paint_mark(split, pfarm, &(orgn->cgp), i);
		all_split(good, i, split);
		ft_bfs(split->arr, split->cnt, split);
		if (split->bfs_flag == 0)
			return (ft_ret(good, save));
		ft_fill_path(&path, split->bfs, split->lwl);
		good[i] = path;
		add_path(good, pfarm, i, split);
		if (worse(save, good, i, aunts))
			return (ft_ret(good, save));
		ft_path_cpy(save, good, i++);
		back_to_origin(split, orgn);
	}
	orgn->cgp = i;
	return (ft_ret(save, good));
}

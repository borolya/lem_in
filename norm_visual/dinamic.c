/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_dinamic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:47:17 by bharmund          #+#    #+#             */
/*   Updated: 2019/10/03 19:47:18 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void		draw_aunt(t_link *link, t_visu *visu)
{
	mlx_put_image_to_window(visu->mlx_ptr, visu->win_ptr, visu->aunt.ptr,
						link->p.x - SQ_SIZE / 2, link->p.y - SQ_SIZE / 2);
	link->p.x += link->delta.x;
	link->p.y += link->delta.y;
}

void		draw_hex(t_visu *visu)
{
	int		i;
	t_room	*room;
	char	*str;

	mlx_put_image_to_window(visu->mlx_ptr, visu->win_ptr, visu->hex.ptr, 0, 0);
	i = 0;
	while (i < visu->farm->count_rooms)
	{
		room = visu->farm->array_rooms[i];
		str = ft_itoa(room->aunts);
		mlx_string_put(visu->mlx_ptr, visu->win_ptr, room->crd.x - SQ_SIZE / 2,
					room->crd.y + SQ_SIZE, 100000, str);
		free(str);
		i++;
	}
}

static void	move_aunts(t_visu *visu)
{
	t_link	*content;
	t_list	*link;

	if (visu->step < 0)
	{
		link = visu->links;
		while (link != NULL)
		{
			content = link->content;
			content->room1->aunts--;
			content->room2->aunts++;
			visu->farm->array_aunts[content->numb] = content->room2->ind;
			link = link->next;
		}
		ft_lstcontentfree(&(visu->links));
		visu->links = NULL;
	}
}

int			dinamic(t_visu *visu)
{
	t_list	*link;

	mlx_clear_window(visu->mlx_ptr, visu->win_ptr);
	draw_hex(visu);
	if (visu->step >= 0)
	{
		link = visu->links;
		mlx_clear_window(visu->mlx_ptr, visu->win_ptr);
		draw_hex(visu);
		while (link != NULL)
		{
			draw_aunt(link->content, visu);
			link = link->next;
		}
		visu->step--;
		move_aunts(visu);
	}
	return (0);
}

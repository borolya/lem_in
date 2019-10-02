/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_draw_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 21:31:00 by bharmund          #+#    #+#             */
/*   Updated: 2019/10/02 21:31:01 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "lemin.h"

void	init_point(t_point *delta, t_point *sign_d, t_point p1, t_point p2)
{
	delta->x = abs(p2.x - p1.x);
	delta->y = abs(p2.y - p1.y);
	sign_d->x = p1.x < p2.x ? 1 : -1;
	sign_d->y = p1.y < p2.y ? 1 : -1;
}

void	draw_line(t_point p1, t_point p2, int *img_data)
{
	t_point delta;
	t_point error;
	t_point sign_d;

	init_point(&delta, &sign_d, p1, p2);
	error.x = delta.x - delta.y;
	if (p2.y >= 0 && p2.y < HEX_H && p2.x >= 0 && p2.x < HEX_W)
		img_data[p2.y * HEX_H + p2.x] = 100000;
	while (p1.x != p2.x || p1.y != p2.y)
	{
		if (p1.y >= 0 && p1.y < HEX_H && p1.x >= 0 && p1.x < HEX_W)
			img_data[p1.y * HEX_H + p1.x] = 100000;
		if ((error.y = error.x * 2) > -delta.y)
		{
			error.x -= delta.y;
			p1.x += sign_d.x;
		}
		if (error.y < delta.x)
		{
			error.x += delta.x;
			p1.y += sign_d.y;
		}
	}
}

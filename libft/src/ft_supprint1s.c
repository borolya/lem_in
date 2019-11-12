/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supprint1s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:43:32 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/13 16:25:45 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sprint3(t_ran *ran, t_spec *s)
{
	if (s->acc == -1 || s->acc == -1)
		return ;
	if (s->strl <= s->acc || s->acc == -1 || s->acc == -1)
		while (s->buf[s->j])
			ran->buf[ran->j++] = s->buf[s->j++];
	else
	{
		while (s->acc)
		{
			ran->buf[ran->j++] = s->buf[s->j++];
			s->acc--;
		}
	}
}

void	ft_sprint2_1(t_ran *ran, t_spec *s)
{
	while (s->buf[s->j])
		ran->buf[ran->j++] = s->buf[s->j++];
}

void	ft_sprint2(t_ran *ran, t_spec *s)
{
	if (s->width <= s->strl)
		ft_sprint2_1(ran, s);
	else
	{
		if (s->minus == 1)
		{
			ft_sprint2_1(ran, s);
			while (s->strl < s->width)
			{
				ran->buf[ran->j++] = ' ';
				s->strl++;
			}
		}
		else
		{
			while (s->strl < s->width)
			{
				ran->buf[ran->j++] = ' ';
				s->strl++;
			}
			ft_sprint2_1(ran, s);
		}
	}
}

void	ft_sprint1(t_ran *ran, t_spec *s)
{
	while (s->buf[s->j])
		ran->buf[ran->j++] = s->buf[s->j++];
}

void	ft_bufjoin_s(t_ran *ran, t_spec *s)
{
	s->i = 0;
	if (s->width == 0 && s->acc == 0)
		ft_sprint1(ran, s);
	if (s->width != 0 && s->acc == 0)
		ft_sprint2(ran, s);
	if (s->width == 0 && s->acc != 0)
		ft_sprint3(ran, s);
	if (s->width != 0 && s->acc != 0)
		ft_sprint4(ran, s);
}

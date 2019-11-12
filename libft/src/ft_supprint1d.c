/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supprint1d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 16:25:05 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/13 19:23:19 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dprint4(t_ran *ran, t_spec *s)
{
	if (ft_o_checkzero4(ran, s) == 1)
		return ;
	if (s->acc == -1 && s->z == 1)
		ft_dp4_1(ran, s);
	else if (s->minus == 0)
	{
		if (s->width <= s->acc)
			ft_dp4_2(ran, s);
		else
			ft_dp4_3(ran, s);
	}
	else
	{
		if (s->width <= s->acc)
			ft_dp4_4(ran, s);
		else
			ft_dp4_5(ran, s);
	}
}

void	ft_dprint3(t_ran *ran, t_spec *s)
{
	if (ft_o_checkzero3(ran, s) == 1)
		return ;
	if (s->acc == -1 && s->z == 1)
	{
		if (s->plus)
			ran->buf[ran->j++] = '+';
		return ;
	}
	if (s->acc <= s->strl)
	{
		if (ran->conver == 'o' && s->grid == 1)
			ran->buf[ran->j++] = '0';
		if (s->space && s->pmz != -1 && s->plus != 1)
			ran->buf[ran->j++] = ' ';
		while (s->buf[s->j])
			ran->buf[ran->j++] = s->buf[s->j++];
	}
	else
	{
		ft_dznak1(ran, s);
		while (s->acc-- > s->strl)
			ran->buf[ran->j++] = '0';
		while (s->buf[s->j])
			ran->buf[ran->j++] = s->buf[s->j++];
	}
}

void	ft_dprint2(t_ran *ran, t_spec *s)
{
	if (s->z == 1)
	{
		ft_dp2_1(ran, s);
		return ;
	}
	if (s->minus == 0)
		ft_dp2_2(ran, s);
	else
		ft_dp2_3(ran, s);
}

void	ft_dprint1(t_ran *ran, t_spec *s)
{
	if (s->space == 1 && s->minus == 0 && s->plus == 0 && s->zero == 0
		&& s->grid == 0 && s->pmz != -1)
		ran->buf[ran->j++] = ' ';
	else if (s->grid == 1 && ran->conver == 'o' && s->buf[s->j] != '0')
		ran->buf[ran->j++] = '0';
	while (s->buf[s->j])
		ran->buf[ran->j++] = s->buf[s->j++];
}

void	ft_bufjoin_d(t_ran *ran, t_spec *s)
{
	s->i = 0;
	s->j = 0;
	s->strl = ft_strlen(s->buf);
	if (s->width == 0 && s->acc == 0)
		ft_dprint1(ran, s);
	else if (s->width != 0 && s->acc == 0)
		ft_dprint2(ran, s);
	else if (s->width == 0 && s->acc != 0)
		ft_dprint3(ran, s);
	else if (s->width != 0 && s->acc != 0)
		ft_dprint4(ran, s);
}

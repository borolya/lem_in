/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supprint2x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 00:41:22 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/07 16:34:34 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print4(t_ran *ran, t_spec *s)
{
	ft_print4_1(ran, s);
	ft_print4_2(ran, s);
	if (s->minus == 1 && s->buf[0] != '0')
	{
		if (s->width >= s->acc)
			ft_print4_3(ran, s);
		else
			ft_print4_4(ran, s);
	}
	if (s->i > 0)
		return ;
	if (s->width >= s->acc)
		ft_print4_5(ran, s);
	else
		ft_print4_6(ran, s);
}

void	ft_print3(t_ran *ran, t_spec *s)
{
	if (s->acc == -1)
		return ;
	if (s->grid == 1 && s->buf[0] != '0')
	{
		ft_checkgrid(ran, s);
		s->i += 2;
		while (s->i < s->acc - ft_strlen(s->buf) + 2)
		{
			ran->buf[ran->j++] = '0';
			s->i++;
		}
		ft_strjcpy(ran->buf, s, &ran->j);
		return ;
	}
	if (ran->conver == 'd' && s->pmz == 1)
		ran->buf[ran->j++] = '-';
	if (ran->conver == 'd' && s->plus == 1 && s->pmz != 1)
		ran->buf[ran->j++] = '+';
	while (s->i < s->acc - ft_strlen(s->buf))
	{
		ran->buf[ran->j++] = '0';
		s->i++;
	}
	ft_strjcpy(ran->buf, s, &ran->j);
}

void	ft_print2(t_ran *ran, t_spec *s)
{
	if (s->zero == 0)
	{
		ft_print2_1(ran, s);
		return ;
	}
	else
	{
		if (s->minus == 0)
		{
			ft_checkgridplus2(ran, s);
			while (s->i++ < s->width && s->minus == 0)
				ran->buf[ran->j++] = '0';
			ft_strjcpy(ran->buf, s, &ran->j);
			return ;
		}
		ft_checkgridplus2(ran, s);
		ft_strjcpy(ran->buf, s, &ran->j);
		while (s->i < s->width)
		{
			ran->buf[ran->j++] = ' ';
			s->i++;
		}
	}
}

void	ft_print1(t_ran *ran, t_spec *s)
{
	if (ran->conver == 'd')
	{
		if (s->pmz == 1)
			ran->buf[ran->j++] = '-';
		if (s->plus == 1 && s->pmz != 1)
			ran->buf[ran->j++] = '+';
	}
	ft_checkgrid(ran, s);
	ft_strjcpy(ran->buf, s, &ran->j);
}

void	ft_bufjoin_x(t_ran *ran, t_spec *s)
{
	s->i = 0;
	if (s->width == 0 && s->acc == 0)
		ft_print1(ran, s);
	if (s->width != 0 && s->acc == 0)
		ft_print2(ran, s);
	if (s->width == 0 && s->acc != 0)
		ft_print3(ran, s);
	if (s->width != 0 && s->acc != 0)
		ft_print4(ran, s);
}

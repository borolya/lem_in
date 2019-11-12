/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supprint1o.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 15:22:48 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/02 12:39:38 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_o_checkwa1(t_ran *ran, t_spec *s)
{
	if (ran->conver == 'o')
	{
		if (s->grid == 1 && s->width == 0)
		{
			ran->buf[ran->j++] = '0';
			s->width--;
		}
		while (s->buf[s->j])
			ran->buf[ran->j++] = s->buf[s->j++];
		if (s->width > s->strl)
		{
			while (s->width-- - s->strl)
				ran->buf[ran->j++] = ' ';
		}
		return (1);
	}
	return (0);
}

int		ft_o_checkzero4(t_ran *ran, t_spec *s)
{
	if (ran->conver == 'o' && s->grid == 1 && s->acc == -1)
	{
		if (s->minus == 1)
		{
			ran->buf[ran->j++] = '0';
			while (s->width-- - s->strl)
				ran->buf[ran->j++] = ' ';
			return (1);
		}
		else
		{
			if (s->zero == 1)
			{
				while (s->width--)
					ran->buf[ran->j++] = '0';
				return (1);
			}
			while (s->width-- - 1)
				ran->buf[ran->j++] = ' ';
			ran->buf[ran->j++] = '0';
			return (1);
		}
	}
	return (0);
}

int		ft_o_checkzero3(t_ran *ran, t_spec *s)
{
	if (ran->conver == 'o' && s->grid == 1)
	{
		while (s->acc-- > ft_strlen(s->buf))
			ran->buf[ran->j++] = '0';
		while (s->buf[s->j])
			ran->buf[ran->j++] = s->buf[s->j++];
		return (1);
	}
	return (0);
}

int		ft_o_checkzero2(t_ran *ran, t_spec *s)
{
	if (ran->conver == 'o')
	{
		if (s->minus == 1)
		{
			if (s->grid == 1)
			{
				ran->buf[ran->j++] = '0';
				while (s->width-- - 1)
					ran->buf[ran->j++] = ' ';
				return (1);
			}
			while (s->buf[s->j])
				ran->buf[ran->j++] = s->buf[s->j++];
			while (s->width-- - s->strl)
				ran->buf[ran->j++] = ' ';
			return (1);
		}
		else
		{
			ft_o_checkzerohelp2(ran, s);
			return (1);
		}
	}
	return (0);
}

int		ft_oexeption2(t_ran *ran, t_spec *s, unsigned long long int *num)
{
	if (*num == 0)
	{
		s->z = 1;
		if (s->plus == 1)
		{
			s->buf[0] = '+';
			s->buf[1] = 48;
		}
		else
			s->buf[0] = 48;
		ft_bufjoin_d(ran, s);
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supprint2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 16:00:01 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/14 16:09:03 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dp2_1(t_ran *ran, t_spec *s)
{
	if (ft_o_checkzero2(ran, s) == 1)
		return ;
	if (s->allflagzero || (s->space && !s->minus && !s->plus && !s->zero))
	{
		while (s->width-- - 1)
			ran->buf[ran->j++] = ' ';
		ran->buf[ran->j++] = '0';
	}
	else if ((s->minus || s->space) && !s->zero && !s->plus)
	{
		if (s->space)
			ran->buf[ran->j++] = ' ';
		ran->buf[ran->j++] = '0';
		while (s->i++ < s->width - s->minus - s->space)
			ran->buf[ran->j++] = ' ';
	}
	else if (s->plus && !s->zero)
	{
		while (s->width-- - 2)
			ran->buf[ran->j++] = ' ';
		ran->buf[ran->j++] = '+';
		ran->buf[ran->j++] = '0';
	}
	else if (s->plus || s->space || s->zero)
		ft_dp2_11(ran, s);
}

void	ft_dp2_11(t_ran *ran, t_spec *s)
{
	if (s->plus || s->space)
	{
		if (s->plus)
			ran->buf[ran->j++] = '+';
		else
			ran->buf[ran->j++] = ' ';
		while (s->width-- - 1)
			ran->buf[ran->j++] = '0';
	}
	else
	{
		if (s->zero == 1 && s->minus == 1)
		{
			ran->buf[ran->j++] = '0';
			while (s->width-- - 1)
				ran->buf[ran->j++] = ' ';
		}
		else
			while (s->width--)
				ran->buf[ran->j++] = '0';
	}
}

void	ft_dp2_2(t_ran *ran, t_spec *s)
{
	if (s->width <= s->strl)
	{
		if (s->space && s->pmz != -1)
			ran->buf[ran->j++] = ' ';
		else if (s->grid == 1 && ran->conver == 'o'
			&& s->width > ft_strlen(s->buf))
			ran->buf[ran->j++] = '0';
		while (s->strl--)
			ran->buf[ran->j++] = s->buf[s->j++];
	}
	else if (s->zero == 0)
	{
		if (ft_odp2_2check(ran, s) == 1)
			return ;
		while (s->i < s->width - s->strl)
		{
			ran->buf[ran->j++] = ' ';
			s->i++;
		}
		while (s->i++ < s->width)
			ran->buf[ran->j++] = s->buf[s->j++];
	}
	else
		ft_dp2_21(ran, s);
}

void	ft_dp2_21(t_ran *ran, t_spec *s)
{
	if (s->pmz == -1 || s->pmz == 1)
	{
		ran->buf[ran->j++] = s->buf[0];
		s->j++;
		s->i++;
		s->strl--;
	}
	else if (s->space == 1)
	{
		ran->buf[ran->j++] = ' ';
		s->i++;
	}
	while (s->i < s->width - s->strl)
	{
		ran->buf[ran->j++] = '0';
		s->i++;
	}
	while (s->i++ < s->width)
		ran->buf[ran->j++] = s->buf[s->j++];
}

void	ft_dp2_3(t_ran *ran, t_spec *s)
{
	if (ft_o_checkwa1(ran, s) == 1)
		return ;
	if (s->width <= s->strl)
	{
		if (s->space && s->pmz != -1)
			ran->buf[ran->j++] = ' ';
		while (s->strl--)
			ran->buf[ran->j++] = s->buf[s->j++];
	}
	else
	{
		if (s->space && s->pmz != -1)
		{
			ran->buf[ran->j++] = ' ';
			s->width--;
		}
		while (s->j < s->strl)
			ran->buf[ran->j++] = s->buf[s->j++];
		while (s->j < s->width)
		{
			ran->buf[ran->j++] = ' ';
			s->j++;
		}
	}
}

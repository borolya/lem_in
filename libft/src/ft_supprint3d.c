/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supprint3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 16:14:15 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/14 16:14:29 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dp4_1(t_ran *ran, t_spec *s)
{
	if (s->plus && s->minus)
	{
		ran->buf[ran->j++] = '+';
		s->width--;
	}
	else if (s->plus)
		s->width--;
	while (s->width--)
		ran->buf[ran->j++] = ' ';
	if (s->plus && !s->minus)
		ran->buf[ran->j++] = '+';
}

void	ft_dp4_2(t_ran *ran, t_spec *s)
{
	ft_dznak1(ran, s);
	if (s->acc <= s->strl)
	{
		if (s->grid == 1 && ran->conver == 'o' && s->width > s->strl + s->acc)
			ran->buf[ran->j++] = '0';
		while (s->i < s->strl)
		{
			ran->buf[ran->j++] = s->buf[s->j++];
			s->i++;
		}
	}
	else
	{
		while (s->i < s->acc - s->strl)
		{
			ran->buf[ran->j++] = '0';
			s->i++;
		}
		while (s->i++ < s->acc)
			ran->buf[ran->j++] = s->buf[s->j++];
	}
}

void	ft_dp4_3(t_ran *ran, t_spec *s)
{
	if (s->strl <= s->acc)
	{
		ft_dznak2(s);
		while (s->i < s->width - s->acc)
		{
			ran->buf[ran->j++] = ' ';
			s->i++;
		}
		ft_dznak3(ran, s);
		while (s->acc - s->strl++)
		{
			ran->buf[ran->j++] = '0';
			s->i++;
		}
		while (s->i++ < s->width)
			ran->buf[ran->j++] = s->buf[s->j++];
	}
	else
		ft_dphelp4_3(ran, s);
}

void	ft_dp4_4(t_ran *ran, t_spec *s)
{
	ft_dznak5(ran, s);
	if (s->acc <= s->strl)
	{
		if (s->grid == 1 && ran->conver == 'o' && s->width > s->acc + s->strl)
			ran->buf[ran->j++] = '0';
		while (s->i++ < s->strl)
			ran->buf[ran->j++] = s->buf[s->j++];
	}
	else
	{
		while (s->acc > s->strl++)
		{
			ran->buf[ran->j++] = '0';
			s->i++;
		}
		while (s->i++ < s->acc)
			ran->buf[ran->j++] = s->buf[s->j++];
	}
}

void	ft_dp4_5(t_ran *ran, t_spec *s)
{
	ft_dznak4(ran, s);
	if (s->acc <= s->strl)
	{
		if (s->grid == 1 && ran->conver == 'o' && s->width > s->strl + s->acc)
		{
			ran->buf[ran->j++] = '0';
			s->width--;
		}
		while (s->strl--)
		{
			ran->buf[ran->j++] = s->buf[s->j++];
			s->i++;
		}
		while (s->i++ < s->width)
			ran->buf[ran->j++] = ' ';
		return ;
	}
	ft_dphelp4_5(ran, s);
}

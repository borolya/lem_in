/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supprint5f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 13:09:29 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/14 13:09:30 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fp4_5(t_ran *ran, t_spec *s)
{
	if (s->pmz == -1)
	{
		ran->buf[ran->j++] = '-';
		s->width--;
	}
	else if (s->plus == 1)
	{
		ran->buf[ran->j++] = '+';
		s->width--;
	}
	else if (s->space == 1)
	{
		ran->buf[ran->j++] = ' ';
		s->width--;
	}
	ft_strjcpy6(ran->buf, s, &ran->j, s->acc);
	while (s->width > s->strl_b + s->acc)
	{
		ran->buf[ran->j++] = ' ';
		s->width--;
	}
}

void	ft_fp4_4(t_ran *ran, t_spec *s)
{
	if (s->pmz == -1)
	{
		ran->buf[ran->j++] = '-';
		s->width--;
	}
	else if (s->plus == 1)
	{
		ran->buf[ran->j++] = '+';
		s->width--;
	}
	else if (s->space == 1)
	{
		ran->buf[ran->j++] = ' ';
		s->width--;
	}
	ft_strjcpy6(ran->buf, s, &ran->j, s->acc);
}

void	ft_fp4_32(t_ran *ran, t_spec *s)
{
	if (s->pmz == -1)
	{
		ran->buf[ran->j++] = '-';
		s->width--;
	}
	else if (s->plus == 1)
	{
		ran->buf[ran->j++] = '+';
		s->width--;
	}
	else if (s->space == 1)
	{
		ran->buf[ran->j++] = ' ';
		s->width--;
	}
	while (s->width > s->strl_b + s->acc)
	{
		ran->buf[ran->j++] = '0';
		s->width--;
	}
	ft_strjcpy6(ran->buf, s, &ran->j, s->acc);
}

void	ft_fp4_3(t_ran *ran, t_spec *s)
{
	if (s->zero == 0)
	{
		while (s->width - 1 > s->strl_b + s->acc)
		{
			ran->buf[ran->j++] = ' ';
			s->width--;
		}
		if (s->pmz == -1)
		{
			ran->buf[ran->j++] = '-';
			s->width--;
		}
		else if (s->plus == 1)
		{
			ran->buf[ran->j++] = '+';
			s->width--;
		}
		else
			ran->buf[ran->j++] = ' ';
		ft_strjcpy6(ran->buf, s, &ran->j, s->acc);
	}
	else
		ft_fp4_32(ran, s);
}

void	ft_fp4_2(t_ran *ran, t_spec *s)
{
	if (s->pmz == -1)
		ran->buf[ran->j++] = '-';
	else if (s->plus == 1)
		ran->buf[ran->j++] = '+';
	else if (s->space == 1)
		ran->buf[ran->j++] = ' ';
	ft_strjcpy6(ran->buf, s, &ran->j, s->acc);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supprint4f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:30:49 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/09 13:46:34 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fp1234minus_plus_space(t_ran *ran, t_spec *s)
{
	if (s->pmz == -1)
		ran->buf[ran->j++] = '-';
	else if (s->plus == 1)
		ran->buf[ran->j++] = '+';
	else if (s->space == 1)
		ran->buf[ran->j++] = ' ';
	else if (s->acc == -1 && s->minus == 0 && s->width != 0)
		s->width++;
}

void	ft_fp4_1(t_ran *ran, t_spec *s)
{
	if (s->pmz == -1 || s->plus == 1)
		s->strl_b++;
	while (s->width > s->strl_b - 1)
	{
		ran->buf[ran->j++] = ' ';
		s->width--;
	}
	if (s->pmz == -1)
	{
		ran->buf[ran->j++] = '-';
		s->strl_b--;
	}
	else if (s->plus == 1)
	{
		ran->buf[ran->j++] = '+';
		s->strl_b--;
	}
	while (s->strl_b - 1)
	{
		ran->buf[ran->j++] = s->buf[s->j++];
		s->strl_b--;
	}
}

void	ft_fp4zero(t_ran *ran, t_spec *s)
{
	if (s->zero == 1)
	{
		ft_fp1234minus_plus_space(ran, s);
		while (s->width > s->strl_b)
		{
			ran->buf[ran->j++] = '0';
			s->width--;
		}
		while (s->strl_b - 1)
		{
			ran->buf[ran->j++] = s->buf[s->j++];
			s->strl_b--;
		}
	}
	else
		ft_fp4_1(ran, s);
}

void	ft_fp4accminus2(t_ran *ran, t_spec *s)
{
	ft_fp1234minus_plus_space(ran, s);
	if (s->pmz == -1 || s->plus == 1 || s->space == 1)
		s->width--;
	while (s->strl_b - 1)
	{
		ran->buf[ran->j++] = s->buf[s->j++];
		s->strl_b--;
	}
	if (s->grid == 1)
	{
		ran->buf[ran->j++] = '.';
		s->width--;
	}
	while (s->width-- > s->strl_b)
		ran->buf[ran->j++] = ' ';
}

int		ft_fp4accminus(t_ran *ran, t_spec *s)
{
	if (s->acc == -1)
	{
		if (s->minus == 0)
			ft_fp4zero(ran, s);
		else
			ft_fp4accminus2(ran, s);
		return (1);
	}
	return (0);
}

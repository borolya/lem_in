/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supprint1x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 00:05:26 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/07 16:34:39 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print4_2(t_ran *ran, t_spec *s)
{
	if (s->allflagzero == 1 && s->acc != -1 && s->i == 0)
	{
		if (s->width >= s->acc)
		{
			while (s->i < s->width - ft_biggeraccornum(s))
			{
				ran->buf[ran->j++] = ' ';
				s->i++;
			}
			while (s->i++ < s->width - ft_strlen(s->buf) && s->buf[0] != '0')
				ran->buf[ran->j++] = '0';
			ft_strjcpy(ran->buf, s, &ran->j);
			return ;
		}
		else
		{
			while ((s->i++ < s->acc - ft_strlen(s->buf)) && s->buf[0] != '0')
				ran->buf[ran->j++] = '0';
			ft_strjcpy(ran->buf, s, &ran->j);
			return ;
		}
	}
}

void	ft_print4_3(t_ran *ran, t_spec *s)
{
	if (s->grid == 1)
	{
		ft_print4grid(ran, s);
		return ;
	}
	if (s->acc < ft_strlen(s->buf))
	{
		ft_strjcpy(ran->buf, s, &ran->j);
		s->i += ft_strlen(s->buf);
		while (s->i++ < s->width)
			ran->buf[ran->j++] = ' ';
		return ;
	}
	while (s->acc-- - ft_strlen(s->buf))
	{
		ran->buf[ran->j++] = '0';
		s->i++;
	}
	ft_strjcpy(ran->buf, s, &ran->j);
	s->i += ft_strlen(s->buf);
	while (s->i++ < s->width)
		ran->buf[ran->j++] = ' ';
	return ;
}

void	ft_print4_4(t_ran *ran, t_spec *s)
{
	if (s->i == 0)
	{
		if (s->grid == 1)
		{
			ft_print4grid(ran, s);
			return ;
		}
		if (s->acc >= ft_strlen(s->buf))
		{
			while (s->i < s->acc - ft_strlen(s->buf))
			{
				ran->buf[ran->j++] = '0';
				s->i++;
			}
		}
		ft_strjcpy(ran->buf, s, &ran->j);
		s->i += ft_strlen(s->buf);
		while (s->i++ < s->acc - ft_strlen(s->buf))
			ran->buf[ran->j++] = '0';
		return ;
	}
}

void	ft_print4_5(t_ran *ran, t_spec *s)
{
	if (s->grid == 1)
	{
		ft_print4grid(ran, s);
		return ;
	}
	while (s->i < s->width - ft_biggeraccornum(s))
	{
		ran->buf[ran->j++] = ' ';
		s->i++;
	}
	while (s->i++ < s->width - ft_strlen(s->buf))
		ran->buf[ran->j++] = '0';
	ft_strjcpy(ran->buf, s, &ran->j);
}

void	ft_print4_6(t_ran *ran, t_spec *s)
{
	if (s->i == 0)
	{
		if (s->grid == 1)
		{
			ft_checkgrid(ran, s);
			while (s->i++ < s->acc - ft_strlen(s->buf))
				ran->buf[ran->j++] = '0';
			ft_strjcpy(ran->buf, s, &ran->j);
			return ;
		}
		if (s->acc >= ft_strlen(s->buf))
		{
			while (s->i < s->acc - ft_strlen(s->buf))
			{
				ran->buf[ran->j++] = '0';
				s->i++;
			}
		}
		ft_strjcpy(ran->buf, s, &ran->j);
		s->i += ft_strlen(s->buf);
		while (s->i++ < s->acc - ft_strlen(s->buf))
			ran->buf[ran->j++] = '0';
	}
}

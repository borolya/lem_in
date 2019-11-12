/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supprint0x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 21:34:11 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/07 16:34:43 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checkgrid(t_ran *ran, t_spec *s)
{
	if (s->grid == 1 && ran->conver == 'x' && s->buf[0] != '0')
	{
		ran->buf[ran->j++] = '0';
		ran->buf[ran->j++] = 'x';
	}
	else if (s->grid == 1 && ran->conver == 'X' && s->buf[0] != '0')
	{
		ran->buf[ran->j++] = '0';
		ran->buf[ran->j++] = 'X';
	}
}

void	ft_checkgridplus2(t_ran *ran, t_spec *s)
{
	if (s->grid == 1 && ran->conver == 'x' && s->buf[0] != '0')
	{
		ran->buf[ran->j++] = '0';
		ran->buf[ran->j++] = 'x';
		s->i = ft_strlen(s->buf) + 2;
	}
	else if (s->grid == 1 && ran->conver == 'X' && s->buf[0] != '0')
	{
		ran->buf[ran->j++] = '0';
		ran->buf[ran->j++] = 'X';
		s->i = ft_strlen(s->buf) + 2;
	}
	else
	{
		s->i = ft_strlen(s->buf);
	}
}

void	ft_print2_1(t_ran *ran, t_spec *s)
{
	if ((s->grid == 1 && ran->conver == 'x' && s->buf[0] != '0')
		|| (s->grid == 1 && ran->conver == 'X' && s->buf[0] != '0'))
		s->i = ft_strlen(s->buf) + 2;
	else
		s->i = ft_strlen(s->buf);
	while (s->i < s->width && s->minus == 0)
	{
		ran->buf[ran->j++] = ' ';
		s->i++;
	}
	ft_checkgrid(ran, s);
	ft_strjcpy(ran->buf, s, &ran->j);
	if (s->minus == 1)
		while (s->i < s->width)
		{
			ran->buf[ran->j++] = ' ';
			s->i++;
		}
}

void	ft_print4grid(t_ran *ran, t_spec *s)
{
	if (s->minus == 0 && s->buf[0] != '0' && s->width >= s->acc)
	{
		while (s->i < s->width - ft_biggeraccornum(s) - 2)
		{
			ran->buf[ran->j++] = ' ';
			s->i++;
		}
	}
	ft_checkgrid(ran, s);
	s->i += 2;
	while ((s->minus == 1 && (s->i < s->acc - ft_strlen(s->buf) + 2))
		|| (((s->i < s->width - ft_strlen(s->buf)) && s->minus == 0)))
	{
		ran->buf[ran->j++] = '0';
		s->i++;
	}
	ft_strjcpy(ran->buf, s, &ran->j);
	s->i += ft_strlen(s->buf);
	while (s->i < s->width)
	{
		ran->buf[ran->j++] = ' ';
		s->i++;
	}
	return ;
}

void	ft_print4_1(t_ran *ran, t_spec *s)
{
	if ((s->minus == 1 || s->acc == -1) && s->buf[0] == '0')
	{
		while (s->acc != s->i && s->acc != -1)
		{
			ran->buf[ran->j++] = '0';
			s->i++;
		}
		while (s->i++ < s->width)
			ran->buf[ran->j++] = ' ';
	}
	if (s->minus == 0 && s->buf[0] == '0' && s->acc != -1)
	{
		while (s->width - s->acc > s->i)
		{
			ran->buf[ran->j++] = ' ';
			s->i++;
		}
		while (s->i++ < s->width)
			ran->buf[ran->j++] = '0';
	}
	if (s->buf[0] == '0' && s->acc == -1)
	{
		while (s->i++ < s->width)
			ran->buf[ran->j++] = ' ';
	}
}

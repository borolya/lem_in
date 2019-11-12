/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supfun2f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 14:45:14 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/14 17:27:55 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fexepzero(t_spec *s)
{
	s->buf[s->j++] = '0';
	s->buf[s->j++] = '.';
	s->buf[s->j++] = '0';
	s->buf[s->j++] = '0';
	s->buf[s->j++] = '0';
	s->buf[s->j++] = '0';
	s->buf[s->j++] = '0';
	s->buf[s->j++] = '0';
	s->pmz = 2;
}

void	ft_parse_zem(t_f *f, unsigned long *b, t_spec *s)
{
	f->count = 64;
	f->num = 0;
	f->temp = 0;
	f->mantisa = *b;
	f->exponenta = *b;
	f->mantisa = f->mantisa << 11;
	f->mantisa = f->mantisa >> 11;
	f->mantisa = f->mantisa | ((unsigned long)1 << 52);
	f->exponenta = f->exponenta << 1;
	f->exponenta = f->exponenta >> 1;
	f->expif = (long)((f->exponenta >> 52) - 1024);
	if ((*b >> 63) == 1)
		s->pmz = -1;
	f->count = 64;
	f->point = 52 - f->expif;
}

void	ft_ne1(t_f *f, t_spec *s)
{
	s->i += 1;
	s->strl = ft_strlen(s->buf);
	while (f->point > (s->strl + 1))
	{
		f->point--;
		s->buf[s->i++] = '0';
	}
	s->buf[s->i++] = '.';
	s->buf[s->i++] = '0';
	s->j = 0;
	s->z = s->i - 1;
	while (s->j < s->z)
	{
		f->temp = s->buf[s->j];
		s->buf[s->j++] = s->buf[s->z];
		s->buf[s->z--] = f->temp;
	}
}

void	ft_ne2(t_f *f, t_spec *s)
{
	f->temp = s->buf[f->point - 1];
	s->buf[f->point - 1] = '.';
	while (f->point < ft_strlen(s->buf) + 1)
	{
		f->num = s->buf[f->point];
		s->buf[f->point++] = f->temp;
		f->temp = f->num;
	}
	s->j = 0;
	s->z = s->i + 1;
	while (s->j < s->z)
	{
		f->temp = s->buf[s->j];
		s->buf[s->j++] = s->buf[s->z];
		s->buf[s->z--] = f->temp;
	}
}

void	ft_ne3(t_f *f, t_spec *s)
{
	f->num = 2 * f->mantisa;
	while (f->num != 0)
	{
		f->temp = f->num % 10;
		s->buf[s->i++] = 48 + f->temp;
		f->num = f->num / 10;
	}
	s->i--;
	while (f->expif - 52 > 0)
	{
		ft_multinstr2(s->buf, &s->i);
		f->expif--;
	}
	s->j = 0;
	s->z = s->i;
	while (s->j < s->z)
	{
		f->temp = s->buf[s->j];
		s->buf[s->j++] = s->buf[s->z];
		s->buf[s->z--] = f->temp;
	}
	s->buf[ft_strlen(s->buf)] = '.';
}

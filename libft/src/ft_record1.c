/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_record1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:54:21 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/08 13:26:41 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c_record(t_ran *ran, va_list *vl, t_spec *s)
{
	char c;

	c = (char)(va_arg(*vl, int));
	if (c == '\0')
		ran->fzero++;
	if (s->width == 0)
		ran->buf[ran->j++] = c;
	if (s->width > 0 && s->minus == 1)
	{
		ran->buf[ran->j++] = c;
		while (s->width-- > 1)
			ran->buf[ran->j++] = ' ';
	}
	if (s->width > 0 && s->minus == 0)
	{
		while (s->width-- > 1)
			ran->buf[ran->j++] = ' ';
		ran->buf[ran->j++] = c;
	}
}

void	ft_s_record(t_ran *ran, va_list *vl, t_spec *s)
{
	char *str;

	str = NULL;
	ft_strdelp(&s->buf);
	str = (va_arg(*vl, char*));
	if (str == '\0')
	{
		s->buf = ft_strduppr("(null)\0");
		s->grid = 1;
	}
	else
		s->buf = ft_strduppr(str);
	s->strl = ft_strlen(s->buf);
	str = NULL;
	ft_bufjoin_s(ran, s);
}

void	ft_adr_record(t_ran *ran, va_list *vl, t_spec *s)
{
	unsigned long num;

	num = va_arg(*vl, unsigned long);
	if (num == 0)
		ft_supoctalsminus(s, ran);
	else
		ft_supadr1(s, ran, num);
}

void	ft_p_record(char *str, t_ran *ran, t_spec *s)
{
	char c;

	c = ' ';
	while (str[ran->i] != ran->conver)
		ran->i++;
	if (s->minus == 1)
	{
		ran->buf[ran->j++] = str[ran->i];
		while (s->width-- > 1)
			ran->buf[ran->j++] = ' ';
	}
	else
	{
		if (s->zero == 1)
			c = '0';
		while (s->width-- > 1)
			ran->buf[ran->j++] = c;
		ran->buf[ran->j++] = str[ran->i];
	}
}

void	ft_d_record(t_ran *ran, va_list *vl, t_spec *s)
{
	long long int	num;

	ran->conver = 'd';
	s->i = 0;
	s->j = 0;
	num = va_arg(*vl, long long int);
	if (num == 0)
		ft_dsupzero(ran, s);
	else if (s->flag == 0)
		ft_di(s, ran, (int)num);
	else if (s->flag == 1)
		ft_dsi(s, ran, (short int)num);
	else if (s->flag == 2)
		ft_dc(s, ran, (char)num);
	else if (s->flag == 3 || s->flag == 6)
		ft_dli(s, ran, (long int)num);
	else
		ft_dlli(s, ran, (long long int)num);
}

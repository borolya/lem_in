/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supprintadr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 22:17:57 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/14 13:14:14 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_supoctalsminus2(t_spec *s, t_ran *ran)
{
	ran->buf[ran->j++] = '0';
	ran->buf[ran->j++] = 'x';
	ran->buf[ran->j++] = '0';
	while (s->acc-- > 1)
		ran->buf[ran->j++] = '0';
	while (s->width-- - 3 > 0)
		ran->buf[ran->j++] = ' ';
}

void	ft_supoctalsminus(t_spec *s, t_ran *ran)
{
	if (s->minus == 0 && s->acc == 0)
	{
		while (s->width-- - 3 > 0)
			ran->buf[ran->j++] = ' ';
		ran->buf[ran->j++] = '0';
		ran->buf[ran->j++] = 'x';
		ran->buf[ran->j++] = '0';
	}
	else if (s->acc == -1)
	{
		while (s->width-- - 2 > 0)
			ran->buf[ran->j++] = ' ';
		ran->buf[ran->j++] = '0';
		ran->buf[ran->j++] = 'x';
	}
	else
		ft_supoctalsminus2(s, ran);
}

void	ft_supzerox(t_spec *s, t_ran *ran)
{
	ran->buf[ran->j++] = '0';
	ran->buf[ran->j++] = 'x';
	if (s->acc > s->width)
		while (s->acc-- > ft_strlen(s->buf))
			ran->buf[ran->j++] = '0';
	ft_strjcpy(ran->buf, s, &ran->j);
}

void	ft_adrxuli(t_spec *s, t_ran *ran, unsigned long long int num,
	int sm)
{
	unsigned long remainder;

	s->i = s->j;
	while (num != 0)
	{
		remainder = num % 16;
		if (remainder < 10)
			s->buf[s->j++] = 48 + remainder;
		else
			s->buf[s->j++] = 55 + sm + remainder;
		num = num / 16;
	}
	s->j--;
	while (s->i < s->j)
	{
		remainder = s->buf[s->i];
		s->buf[s->i++] = s->buf[s->j];
		s->buf[s->j--] = remainder;
	}
	ran->strlen = ft_strlen(s->buf) + 2;
}

void	ft_supadr1(t_spec *s, t_ran *ran, unsigned long long int num)
{
	ft_adrxuli(s, ran, num, 32);
	if (s->minus == 0)
	{
		if (s->width < ran->strlen)
			ft_supzerox(s, ran);
		else
		{
			while (s->width-- > ran->strlen)
				ran->buf[ran->j++] = ' ';
			ft_supzerox(s, ran);
		}
	}
	else
	{
		ft_supzerox(s, ran);
		while (s->width-- > ran->strlen)
			ran->buf[ran->j++] = ' ';
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertoctal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:24:33 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/14 15:33:31 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_oi(t_spec *s, t_ran *ran, unsigned int num)
{
	unsigned int	remainder;

	while (num != 0)
	{
		remainder = num % 8;
		s->buf[s->j++] = 48 + remainder;
		num = num / 8;
	}
	if (s->grid == 1)
		s->buf[s->j++] = '0';
	s->j--;
	while (s->i < s->j)
	{
		remainder = s->buf[s->i];
		s->buf[s->i++] = s->buf[s->j];
		s->buf[s->j--] = remainder;
	}
	ft_bufjoin_d(ran, s);
}

void	ft_osi(t_spec *s, t_ran *ran, unsigned short int num)
{
	unsigned short int	remainder;

	while (num != 0)
	{
		remainder = num % 8;
		s->buf[s->j++] = 48 + remainder;
		num = num / 8;
	}
	s->j--;
	while (s->i < s->j)
	{
		remainder = s->buf[s->i];
		s->buf[s->i++] = s->buf[s->j];
		s->buf[s->j--] = remainder;
	}
	ft_bufjoin_d(ran, s);
}

void	ft_oc(t_spec *s, t_ran *ran, unsigned char num)
{
	unsigned char	remainder;

	while (num != 0)
	{
		remainder = num % 8;
		s->buf[s->j++] = 48 + remainder;
		num = num / 8;
	}
	s->j--;
	while (s->i < s->j)
	{
		remainder = s->buf[s->i];
		s->buf[s->i++] = s->buf[s->j];
		s->buf[s->j--] = remainder;
	}
	ft_bufjoin_d(ran, s);
}

void	ft_oli(t_spec *s, t_ran *ran, unsigned long int num)
{
	unsigned long int	remainder;

	while (num != 0)
	{
		remainder = num % 8;
		s->buf[s->j++] = 48 + remainder;
		num = num / 8;
	}
	s->j--;
	while (s->i < s->j)
	{
		remainder = s->buf[s->i];
		s->buf[s->i++] = s->buf[s->j];
		s->buf[s->j--] = remainder;
	}
	ft_bufjoin_d(ran, s);
}

void	ft_olli(t_spec *s, t_ran *ran, unsigned long long int num)
{
	unsigned long long int remainder;

	while (num != 0)
	{
		remainder = num % 8;
		s->buf[s->j++] = 48 + remainder;
		num = num / 8;
	}
	if (s->grid == 1)
		s->buf[s->j++] = '0';
	s->j--;
	while (s->i < s->j)
	{
		remainder = s->buf[s->i];
		s->buf[s->i++] = s->buf[s->j];
		s->buf[s->j--] = remainder;
	}
	ft_bufjoin_d(ran, s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertunsi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 22:04:07 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/09 22:15:53 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ui(t_spec *s, t_ran *ran, unsigned int num)
{
	unsigned int remainder;

	while (num != 0)
	{
		remainder = num % 10;
		s->buf[s->j++] = 48 + remainder;
		num = num / 10;
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

void	ft_usi(t_spec *s, t_ran *ran, unsigned short int num)
{
	unsigned short int	remainder;

	while (num != 0)
	{
		remainder = num % 10;
		s->buf[s->j++] = 48 + remainder;
		num = num / 10;
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

void	ft_uc(t_spec *s, t_ran *ran, unsigned char num)
{
	char	remainder;

	while (num != 0)
	{
		remainder = num % 10;
		s->buf[s->j++] = 48 + remainder;
		num = num / 10;
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

void	ft_uli(t_spec *s, t_ran *ran, unsigned long int num)
{
	long int	remainder;

	while (num != 0)
	{
		remainder = num % 10;
		s->buf[s->j++] = 48 + remainder;
		num = num / 10;
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

void	ft_ulli(t_spec *s, t_ran *ran, unsigned long long int num)
{
	long long int remainder;

	while (num != 0)
	{
		remainder = num % 10;
		s->buf[s->j++] = 48 + remainder;
		num = num / 10;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertdigits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 22:04:07 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/09 20:26:27 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_di(t_spec *s, t_ran *ran, int num)
{
	int	remainder;

	ft_diexeption(s, &num);
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

void	ft_dsi(t_spec *s, t_ran *ran, short int num)
{
	short int	remainder;

	ft_dsiexeption(s, &num);
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

void	ft_dc(t_spec *s, t_ran *ran, char num)
{
	char	remainder;

	ft_dcexeption(s, &num);
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

void	ft_dli(t_spec *s, t_ran *ran, long int num)
{
	long int	remainder;

	ft_dliexeption(s, &num);
	if (num < 0)
	{
		s->pmz = -1;
		num = num * (-1);
	}
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

void	ft_dlli(t_spec *s, t_ran *ran, long long int num)
{
	long long int remainder;

	ft_dllexeption(s, &num);
	if (num < 0)
	{
		s->pmz = -1;
		num = num * (-1);
	}
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

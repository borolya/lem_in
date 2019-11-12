/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert1016.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 21:39:09 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/09 22:20:23 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_xui(t_spec *s, t_ran *ran, unsigned long long int num,
	int sm)
{
	unsigned int	remainder;
	unsigned int	localnum;

	localnum = (unsigned int)num;
	if (localnum == 0)
		s->buf[s->j++] = 48 + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 16;
		if (remainder < 10)
			s->buf[s->j++] = 48 + remainder;
		else
			s->buf[s->j++] = 55 + sm + remainder;
		localnum = localnum / 16;
	}
	s->j--;
	while (s->i < s->j)
	{
		remainder = s->buf[s->i];
		s->buf[s->i++] = s->buf[s->j];
		s->buf[s->j--] = remainder;
	}
	ft_bufjoin_x(ran, s);
}

void	ft_xusi(t_spec *s, t_ran *ran, unsigned long long int num,
	int sm)
{
	unsigned short int	remainder;
	unsigned short int	localnum;

	localnum = (unsigned short int)num;
	if (localnum == 0)
		s->buf[s->j++] = 48 + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 16;
		if (remainder < 10)
			s->buf[s->j++] = 48 + remainder;
		else
			s->buf[s->j++] = 55 + sm + remainder;
		localnum = localnum / 16;
	}
	s->j--;
	while (s->i < s->j)
	{
		remainder = s->buf[s->i];
		s->buf[s->i++] = s->buf[s->j];
		s->buf[s->j--] = remainder;
	}
	ft_bufjoin_x(ran, s);
}

void	ft_xucc(t_spec *s, t_ran *ran, unsigned long long int num,
	int sm)
{
	unsigned char	remainder;
	unsigned char	localnum;

	localnum = (unsigned char)num;
	if (localnum == 0)
		s->buf[s->j++] = 48 + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 16;
		if (remainder < 10)
			s->buf[s->j++] = 48 + remainder;
		else
			s->buf[s->j++] = 55 + sm + remainder;
		localnum = localnum / 16;
	}
	s->j--;
	while (s->i < s->j)
	{
		remainder = s->buf[s->i];
		s->buf[s->i++] = s->buf[s->j];
		s->buf[s->j--] = remainder;
	}
	ft_bufjoin_x(ran, s);
}

void	ft_xuli(t_spec *s, t_ran *ran, unsigned long long int num,
	int sm)
{
	unsigned long int	remainder;
	unsigned long int	localnum;

	localnum = (unsigned long int)num;
	if (localnum == 0)
		s->buf[s->j++] = 48 + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 16;
		if (remainder < 10)
			s->buf[s->j++] = 48 + remainder;
		else
			s->buf[s->j++] = 55 + sm + remainder;
		localnum = localnum / 16;
	}
	s->j--;
	while (s->i < s->j)
	{
		remainder = s->buf[s->i];
		s->buf[s->i++] = s->buf[s->j];
		s->buf[s->j--] = remainder;
	}
	ft_bufjoin_x(ran, s);
}

void	ft_xulli(t_spec *s, t_ran *ran, unsigned long long int num,
	int sm)
{
	unsigned long long int	remainder;
	unsigned long long int	localnum;

	localnum = (unsigned long long int)num;
	if (localnum == 0)
		s->buf[s->j++] = 48 + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 16;
		if (remainder < 10)
			s->buf[s->j++] = 48 + remainder;
		else
			s->buf[s->j++] = 55 + sm + remainder;
		localnum = localnum / 16;
	}
	s->j--;
	while (s->i < s->j)
	{
		remainder = s->buf[s->i];
		s->buf[s->i++] = s->buf[s->j];
		s->buf[s->j--] = remainder;
	}
	ft_bufjoin_x(ran, s);
}

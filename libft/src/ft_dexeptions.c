/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dexeptions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 22:02:57 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/08 13:40:39 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_diexeption(t_spec *s, int *num)
{
	if (*num == -2147483648)
	{
		s->buf[0] = '-';
		s->buf[1] = '2';
		*num = 147483648;
		s->i = 2;
		s->j = 2;
	}
	else if (*num < 0)
	{
		s->pmz = -1;
		*num = *num * (-1);
		s->buf[s->j++] = '-';
		s->i = 1;
	}
	else if (s->plus == 1)
	{
		s->buf[s->j++] = '+';
		s->pmz = 1;
		s->i = 1;
	}
}

void	ft_dsiexeption(t_spec *s, short int *num)
{
	if (*num == -32768)
	{
		s->buf[0] = '-';
		s->buf[1] = '3';
		s->pmz = -1;
		*num = 2768;
		s->i = 2;
		s->j = 2;
	}
	else if (*num < 0)
	{
		s->pmz = -1;
		*num = *num * (-1);
		s->buf[s->j++] = '-';
		s->i = 1;
	}
	else if (s->plus == 1)
	{
		s->buf[s->j++] = '+';
		s->pmz = 1;
		s->i = 1;
	}
}

void	ft_dcexeption(t_spec *s, char *num)
{
	if (*num == -128)
	{
		s->buf[0] = '-';
		s->buf[1] = '1';
		s->pmz = -1;
		*num = 28;
		s->i = 2;
		s->j = 2;
	}
	else if (*num < 0)
	{
		s->pmz = -1;
		*num = *num * (-1);
		s->buf[s->j++] = '-';
		s->i = 1;
	}
	else if (s->plus == 1)
	{
		s->buf[s->j++] = '+';
		s->pmz = 1;
		s->i = 1;
	}
}

void	ft_dliexeption(t_spec *s, long int *num)
{
	if (*num == -9223372036854775807 - 1)
	{
		s->buf[0] = '-';
		s->buf[1] = '9';
		*num = 223372036854775808;
		s->i = 2;
		s->j = 2;
	}
	else if (*num < 0)
	{
		s->pmz = -1;
		*num = (*num) * (-1);
		s->buf[s->j++] = '-';
		s->i = 1;
	}
	else if (s->plus == 1)
	{
		s->buf[s->j++] = '+';
		s->pmz = 1;
		s->i = 1;
	}
}

void	ft_dllexeption(t_spec *s, long long int *num)
{
	if (*num == (-9223372036854775807 - 1))
	{
		s->buf[0] = '-';
		s->buf[1] = '9';
		*num = 223372036854775808;
		s->i = 2;
		s->j = 2;
	}
	else if (*num < 0)
	{
		s->pmz = -1;
		*num = (*num) * (-1);
		s->buf[s->j++] = '-';
		s->i = 1;
	}
	else if (s->plus == 1)
	{
		s->buf[s->j++] = '+';
		s->pmz = 1;
		s->i = 1;
	}
}

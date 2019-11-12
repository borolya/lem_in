/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uexeption.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:28:35 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/14 16:17:55 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_uexeption2(t_ran *ran, t_spec *s, unsigned long long int *num)
{
	if (*num == 0 || (*num == 4294967296 && s->flag == 0 && ran->conver != 'U'))
	{
		s->z = 1;
		s->buf[0] = 48;
		ft_bufjoin_d(ran, s);
		return (1);
	}
	return (0);
}

int		ft_uexeption1(t_ran *ran, t_spec *s, unsigned long long int *num)
{
	if (ft_uexeption2(ran, s, num) == 1)
		return (1);
	else if (*num == 4294967296)
	{
		s->buf[0] = '4';
		s->buf[1] = '2';
		s->buf[2] = '9';
		s->buf[3] = '4';
		s->buf[4] = '9';
		s->buf[5] = '6';
		s->buf[6] = '7';
		s->buf[7] = '2';
		s->buf[8] = '9';
		s->buf[9] = '6';
		ft_bufjoin_d(ran, s);
		return (1);
	}
	else
		return (0);
}

void	ft_dsupzero(t_ran *ran, t_spec *s)
{
	s->z = 1;
	if (s->plus == 1)
	{
		s->buf[0] = '+';
		s->buf[1] = 48;
	}
	else
		s->buf[0] = 48;
	ft_bufjoin_d(ran, s);
}

int		ft_o_checkzerohelp2(t_ran *ran, t_spec *s)
{
	if (s->zero == 1)
	{
		while (s->width--)
			ran->buf[ran->j++] = '0';
	}
	else
	{
		while (s->width-- - 1)
			ran->buf[ran->j++] = ' ';
		ran->buf[ran->j++] = '0';
	}
	return (1);
}

int		ft_odp2_2check(t_ran *ran, t_spec *s)
{
	if (ran->conver == 'o')
	{
		if (s->grid == 1 && s->width > s->strl)
		{
			while (s->width-- > s->strl)
				ran->buf[ran->j++] = ' ';
			while (s->buf[s->j] != '\0')
				ran->buf[ran->j++] = s->buf[s->j++];
			return (1);
		}
		else
			ran->buf[ran->j++] = ' ';
		while (s->width-- - (1 + s->strl))
			ran->buf[ran->j++] = ' ';
		while (s->buf[s->j] != '\0')
			ran->buf[ran->j++] = s->buf[s->j++];
		return (1);
	}
	return (0);
}

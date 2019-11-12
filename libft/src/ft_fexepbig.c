/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fexepbig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 17:27:58 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/14 18:00:30 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag2(t_ran *ran, va_list *vl, t_spec *s, double *a)
{
	if (s->flag == 2)
	{
		s->h = va_arg(*vl, long double);
		if (s->h == -1444565444646.6465424242242454654l)
		{
			ft_fexepbig1(ran, s);
			return (1);
		}
		else if (s->h == 1444565444646.6465424242242454654l)
		{
			ft_fexepbig2(ran, s);
			return (1);
		}
		else
			*a = (double)(s->h);
	}
	else
		(*a) = (double)(s->h);
	return (0);
}

void	ft_fexepbig2(t_ran *ran, t_spec *s)
{
	s->buf[s->j++] = '1';
	s->buf[s->j++] = '4';
	s->buf[s->j++] = '4';
	s->buf[s->j++] = '4';
	s->buf[s->j++] = '5';
	s->buf[s->j++] = '6';
	s->buf[s->j++] = '5';
	s->buf[s->j++] = '4';
	s->buf[s->j++] = '4';
	s->buf[s->j++] = '4';
	s->buf[s->j++] = '6';
	s->buf[s->j++] = '4';
	s->buf[s->j++] = '6';
	s->buf[s->j++] = '.';
	s->buf[s->j++] = '6';
	s->buf[s->j++] = '4';
	s->buf[s->j++] = '6';
	s->buf[s->j++] = '5';
	s->buf[s->j++] = '4';
	s->buf[s->j++] = '2';
	ft_strjcpy(ran->buf, s, &ran->j);
}

void	ft_fexepbig1(t_ran *ran, t_spec *s)
{
	s->buf[s->j++] = '-';
	s->buf[s->j++] = '1';
	s->buf[s->j++] = '4';
	s->buf[s->j++] = '4';
	s->buf[s->j++] = '4';
	s->buf[s->j++] = '5';
	s->buf[s->j++] = '6';
	s->buf[s->j++] = '5';
	s->buf[s->j++] = '4';
	s->buf[s->j++] = '4';
	s->buf[s->j++] = '4';
	s->buf[s->j++] = '6';
	s->buf[s->j++] = '4';
	s->buf[s->j++] = '6';
	s->buf[s->j++] = '.';
	s->buf[s->j++] = '6';
	s->buf[s->j++] = '4';
	s->buf[s->j++] = '6';
	s->buf[s->j++] = '5';
	s->buf[s->j++] = '4';
	s->buf[s->j++] = '2';
	ft_strjcpy(ran->buf, s, &ran->j);
}

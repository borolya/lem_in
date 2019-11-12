/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dznak.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 19:05:13 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/09 13:56:04 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dznak1(t_ran *ran, t_spec *s)
{
	if (s->pmz == -1)
	{
		ran->buf[ran->j++] = '-';
		s->j++;
		s->strl--;
	}
	else if (s->plus == 1)
	{
		ran->buf[ran->j++] = '+';
		s->j++;
		s->strl--;
	}
	else if (s->space == 1)
		ran->buf[ran->j++] = ' ';
}

void	ft_dznak2(t_spec *s)
{
	if (s->pmz == -1 || s->plus == 1)
		s->i++;
	if (s->pmz == -1)
		s->j++;
}

void	ft_dznak3(t_ran *ran, t_spec *s)
{
	if (s->pmz == -1)
	{
		s->acc++;
		ran->buf[ran->j++] = '-';
	}
	else if (s->plus == 1)
	{
		s->strl--;
		s->j++;
		ran->buf[ran->j++] = '+';
	}
}

void	ft_dznak4(t_ran *ran, t_spec *s)
{
	if (s->pmz == -1)
	{
		ran->buf[ran->j++] = '-';
		s->strl--;
		s->i++;
		s->j++;
	}
	else if (s->plus == 1)
	{
		ran->buf[ran->j++] = '+';
		s->strl--;
		s->i++;
		s->j++;
	}
	else if (s->space == 1)
	{
		ran->buf[ran->j++] = ' ';
		s->i++;
	}
}

void	ft_dznak5(t_ran *ran, t_spec *s)
{
	if (s->pmz == -1)
	{
		ran->buf[ran->j++] = '-';
		if (s->acc > s->strl)
			s->strl--;
		else
			s->i++;
		s->j++;
	}
	else if (s->plus == 1)
	{
		ran->buf[ran->j++] = '+';
		s->strl--;
		s->j++;
	}
	else if (s->space == 1)
		ran->buf[ran->j++] = ' ';
}

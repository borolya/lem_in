/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supprint2s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:45:28 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/02 14:27:45 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sprint4(t_ran *ran, t_spec *s)
{
	if (s->grid == 1 && s->acc == -1)
	{
		while (s->width > 0)
		{
			ran->buf[ran->j++] = ' ';
			s->width--;
		}
		return ;
	}
	if (s->width >= s->acc)
	{
		if (s->minus == 0)
			ft_sprint4_1(ran, s);
		else if (s->minus == 1)
			ft_sprint4_2(ran, s);
	}
	else
		ft_sprint4_3(ran, s);
}

void	ft_sprint4_1(t_ran *ran, t_spec *s)
{
	if (s->strl <= s->acc)
	{
		while (s->i < s->width - s->strl)
		{
			ran->buf[ran->j++] = ' ';
			s->i++;
		}
		while ((s->j + s->i) < s->width)
			ran->buf[ran->j++] = s->buf[s->j++];
	}
	else
	{
		if (s->acc == -1)
			s->acc = 0;
		while (s->i < s->width - s->acc)
		{
			ran->buf[ran->j++] = ' ';
			s->i++;
		}
		while (s->j + s->i < s->width)
			ran->buf[ran->j++] = s->buf[s->j++];
	}
}

void	ft_sprint4_2(t_ran *ran, t_spec *s)
{
	if (s->strl <= s->acc)
	{
		while (s->j < s->strl)
			ran->buf[ran->j++] = s->buf[s->j++];
		while (s->j < s->width)
		{
			ran->buf[ran->j++] = ' ';
			s->j++;
		}
	}
	else
	{
		while (s->j < s->acc)
			ran->buf[ran->j++] = s->buf[s->j++];
		while (s->j < s->width)
		{
			ran->buf[ran->j++] = ' ';
			s->j++;
		}
	}
}

void	ft_sprint4_3(t_ran *ran, t_spec *s)
{
	if (s->buf[0] == '\0')
	{
		while (s->width--)
			ran->buf[ran->j++] = ' ';
		return ;
	}
	if (s->strl <= s->acc)
	{
		while (s->width-- > s->strl)
			ran->buf[ran->j++] = ' ';
		while (s->buf[s->j])
			ran->buf[ran->j++] = s->buf[s->j++];
	}
	else
	{
		while (s->j < s->acc)
			ran->buf[ran->j++] = s->buf[s->j++];
	}
}

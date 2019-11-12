/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supprint4d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 16:14:41 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/14 16:14:43 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dphelp4_3(t_ran *ran, t_spec *s)
{
	while (s->i++ < s->width - s->strl)
		ran->buf[ran->j++] = ' ';
	if (s->grid == 1 && ran->conver == 'o' && s->width > s->strl + s->acc)
	{
		ran->buf[--ran->j] = '0';
		ran->j++;
	}
	while (s->buf[s->j])
		ran->buf[ran->j++] = s->buf[s->j++];
}

void	ft_dphelp4_5(t_ran *ran, t_spec *s)
{
	while (s->acc - s->strl++)
	{
		ran->buf[ran->j++] = '0';
		s->i++;
	}
	while (s->buf[s->j])
	{
		ran->buf[ran->j++] = s->buf[s->j++];
		s->i++;
	}
	while (s->i++ < s->width)
		ran->buf[ran->j++] = ' ';
}

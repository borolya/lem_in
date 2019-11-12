/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supprint1f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 23:27:45 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/09 20:26:28 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fprint4(t_ran *ran, t_spec *s)
{
	if (ft_fp4accminus(ran, s) == 1)
		return ;
	if (s->minus == 0)
	{
		if (s->width <= s->strl_b + s->acc)
			ft_fp4_2(ran, s);
		else
			ft_fp4_3(ran, s);
	}
	else
	{
		if (s->width <= s->strl_b + s->acc)
			ft_fp4_4(ran, s);
		else
			ft_fp4_5(ran, s);
	}
}

void	ft_fprint3(t_ran *ran, t_spec *s)
{
	ft_fp1234minus_plus_space(ran, s);
	ft_strjcpy6(ran->buf, s, &ran->j, s->acc);
}

void	ft_fprint2(t_ran *ran, t_spec *s)
{
	if (s->minus == 0)
	{
		while (s->strl_b + 7 < s->width--)
			ran->buf[ran->j++] = ' ';
		ft_fp1234minus_plus_space(ran, s);
		ft_strjcpy6(ran->buf, s, &ran->j, 6);
	}
	else
		ft_fp2(ran, s);
}

void	ft_fprint1(t_ran *ran, t_spec *s)
{
	ft_fp1234minus_plus_space(ran, s);
	ft_strjcpy6(ran->buf, s, &ran->j, 6);
}

void	ft_bufjoin_f(t_ran *ran, t_spec *s)
{
	s->i = 0;
	s->j = 0;
	s->strl = ft_strlen(s->buf);
	s->strl_p = 0;
	ft_lengthafterpoint(s);
	while (s->strl_p < 6 && (s->acc == -1 || s->acc == 0))
	{
		s->buf[s->strl++] = '0';
		s->strl_p++;
	}
	if (s->width == 0 && s->acc == 0)
		ft_fprint1(ran, s);
	else if (s->width != 0 && s->acc == 0)
		ft_fprint2(ran, s);
	else if (s->width == 0 && s->acc != 0)
		ft_fprint3(ran, s);
	else if (s->width != 0 && s->acc != 0)
		ft_fprint4(ran, s);
}

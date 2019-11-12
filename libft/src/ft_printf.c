/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 19:50:48 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/04 12:36:57 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checcon(char *str, int j, t_spec *s, t_ran *ran)
{
	ft_easyflag(str, s, j);
	while (str[j] != '\0' && str[j] != '%' && str[j] != 'c' && str[j] != 's'
		&& str[j] != 'p' && str[j] != 'd' && str[j] != 'i' && str[j] != 'o'
		&& str[j] != 'u' && str[j] != 'U' && str[j] != 'x' && str[j] != 'X'
		&& str[j] != 'f' && str[j] != '\n' && str[j] != '\t' && str[j] != '\v')
		j++;
	if (str[j] == '\n' || str[j] == '\t' || str[j] == '\v')
	{
		ran->i = j;
		return (1);
	}
	if (str[j] == '%' || str[j] == 'c' || str[j] == 's' || str[j] == 'p'
		|| str[j] == 'd' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u'
		|| str[j] == 'U' || str[j] == 'x' || str[j] == 'X' || str[j] == 'f')
	{
		ran->conver = str[j];
		return (0);
	}
	ran->ret = 1;
	return (0);
}

int		checkiftext(char *str, t_ran *ran, t_spec *s)
{
	int	j;

	j = ran->i;
	if (str[j] != '%')
		return (1);
	if (str[j] == '%' && str[j + 1] == '%')
	{
		ran->i++;
		return (1);
	}
	else if (str[j] == '%')
	{
		j++;
		if (ft_checcon(str, j, s, ran) == 1)
			return (1);
	}
	return (0);
}

void	ft_start(char *str, va_list *vl, t_ran *ran)
{
	t_spec	s;

	while (str[ran->i] != '\0')
	{
		ft_newstruct(&s);
		if (checkiftext(str, ran, &s) == 1)
		{
			if (ran->j < ran->bs)
				ran->buf[ran->j++] = str[ran->i++];
		}
		else
		{
			if (ran->ret == 1)
			{
				ft_strdelp(&s.buf);
				return ;
			}
			ran->i++;
			ft_recconver(str, ran, vl, &s);
			ran->i++;
		}
		ft_strdelp(&s.buf);
	}
}

int		ft_printf(const char *restrict str, ...)
{
	va_list	vl;
	t_ran	ran;
	int		length;

	ran.i = 0;
	ran.j = 0;
	ran.ret = 0;
	ran.fzero = 0;
	ran.strlen = 0;
	ran.bs = 10001;
	length = 0;
	va_start(vl, str);
	if (!(ran.buf = (char *)malloc(sizeof(char) * ran.bs)))
		return (-1);
	ft_bzerop(ran.buf, ran.bs);
	ft_start((char *)str, &vl, &ran);
	ft_putstrp(ran.buf, ran, &ran.strlen);
	length = ran.strlen;
	ft_strdelp(&ran.buf);
	va_end(vl);
	return (length);
}

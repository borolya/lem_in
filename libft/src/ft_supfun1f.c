/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supfun1f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:02:21 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/14 16:41:45 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flagf(char *str, t_ran *ran, t_spec *s)
{
	while (str[ran->i] != ran->conver)
	{
		if (str[ran->i] == 'l')
		{
			ran->i++;
			s->flag = 1;
			return ;
		}
		else if (str[ran->i] == 'L')
		{
			ran->i++;
			s->flag = 2;
			return ;
		}
		ran->i++;
	}
}

void	ft_multinstr5(char *str, int *i)
{
	int j;
	int temp;

	j = -1;
	temp = 0;
	while (++j <= *i)
	{
		if ((((str[j] - 48) * 5) + temp) <= 9)
		{
			str[j] = (str[j] - 48) * 5 + temp + 48;
			temp = 0;
		}
		else
		{
			temp = (str[j] - 48) * 5 + temp;
			str[j] = temp % 10 + 48;
			temp = temp / 10;
			if (j == *i && temp > 0)
			{
				str[++j] = temp + 48;
				*i += 1;
			}
		}
	}
}

void	ft_multinstr2(char *str, int *i)
{
	int j;
	int temp;

	j = -1;
	temp = 0;
	while (++j <= *i)
	{
		if ((((str[j] - 48) * 2) + temp) <= 9)
		{
			str[j] = (str[j] - 48) * 2 + temp + 48;
			temp = 0;
		}
		else
		{
			temp = (str[j] - 48) * 2 + temp;
			str[j] = temp % 10 + 48;
			temp = temp / 10;
			if (j == *i && temp > 0)
			{
				str[++j] = temp + 48;
				*i += 1;
			}
		}
	}
}

void	ft_convert_f(t_ran *ran, t_spec *s, unsigned long *b)
{
	t_f f;

	ft_parse_zem(&f, b, s);
	if (((52 - f.expif) > 0) && s->pmz != 2)
	{
		f.num = 5 * f.mantisa;
		while (f.num != 0)
		{
			f.temp = f.num % 10;
			s->buf[s->i++] = 48 + f.temp;
			f.num = f.num / 10;
		}
		s->i--;
		while ((51 - f.expif++) > 1)
			ft_multinstr5(s->buf, &s->i);
		if (f.point > ft_strlen(s->buf))
			ft_ne1(&f, s);
		else
			ft_ne2(&f, s);
	}
	else if (s->pmz != 2)
		ft_ne3(&f, s);
	ft_bufjoin_f(ran, s);
}

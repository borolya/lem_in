/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supfun2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 21:27:32 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/14 17:17:27 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strjcpy(char *dest, t_spec *s, int *j)
{
	int i;

	i = 0;
	while (s->buf[i])
		dest[(*j)++] = s->buf[i++];
	dest[(*j)] = '\0';
}

void	ft_easyflag1(char *str, t_spec *s, int *j)
{
	if (str[*j] >= '1' && str[*j] <= '9')
		s->flag = 1;
	if (s->flag == 0)
	{
		if (str[*j] == '-')
			s->minus = 1;
		if (str[*j] == '+')
			s->plus = 1;
		if (str[*j] == '0')
			s->zero = 1;
		if (str[*j] == '#')
			s->grid = 1;
		if (str[*j] == ' ')
			s->space = 1;
	}
	else
	{
		if (str[*j] == '-')
			s->minus = 1;
		if (str[*j] == '+')
			s->plus = 1;
	}
	(*j)++;
}

void	ft_easyflag(char *str, t_spec *s, int j)
{
	while (str[j] != '\0' && str[j] != '%' && str[j] != 'c' && str[j] != 's'
		&& str[j] != 'p' && str[j] != 'd' && str[j] != 'i' && str[j] != 'o'
		&& str[j] != 'u' && str[j] != 'x' && str[j] != 'X' && str[j] != 'f'
		&& str[j] != '\n' && str[j] != '\t' && str[j] != '\v')
		ft_easyflag1(str, s, &j);
	s->flag = 0;
	if (s->minus == 0 && s->plus == 0 && s->zero == 0 && s->grid == 0
		&& s->space == 0)
		s->allflagzero = 1;
}

int		ft_biggeraccornum(t_spec *s)
{
	if (ft_strlen(s->buf) < s->acc)
		return (s->acc);
	return (ft_strlen(s->buf));
}

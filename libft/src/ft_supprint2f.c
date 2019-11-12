/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supprint2f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 12:45:28 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/09 12:58:23 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lengthafterpoint(t_spec *s)
{
	while (s->buf[s->j] != '.' && s->buf[s->j] != '\0')
		s->j++;
	s->strl_b = s->j + 1;
	if (s->buf[s->j] == '.')
	{
		s->j++;
		while (s->buf[s->j] != '\0')
		{
			s->strl_p++;
			s->j++;
		}
	}
	s->j = 0;
}

void	ft_supround1(char *dest, int *j, t_spec *s, int *temp)
{
	while (s->buf[*temp] == '9')
	{
		dest[(*j)--] = 48;
		(*temp)--;
	}
	if (s->buf[*temp] == '.')
	{
		(*temp)--;
		(*j)--;
	}
	while (s->buf[*temp] == '9')
	{
		dest[(*j)--] = 48;
		(*temp)--;
	}
	if ((*j) != s->z)
		dest[(*j)] = s->buf[*temp] + 1;
	else
		dest[(*j)] = '1';
}

void	ft_checkrounding(char *dest, int *j, t_spec *s)
{
	if (dest[s->z] == '\0')
	{
		while (s->z < (*j))
		{
			dest[s->z] = dest[s->z + 1];
			s->z++;
		}
		if (s->grid == 1 && s->acc == -1)
			dest[s->z++] = '.';
		dest[s->z] = '\0';
	}
	else if (s->grid == 1 && s->acc == -1)
	{
		s->z++;
		dest[s->z++] = '.';
		dest[s->z] = '\0';
	}
	else
		dest[(*j) + 1] = '\0';
}

void	ft_strjcpy6(char *dest, t_spec *s, int *j, int six)
{
	s->z = *j;
	(*j)++;
	while (s->buf[s->j] && s->buf[s->j] != '.')
		dest[(*j)++] = s->buf[s->j++];
	if (s->buf[s->j] == '.')
	{
		dest[(*j)++] = s->buf[s->j++];
		while (six > 1 && s->buf[s->j] != '\0')
		{
			dest[(*j)++] = s->buf[s->j++];
			six--;
		}
		if (six > 1)
		{
			while (six-- > 0)
				dest[(*j)++] = '0';
			(*j)--;
		}
		else
			ft_rounding(dest, j, s);
	}
	ft_checkrounding(dest, j, s);
}

void	ft_fp2(t_ran *ran, t_spec *s)
{
	if (s->pmz == -1)
		ran->buf[ran->j++] = '-';
	else if (s->plus)
		ran->buf[ran->j++] = '+';
	else if (s->space == 1)
		ran->buf[ran->j++] = ' ';
	ft_strjcpy6(ran->buf, s, &ran->j, 6);
	while (s->strl_b + 7 < s->width--)
		ran->buf[ran->j++] = ' ';
}

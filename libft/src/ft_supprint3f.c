/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supprint3f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:03:45 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/09 13:04:15 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_supround2(char *dest, int *j, t_spec *s, int *i)
{
	if (dest[(*j) - 2] == '9')
	{
		(*i) += 1;
		while (dest[(*j) - 2] == '9')
		{
			dest[(*j) - 2] = 48;
			(*j)--;
		}
		if ((*j) - 2 != s->z)
			dest[(*j) - 2] = dest[(*j) - 2] + 1;
		else
			dest[(*j) - 2] = '1';
	}
	else
		dest[(*j) - 2] += 1;
}

void	ft_supround3(char *dest, int *j, t_spec *s, int *i)
{
	s->j += 1;
	while (s->buf[s->j] == '0' && s->buf[s->j] != '\0')
		s->j++;
	if (s->buf[s->j] != '\0' || (dest[(*j) - 2] - 48) % 2 != 0)
	{
		if (dest[(*j) - 2] == '9')
		{
			if (dest[(*j) - 2] == '9')
			{
				(*i) += 1;
				while (dest[(*j) - 2] == '9')
				{
					dest[(*j) - 2] = 48;
					(*j)--;
				}
				if ((*j) - 2 != s->z)
					dest[(*j) - 2] = dest[(*j) - 2] + 1;
				else
					dest[(*j) - 2] = '1';
			}
		}
		else
			dest[(*j) - 2] += 1;
	}
}

void	ft_supround4(char *dest, int *j, t_spec *s, int *temp)
{
	s->j += 2;
	while (s->buf[s->j] == '0' && s->buf[s->j] != '\0')
		s->j++;
	if (s->buf[s->j] != '\0' || s->buf[s->j] != '9')
	{
		if (s->buf[*temp] != '9')
			dest[(*j)] = s->buf[*temp] + 1;
		else
			ft_supround1(dest, j, s, temp);
	}
	else
	{
		if ((s->buf[s->j] - 48) % 2 == 0)
			dest[(*j)] = s->buf[s->j];
	}
}

int		ft_supacc23(char *dest, int *j, t_spec *s, int *i)
{
	if (s->buf[s->j] >= '6' && s->buf[s->j] <= '9')
		ft_supround2(dest, j, s, i);
	else if (s->buf[s->j] == '5')
		ft_supround3(dest, j, s, i);
	*j = *i;
	dest[(*j)--] = '\0';
	dest[(*j)--] = '\0';
	return (1);
}

void	ft_rounding(char *dest, int *j, t_spec *s)
{
	int i;
	int temp;

	i = (*j);
	temp = s->j;
	if (s->acc == -1 && ft_supacc23(dest, j, s, &i) == 1)
		return ;
	else if ((s->buf[s->j + 1] <= '4' && s->buf[s->j + 1] >= '0')
		|| s->buf[s->j + 1] == '\0')
		dest[(*j)] = s->buf[s->j];
	else if (s->buf[s->j + 1] == '5')
		ft_supround4(dest, j, s, &temp);
	else if (s->buf[s->j + 1] >= '6' && s->buf[s->j + 1] <= '9')
	{
		if (s->buf[s->j] >= '0' && s->buf[s->j] < '9')
			dest[(*j)] = s->buf[s->j] + 1;
		else if (s->buf[s->j] == '9')
			ft_supround1(dest, j, s, &temp);
	}
	*j = i;
}

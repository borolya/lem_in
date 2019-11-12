/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:00:36 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/02 14:15:33 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	space_free(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'
							|| str[i] == '\r' || str[i] == '\n'
							|| str[i] == '\v' || str[i] == '\f'))
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int				i;
	long long int	res;
	long long int	sg;
	int				start;

	res = 0;
	start = space_free(str);
	i = start;
	sg = 1;
	while (str[i] != '\0' && ((str[i] >= '0' && str[i] <= '9') ||
							(i == start && (str[i] == '-' || str[i] == '+'))))
	{
		if (str[i] == '-')
			sg = -1;
		if (str[i] >= '0' && str[i] <= '9')
		{
			if ((((res * 10) + sg * (str[i] - 48)
				- sg * (str[i] - 48)) / 10) != res)
				return (sg == 1 ? -1 : 0);
			else
				res = (res * 10) + sg * (str[i] - 48);
		}
		++i;
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:09:51 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/03 13:16:32 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_atoizero(char *s)
{
	if ((s[1] != '\0') && (s[0] == '0'))
	{
		write(1, "Error\n", 6);
		exit(-1);
	}
	if ((s[1] == '\0') && (s[0] == '-'))
	{
		write(1, "Error\n", 6);
		exit(-1);
	}
}

static void		ft_atoisup(long n, int s, char c)
{
	if (n > 2147483647 || n * s < -2147483648 || (c - '0' < 0 || c - '0' > 9))
	{
		write(1, "Error\n", 6);
		exit(-1);
	}
}

int				ft_atoi(const char *s)
{
	long	n;
	int		sign;
	int		i;

	n = 0;
	sign = 1;
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\f')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i++] == '-')
			sign = -1;
	}
	ft_atoizero((char *)s);
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = (n * 10) + (s[i] - '0');
		ft_atoisup(n, sign, s[i]);
		i++;
	}
	if (s[i] != '\0')
		ft_atoisup(n, sign, s[i]);
	return ((int)(n * sign));
}

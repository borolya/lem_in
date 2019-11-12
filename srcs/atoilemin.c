/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoilemin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:18:41 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/05 21:31:16 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_atoisuplem(char *s, long n, char c, const char *str_error)
{
	if (n > 2147483647 || n < 1 || (c - '0' < 0 || c - '0' > 9))
		ft_lem_error(str_error, &s);
}

int				ft_atoilemin(char *s)
{
	long	n;
	int		i;

	n = 0;
	i = 0;
	if (s && *s)
	{
		if (s[i] == '+')
			i++;
		if (s[i] < '1' || s[i] > '9')
			ft_lem_error("Error! (atoilemin) = \0", &s);
		else
			n = s[i++] - '0';
		while (s[i] >= '0' && s[i] <= '9')
		{
			n = (n * 10) + (s[i] - '0');
			ft_atoisuplem((char *)s, n, s[i++], "Error! (atoilemin) = \0");
		}
		if (s[i] != '\0')
			ft_lem_error("Error! (atoilemin) = \0", &s);
		return ((int)n);
	}
	ft_lem_error("Error! (atoilemin) = \0", &s);
	return (0);
}

void			ft_atoicoor(char *s)
{
	long	n;
	int		i;

	n = 0;
	i = 0;
	if (s && *s)
	{
		if (s[i] == '+')
			i++;
		if (s[i] == '0' && !s[i + 1])
			return ;
		if (s[i] < '1' || s[i] > '9')
			ft_lem_error("Error! (coor_of_room) = \0", &s);
		else
			n = s[i++] - '0';
		while (s[i] >= '0' && s[i] <= '9')
		{
			n = (n * 10) + (s[i] - '0');
			ft_atoisuplem((char *)s, n, s[i++], "Error! (coor_of_room) = ");
		}
		if (s[i] != '\0')
			ft_lem_error("Error! (coor_of_room) = \0", &s);
		return ;
	}
	ft_lem_error("Error! (coor_of_room) = \0", &s);
}

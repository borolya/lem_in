/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:56:22 by bharmund          #+#    #+#             */
/*   Updated: 2019/10/02 20:56:23 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			check_link(char *str)
{
	int i;
	int tmp;

	i = 0;
	while (str[i] && str[i] != '-' && str[i] != ' ')
		i++;
	if (i < 1 || str[i] != '-')
		return (0);
	i++;
	tmp = 0;
	while (str[i] && str[i] != ' ')
	{
		i++;
		tmp++;
	}
	if (i < 1 && str[i] != '\0')
		return (0);
	return (1);
}

static int	check_num(char *str, int *i)
{
	int tmp;

	tmp = 0;
	while (str[*i] != '\0' && str[*i] != ' ')
	{
		if (str[*i] > '9' || str[*i] < '0')
			return (0);
		tmp++;
		(*i)++;
	}
	if (tmp < 1)
		return (0);
	return (1);
}

int			check_room(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	if (i < 1 || str[i] == '\0')
		return (0);
	i++;
	if (check_num(str, &i) == 0 || str[i] == '\0')
		return (0);
	i++;
	if (check_num(str, &i) == 0 || str[i] != '\0')
		return (0);
	return (1);
}

int			check_comment(char *str)
{
	if (str[0] == '#' && ft_strequ(str, "##start") == 0
					&& ft_strequ(str, "##end") == 0)
		return (1);
	return (0);
}

int			check_command(char *str)
{
	if (ft_strequ(str, "##start") || ft_strequ(str, "##end"))
		return (1);
	return (0);
}

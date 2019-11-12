/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 12:49:11 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/05 15:26:41 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_lem_error(const char *err, char **line)
{
	ft_putstr_fd(err, 2);
	ft_putstr_fd(*line, 2);
	ft_putchar_fd('\n', 2);
	exit(-1);
}

void	ft_linkserror(void)
{
	ft_putstr_fd("INPUT ERROR(LINKS)!\n", 2);
	exit(-1);
}

void	ft_cant_find_way_error(void)
{
	ft_putstr_fd("ERROR. No way to solve this map!\n", 2);
	exit(-1);
}

void	ft_input_error(void)
{
	ft_putstr_fd("INPUT ERROR!\n", 2);
	exit(-1);
}

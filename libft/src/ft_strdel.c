/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:12:15 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/11 15:40:51 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel(char **as)
{
	if (!as || !*as)
		return ;
	free(*as);
	*as = NULL;
}

int		ft_strdel_return(char **as)
{
	if (!as || !*as)
		return (1);
	free(*as);
	*as = NULL;
	return (0);
}

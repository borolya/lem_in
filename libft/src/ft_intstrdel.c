/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intstrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:23:37 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/08 13:27:13 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_intstrdel(int **as)
{
	if (as)
	{
		if (*as != NULL)
		{
			free(*as);
			*as = NULL;
		}
	}
}

static int		ft_intstrdel_return(int **as)
{
	if (as)
	{
		if (*as != NULL)
		{
			free(*as);
			*as = NULL;
			return (0);
		}
		return (1);
	}
	return (1);
}

void			ft_intstr2del(int ***as, int quantity)
{
	int i;

	i = 0;
	if (as != NULL && *as != NULL)
	{
		while (i < quantity && (*as)[i] != NULL)
		{
			if (ft_intstrdel_return(&((*as)[i])) == 1)
				break ;
			i++;
		}
		free(*as);
		*as = NULL;
	}
}

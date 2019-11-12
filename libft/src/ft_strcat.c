/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:11:03 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/02 12:24:28 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int		i;
	size_t	end_of_s1;

	i = 0;
	end_of_s1 = ft_strlen(s1);
	while (s2[i] != '\0')
	{
		s1[end_of_s1] = s2[i];
		end_of_s1++;
		i++;
	}
	s1[end_of_s1] = '\0';
	return (s1);
}

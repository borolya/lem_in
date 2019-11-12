/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:11:22 by crenly-b          #+#    #+#             */
/*   Updated: 2019/02/09 16:40:52 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t	i;
	int		length_s1;

	i = 0;
	length_s1 = ft_strlen(s1);
	while (i < n && s2[i] != '\0')
	{
		s1[length_s1] = s2[i];
		length_s1++;
		i++;
	}
	s1[length_s1] = '\0';
	return (s1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:11:16 by crenly-b          #+#    #+#             */
/*   Updated: 2019/02/19 13:22:31 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *restrict dst, const char *restrict src,
	size_t size)
{
	size_t	len_dst;
	size_t	i;

	len_dst = 0;
	i = 0;
	while (dst[len_dst] != '\0' && len_dst < size)
	{
		len_dst++;
	}
	if (len_dst == size)
	{
		return (len_dst + ft_strlen(src));
	}
	while (src[i] != '\0' && (len_dst + i) < (size - 1))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + ft_strlen(src));
}

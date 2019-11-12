/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:10:45 by crenly-b          #+#    #+#             */
/*   Updated: 2019/02/20 10:29:32 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
	size_t n)
{
	unsigned char	*str_src;
	unsigned char	*str_dst;
	size_t			i;

	str_src = (unsigned char *)src;
	str_dst = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		*str_dst = str_src[i];
		str_dst++;
		if (str_src[i] == (unsigned char)c)
		{
			return ((void *)str_dst);
		}
		i++;
	}
	return (NULL);
}

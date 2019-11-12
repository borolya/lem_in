/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:10:58 by crenly-b          #+#    #+#             */
/*   Updated: 2019/02/20 10:33:30 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*str_src;
	char		*str_dst;
	size_t		i;

	str_src = src;
	str_dst = dst;
	i = (int)len - 1;
	if (str_dst > str_src)
	{
		while ((int)i >= 0)
		{
			str_dst[i] = str_src[i];
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:10:53 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/09 20:37:10 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t		i;
	const char	*str_src;
	char		*str_dst;

	i = 0;
	str_src = src;
	str_dst = dst;
	while (i < n)
	{
		str_dst[i] = str_src[i];
		i++;
	}
	return (dst);
}

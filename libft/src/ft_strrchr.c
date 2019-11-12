/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:11:32 by crenly-b          #+#    #+#             */
/*   Updated: 2019/01/24 03:21:01 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		len_s;

	len_s = ft_strlen(s);
	p = (char *)s + len_s - 1;
	if (c == '\0')
	{
		return (++p);
	}
	while (len_s != 0)
	{
		if (*p == (char)c)
		{
			return (p);
		}
		len_s--;
		p--;
	}
	return (NULL);
}

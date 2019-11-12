/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:12:37 by crenly-b          #+#    #+#             */
/*   Updated: 2019/02/19 13:48:05 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	i;

	i = 0;
	if (s)
	{
		fresh = ft_strnew(len);
		if (fresh)
		{
			while (i < len && s[start] != '\0')
			{
				fresh[i++] = (char)s[start++];
			}
			fresh[i] = '\0';
			return (fresh);
		}
	}
	return (NULL);
}

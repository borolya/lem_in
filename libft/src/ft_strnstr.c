/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:11:29 by crenly-b          #+#    #+#             */
/*   Updated: 2019/02/16 20:48:24 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	char	*hs;
	char	*ne;

	hs = (char *)haystack;
	ne = (char *)needle;
	i = 0;
	if (needle[i] == '\0')
		return (hs);
	if (ft_strlen(ne) > ft_strlen(hs) || ft_strlen(ne) > len || len == 0)
		return (NULL);
	while ((size_t)i <= (len - ft_strlen(ne)))
	{
		j = 0;
		while (hs[i + j] == ne[j])
		{
			if (ne[j + 1] == '\0' || ne[j] == '\0')
				return (hs + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

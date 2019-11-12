/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:11:34 by crenly-b          #+#    #+#             */
/*   Updated: 2019/02/16 20:46:49 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*hs;
	char	*ne;

	hs = (char *)haystack;
	ne = (char *)needle;
	i = 0;
	j = 0;
	if (ne[i] == '\0')
		return (hs);
	while (hs[i])
	{
		while (hs[i + j] == ne[j])
		{
			if (ne[j + 1] == '\0')
				return (hs + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}

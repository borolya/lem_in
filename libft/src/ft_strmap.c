/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:12:26 by crenly-b          #+#    #+#             */
/*   Updated: 2019/02/09 16:01:48 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	int		i;

	if (f && s)
	{
		fresh = (char *)malloc(sizeof(*fresh) * (ft_strlen(s) + 1));
		if (fresh)
		{
			i = 0;
			while (s[i] != '\0')
			{
				fresh[i] = (*f)(s[i]);
				i++;
			}
			fresh[i] = '\0';
			return (fresh);
		}
	}
	return (NULL);
}

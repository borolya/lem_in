/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:12:29 by crenly-b          #+#    #+#             */
/*   Updated: 2019/02/09 16:02:48 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*fresh;

	if (f && s)
	{
		fresh = (char *)malloc(sizeof(*fresh) * (ft_strlen(s) + 1));
		if (fresh)
		{
			i = 0;
			while (s[i] != '\0')
			{
				fresh[i] = f(i, s[i]);
				i++;
			}
			fresh[i] = '\0';
			return (fresh);
		}
	}
	return (NULL);
}

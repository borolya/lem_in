/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:12:23 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/04 17:56:20 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;

	i = 0;
	if (s1 && s2)
	{
		s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (s3)
		{
			while (*s1)
			{
				s3[i++] = *s1;
				s1++;
			}
			while (*s2)
			{
				s3[i++] = *s2;
				s2++;
			}
			s3[i] = '\0';
			return (s3);
		}
	}
	return (NULL);
}

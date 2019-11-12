/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:11:13 by crenly-b          #+#    #+#             */
/*   Updated: 2019/02/09 15:56:55 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str1;
	int		s1_length;

	s1_length = ft_strlen(s1);
	str1 = (char *)malloc(sizeof(*s1) * (s1_length + 1));
	if (str1)
	{
		ft_strcpy(str1, s1);
		return (str1);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:12:40 by crenly-b          #+#    #+#             */
/*   Updated: 2019/03/11 18:20:54 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	begin_of_s(char const *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

static int	end_of_s(char const *s)
{
	int i;

	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		new_len;
	char	*fresh_s;

	if (s)
	{
		new_len = end_of_s(s) - begin_of_s(s) + 1;
		if (new_len <= 0)
			return (ft_strnew(1));
		fresh_s = ft_strsub(s, begin_of_s(s), new_len);
		if (fresh_s)
			return (fresh_s);
	}
	return (NULL);
}

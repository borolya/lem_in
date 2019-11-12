/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:11:47 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/30 15:33:01 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fill_in_2(char *fresh_str)
{
	int i;
	int length;
	int n;

	n = 2147483647;
	length = 10;
	fresh_str[0] = '-';
	i = 1;
	while (length != 1)
	{
		fresh_str[i++] = find_ch(n, length) + '0';
		length--;
	}
	fresh_str[i] = n % 10 + '1';
	return (fresh_str);
}

char	*fill_in_1(char *fresh_str, int n)
{
	int i;
	int length;

	i = 1;
	length = length_int(n) - 1;
	fresh_str[0] = '-';
	n = n * (-1);
	while (length != 0)
	{
		fresh_str[i++] = find_ch(n, length) + '0';
		length--;
	}
	return (fresh_str);
}

char	*fill_in_0(char *fresh_str, int n)
{
	int i;
	int length;

	i = 0;
	length = length_int(n);
	while (length != 0)
	{
		fresh_str[i++] = find_ch(n, length) + '0';
		length--;
	}
	return (fresh_str);
}

char	*ft_itoa(int n)
{
	char *fresh_str;

	if (super_check(n) == 2)
	{
		fresh_str = ft_strnew(11);
		if (fresh_str)
			return (fill_in_2(fresh_str));
	}
	if (super_check(n) == 1)
	{
		fresh_str = ft_strnew(length_int(n));
		if (fresh_str)
			return (fill_in_1(fresh_str, n));
	}
	fresh_str = ft_strnew(length_int(n));
	if (fresh_str)
		return (fill_in_0(fresh_str, n));
	return (NULL);
}

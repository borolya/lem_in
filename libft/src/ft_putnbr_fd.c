/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 22:12:05 by crenly-b          #+#    #+#             */
/*   Updated: 2019/02/16 21:07:52 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int i;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n >= 0)
		i = n;
	else
	{
		i = (-1) * n;
		ft_putchar_fd('-', fd);
	}
	if (i > 9)
		ft_putnbr_fd(i / 10, fd);
	ft_putchar_fd((i % 10) + '0', fd);
}

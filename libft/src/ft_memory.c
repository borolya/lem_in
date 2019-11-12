/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 21:29:58 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/05 15:52:25 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strdelp(char **as)
{
	if (!as || !(*as))
		return ;
	free(*as);
	*as = NULL;
}

char	*ft_strduppr(const char *s)
{
	char	*str;
	int		len;

	len = 0;
	while (s[len] != '\0')
		len++;
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	len = 0;
	while (s[len] != '\0')
	{
		str[len] = s[len];
		len++;
	}
	str[len] = '\0';
	return (str);
}

void	ft_reworkbuf(t_spec *s)
{
	if (s->buf)
		ft_strdelp(&s->buf);
	if (!(s->buf = (char *)malloc(sizeof(char) * 10001)))
		exit(-1);
	ft_bzerop(s->buf, 10001);
}

void	ft_newstruct(t_spec *s)
{
	s->i = 0;
	s->j = 0;
	s->z = 0;
	s->space = 0;
	s->flag = 0;
	s->zero = 0;
	s->minus = 0;
	s->plus = 0;
	s->grid = 0;
	s->pmz = 0;
	s->width = 0;
	s->acc = 0;
	s->allflagzero = 0;
	s->strl = 0;
	s->strl_b = 0;
	s->strl_p = 0;
	if (!(s->buf = (char *)malloc(sizeof(char) * 10001)))
		exit(-1);
	ft_bzerop(s->buf, 10001);
}

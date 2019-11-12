/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_record2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 00:40:06 by crenly-b          #+#    #+#             */
/*   Updated: 2019/07/14 17:46:44 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_x_record(t_ran *ran, va_list *vl, t_spec *s)
{
	unsigned long long int	num;
	int						sl;

	sl = 32;
	num = va_arg(*vl, unsigned long long int);
	if (s->flag == 0)
		ft_xui(s, ran, num, sl);
	else if (s->flag == 1)
		ft_xusi(s, ran, num, sl);
	else if (s->flag == 2)
		ft_xucc(s, ran, num, sl);
	else if (s->flag == 3 || s->flag == 5)
		ft_xuli(s, ran, num, sl);
	else if (s->flag == 4)
		ft_xulli(s, ran, num, sl);
}

void	ft_xbig_record(t_ran *ran, va_list *vl, t_spec *s)
{
	unsigned long long int	num;
	int						bl;

	bl = 0;
	num = va_arg(*vl, unsigned long long int);
	if (s->flag == 0)
		ft_xui(s, ran, num, bl);
	else if (s->flag == 1)
		ft_xusi(s, ran, num, bl);
	else if (s->flag == 2)
		ft_xucc(s, ran, num, bl);
	else if (s->flag == 3 || s->flag == 5)
		ft_xuli(s, ran, num, bl);
	else if (s->flag == 4)
		ft_xulli(s, ran, num, bl);
}

void	ft_o_record(t_ran *ran, va_list *vl, t_spec *s)
{
	unsigned long long int	num;

	s->i = 0;
	s->j = 0;
	num = va_arg(*vl, unsigned long long int);
	if (ft_oexeption2(ran, s, &num) == 1)
		return ;
	if (s->flag == 0)
		ft_oi(s, ran, (int)num);
	else if (s->flag == 1)
		ft_osi(s, ran, (short int)num);
	else if (s->flag == 2)
		ft_oc(s, ran, (char)num);
	else if (s->flag == 3)
		ft_oli(s, ran, (long int)num);
	else
		ft_olli(s, ran, (long long int)num);
}

void	ft_u_record(t_ran *ran, va_list *vl, t_spec *s)
{
	unsigned long long int	num;

	s->i = 0;
	s->j = 0;
	s->space = 0;
	s->grid = 0;
	s->plus = 0;
	num = va_arg(*vl, unsigned long long int);
	if (ft_uexeption1(ran, s, &num))
		return ;
	else if (s->flag == 0)
		ft_ui(s, ran, (unsigned int)num);
	else if (s->flag == 1)
		ft_usi(s, ran, (unsigned short int)num);
	else if (s->flag == 2)
		ft_uc(s, ran, (unsigned char)num);
	else if (s->flag == 3)
		ft_uli(s, ran, (unsigned long int)num);
	else
		ft_ulli(s, ran, (unsigned long long int)num);
}

void	ft_f_record(t_ran *ran, va_list *vl, t_spec *s)
{
	double			a;
	unsigned long	*b;

	if (ft_flag2(ran, vl, s, &a) == 1)
		return ;
	if (s->flag != 2)
		a = (double)va_arg(*vl, double);
	b = (unsigned long*)&a;
	if (*b == 0)
		ft_fexepzero(s);
	else if (*b == (922337203685477580.8 * 10))
	{
		s->buf[s->j++] = '-';
		ft_fexepzero(s);
	}
	ft_convert_f(ran, s, b);
}

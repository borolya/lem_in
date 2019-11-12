/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 11:50:19 by crenly-b          #+#    #+#             */
/*   Updated: 2019/09/05 15:53:13 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <float.h>
# include <stdint.h>

typedef struct	s_spec
{
	char		*buf;
	int			flag;
	int			space;
	int			zero;
	int			minus;
	int			plus;
	int			grid;
	int			pmz;
	int			width;
	int			acc;
	int			allflagzero;
	int			i;
	int			j;
	int			z;
	int			strl;
	int			strl_b;
	int			strl_p;
	long double	h;
}				t_spec;

typedef struct	s_f
{
	unsigned long	mantisa;
	unsigned long	exponenta;
	long			num;
	long			temp;
	long			expif;
	int				count;
	int				point;
}				t_f;

typedef struct	s_ran
{
	int		i;
	int		j;
	int		bs;
	char	conver;
	int		ret;
	char	*buf;
	int		fzero;
	int		strlen;
}				t_ran;

int				ft_printf(const char *restrict format, ...);
void			ft_recconver(char *str, t_ran *ran, va_list *vl, t_spec *s);
int				ft_flagsup(char *str, t_ran *ran, t_spec *s);
void			ft_p_record(char *str, t_ran *ran, t_spec *s);
void			ft_c_record(t_ran *ran, va_list *vl, t_spec *s);
void			ft_s_record(t_ran *ran, va_list *vl, t_spec *s);
void			ft_bufjoin_s(t_ran *ran, t_spec *s);
void			ft_sprint1(t_ran *ran, t_spec *s);
void			ft_sprint2(t_ran *ran, t_spec *s);
void			ft_sprint2_1(t_ran *ran, t_spec *s);
void			ft_sprint3(t_ran *ran, t_spec *s);
void			ft_sprint4(t_ran *ran, t_spec *s);
void			ft_sprint4_1(t_ran *ran, t_spec *s);
void			ft_sprint4_2(t_ran *ran, t_spec *s);
void			ft_sprint4_3(t_ran *ran, t_spec *s);
void			ft_adr_record(t_ran *ran, va_list *vl, t_spec *s);
void			ft_supoctalsminus(t_spec *s, t_ran *ran);
void			ft_adrxuli(t_spec *s, t_ran *ran, unsigned long long int num,
		int sm);
void			ft_supadr1(t_spec *s, t_ran *ran, unsigned long long int num);
void			ft_supzerox(t_spec *s, t_ran *ran);
void			ft_sup0x(t_spec *s, t_ran *ran);
void			ft_d_record(t_ran *ran, va_list *vl, t_spec *s);
void			ft_dsupzero(t_ran *ran, t_spec *s);
void			ft_di(t_spec *spec, t_ran *ran, int num);
void			ft_diexeption(t_spec *s, int *num);
void			ft_dsi(t_spec *spec, t_ran *ran, short int num);
void			ft_dsiexeption(t_spec *s, short int *num);
void			ft_dc(t_spec *spec, t_ran *ran, char num);
void			ft_dcexeption(t_spec *s, char *num);
void			ft_dli(t_spec *spec, t_ran *ran, long int num);
void			ft_dliexeption(t_spec *s, long int *num);
void			ft_dlli(t_spec *spec, t_ran *ran, long long int num);
void			ft_dllexeption(t_spec *s, long long int *num);
void			ft_bufjoin_d(t_ran *ran, t_spec *s);
void			ft_dznak1(t_ran *ran, t_spec *s);
void			ft_dznak2(t_spec *s);
void			ft_dznak3(t_ran *ran, t_spec *s);
void			ft_dznak4(t_ran *ran, t_spec *s);
void			ft_dznak5(t_ran *ran, t_spec *s);
void			ft_dprint1(t_ran *ran, t_spec *s);
void			ft_dprint2(t_ran *ran, t_spec *s);
void			ft_dprint3(t_ran *ran, t_spec *s);
void			ft_dprint4(t_ran *ran, t_spec *s);
void			ft_dp2_1(t_ran *ran, t_spec *s);
void			ft_dp2_11(t_ran *ran, t_spec *s);
void			ft_dp2_2(t_ran *ran, t_spec *s);
void			ft_dp2_21(t_ran *ran, t_spec *s);
void			ft_dp2_3(t_ran *ran, t_spec *s);
void			ft_dp4_1(t_ran *ran, t_spec *s);
void			ft_dp4_2(t_ran *ran, t_spec *s);
void			ft_dp4_3(t_ran *ran, t_spec *s);
void			ft_dphelp4_3(t_ran *ran, t_spec *s);
void			ft_dp4_4(t_ran *ran, t_spec *s);
void			ft_dp4_5(t_ran *ran, t_spec *s);
void			ft_dphelp4_5(t_ran *ran, t_spec *s);
void			ft_o_record(t_ran *ran, va_list *vl, t_spec *s);
void			ft_oi(t_spec *s, t_ran *ran, unsigned int num);
void			ft_osi(t_spec *s, t_ran *ran, unsigned short int num);
void			ft_oc(t_spec *s, t_ran *ran, unsigned char num);
void			ft_oli(t_spec *s, t_ran *ran, unsigned long int num);
void			ft_olli(t_spec *s, t_ran *ran, unsigned long long int num);
int				ft_o_checkzero2(t_ran *ran, t_spec *s);
int				ft_o_checkzerohelp2(t_ran *ran, t_spec *s);
int				ft_o_checkzero3(t_ran *ran, t_spec *s);
int				ft_o_checkzero4(t_ran *ran, t_spec *s);
int				ft_o_checkwa1(t_ran *ran, t_spec *s);
void			ft_supoctalsminus(t_spec *s, t_ran *ran);
int				ft_oexeption2(t_ran *ran, t_spec *s,
		unsigned long long int *num);
int				ft_odp2_2check(t_ran *ran, t_spec *s);
void			ft_u_record(t_ran *ran, va_list *vl, t_spec *s);
void			ft_ui(t_spec *s, t_ran *ran, unsigned int num);
void			ft_usi(t_spec *s, t_ran *ran, unsigned short int num);
void			ft_uc(t_spec *s, t_ran *ran, unsigned char num);
void			ft_uli(t_spec *s, t_ran *ran, unsigned long int num);
void			ft_ulli(t_spec *s, t_ran *ran, unsigned long long int num);
int				ft_uexeption1(t_ran *ran, t_spec *s,
		unsigned long long int *num);
void			ft_f_record(t_ran *ran, va_list *vl, t_spec *s);
void			ft_flagf(char *str, t_ran *ran, t_spec *s);
void			ft_convert_f(t_ran *ran, t_spec *s, unsigned long *b);
void			ft_multinstr5(char *str, int *i);
void			ft_multinstr2(char *str, int *i);
int				ft_flag2(t_ran *ran, va_list *vl, t_spec *s, double *a);
void			ft_fexepbig1(t_ran *ran, t_spec *s);
void			ft_fexepbig2(t_ran *ran, t_spec *s);
void			ft_fexepzero(t_spec *s);
void			ft_parse_zem(t_f *f, unsigned long *b, t_spec *s);
void			ft_ne1(t_f *f, t_spec *s);
void			ft_ne2(t_f *f, t_spec *s);
void			ft_ne3(t_f *f, t_spec *s);
void			ft_bufjoin_f(t_ran *ran, t_spec *s);
void			ft_strjcpy6(char *dest, t_spec *s, int *j, int six);
void			ft_lengthafterpoint(t_spec *s);
void			ft_rounding(char *dest, int *j, t_spec *s);
void			ft_suproud1(char *dest, int *j, t_spec *s, int *temp);
void			ft_checkrounding(char *dest, int *j, t_spec *s);
void			ft_fp2(t_ran *ran, t_spec *s);
void			ft_supround1(char *dest, int *j, t_spec *s, int *temp);
void			ft_supround2(char *dest, int *j, t_spec *s, int *i);
void			ft_supround3(char *dest, int *j, t_spec *s, int *i);
void			ft_supround4(char *dest, int *j, t_spec *s, int *temp);
int				ft_supacc23(char *dest, int *j, t_spec *s, int *i);
void			ft_fp1234minus_plus_space(t_ran *ran, t_spec *s);
void			ft_fp4zero(t_ran *ran, t_spec *s);
void			ft_fp4_1(t_ran *ran, t_spec *s);
int				ft_fp4accminus(t_ran *ran, t_spec *s);
void			ft_fp4_2(t_ran *ran, t_spec *s);
void			ft_fp4_3(t_ran *ran, t_spec *s);
void			ft_fp4_32(t_ran *ran, t_spec *s);
void			ft_fp4_4(t_ran *ran, t_spec *s);
void			ft_fp4_5(t_ran *ran, t_spec *s);
void			ft_x_record(t_ran *ran, va_list *vl, t_spec *s);
void			ft_xbig_record(t_ran *ran, va_list *vl, t_spec *s);
void			ft_xui(t_spec *s, t_ran *ran, unsigned long long int num,
		int sm);
void			ft_xusi(t_spec *s, t_ran *ran, unsigned long long int num,
		int sm);
void			ft_xucc(t_spec *s, t_ran *ran, unsigned long long int num,
		int sm);
void			ft_xuli(t_spec *s, t_ran *ran, unsigned long long int num,
		int sm);
void			ft_xulli(t_spec *s, t_ran *ran, unsigned long long int num,
		int sm);
void			ft_bufjoin_x(t_ran *ran, t_spec *s);
void			ft_print1(t_ran *ran, t_spec *s);
void			ft_print2(t_ran *ran, t_spec *s);
void			ft_print2_1(t_ran *ran, t_spec *s);
void			ft_print3(t_ran *ran, t_spec *s);
void			ft_print4(t_ran *ran, t_spec *s);
void			ft_print4_1(t_ran *ran, t_spec *s);
void			ft_print4_2(t_ran *ran, t_spec *s);
void			ft_print4_3(t_ran *ran, t_spec *s);
void			ft_print4_4(t_ran *ran, t_spec *s);
void			ft_print4_5(t_ran *ran, t_spec *s);
void			ft_print4_6(t_ran *ran, t_spec *s);
void			ft_print4grid(t_ran *ran, t_spec *s);
void			ft_checkgrid(t_ran *ran, t_spec *s);
void			ft_checkgridplus2(t_ran *ran, t_spec *s);
int				ft_biggeraccornum(t_spec *s);
int				ft_strlen(char *str);
void			ft_newstruct(t_spec *s);
void			ft_findflags(char *str, t_ran *ran, t_spec *s);
char			*ft_strduppr(const char *s);
int				ft_atoi(const char *str);
void			ft_strjcpy(char *dest, t_spec *s, int *j);
void			ft_easyflag(char *str, t_spec *s, int j);
void			*extend_buf(t_ran *ran);
void			ft_putchar(char c);
void			ft_putstrp(char *str, t_ran ran, int *i);
void			ft_bzerop(void *s, size_t size);
void			ft_strdelp(char **as);
void			ft_reworkbuf(t_spec *s);

#endif

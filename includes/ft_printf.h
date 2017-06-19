/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:26:29 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/13 06:26:35 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <wchar.h>
# include "../libft/libft.h"

# define INTI 1
# define HEXA 2
# define HEXAM 3
# define CHAR 4
# define D_MOD 5
# define INTU 6
# define POINTER_ADRESSE 7
# define STR 8
# define INTLU 9
# define INTL 10
# define OCTAL 11
# define OCTALM 12
# define WCHAR 13
# define WSTR 14
# define HASH_TAG 2
# define POSITIVE 1
# define NEGATIVE 1
# define H_CAST 6
# define HH_CAST 7
# define J_CAST 8
# define Z_CAST 9
# define LONG_LONG 10
# define LONG 11

typedef struct			s_type
{
	short				type;
	unsigned int		unbr;
	long unsigned int	lunbr;
	long long			lnbr;
	int					number;
	unsigned long long	octal;
	unsigned long long	hexa;
	unsigned long		pointer;
	double				fnumber;
	char				*str;
	uintmax_t			c;
	wchar_t				*wstr;
	wchar_t				wc;
	int					pres_left;
	int					pres_right;
	short				no_pres_left;
	short				no_pres_right;
	int					spaces;
	short				hash_tag;
	short				plus;
	short				negative;
	short				cast;
	short				nopoint;
	short				point;
	short				cero;
}						t_type;

void					increase_one(int *a, int *b);
int						print_chars(t_type *temp);
int						ft_double_modulo_handler(t_type *temp);
int						ft_putoctalm(t_type *temp);
char					*ft_hexa_itoa(unsigned long long n);
int						printer(t_type *all);
int						option_handler(char *str, int i, t_type *temp);
int						precission_handler(char *str, int i, t_type *temp);
int						cast_handler(char *str, int i, t_type *temp);
int						set_presschar_forprev(t_type *temp, int total);
int						set_presschar_forp(t_type *temp, int total);




int						set_presschar(t_type *temp, int total);
int						print_number(t_type *temp);
int						set_presschar_for_long(t_type *temp, int total);
int						set_presschar_for_long_inverse(t_type *temp,
		int total);
void					ft_printlongnbr(long long ll);
int						total_int(int t, int total);
int						cero_manager_int(t_type *temp, int total,
		int t, int i);

int						choose_for_long(t_type *temp, int total, long long t, int i);
int						total_long(long long t, int total);
int						set_presschar_for_int(t_type *temp, int total);
int						ft_putllnbr(t_type *temp);
void					cast_manager3(t_type *temp, int t);
int						cero_manager_int(t_type *temp, int total, int t, int i);
int						set_presschar_for_int_inverse(t_type *temp, int total);
void					cast_manager3(t_type *temp, int t);

int						set_presschar_octal(t_type *temp, int total);
int						ft_puthexa(t_type *temp);
char					*ft_hexa_itoa_capital(unsigned long long n);
int						ft_putoctal(t_type *temp);
int						ft_putoctal3(t_type *temp, int i, int total, char *str);
int						ft_putoctal4(t_type *temp, char *str, int *i,
		int total);
void					ft_putunbr(unsigned long long unbr);

int						ft_putwchar(wchar_t wc);
int						ft_putwstr(t_type *temp, wchar_t *wstr, int everything,
		int i);
int						putwstr4(t_type *temp, wchar_t *str_temp, int evr,
		int total);
int						putwstr5(t_type *temp, wchar_t *wstr,
		wchar_t *str_temp, int evr);
int						putwstr6(int everything, wchar_t *str_temp);
int						parse_all(char *str, va_list args, int i,
		int everything);
void					parse_the_values3(va_list args, t_type *temp,
		char *str, int i);
void					parse_the_values4(va_list args, t_type *temp,
		char *str, int i);
int						parse_the_values2(va_list args, t_type *temp,
		char *str, int i);
int						ft_printf(char *format, ...);
int						print_unumber(t_type *temp);
int						print_lunumber(t_type *temp);
int						print_lnumber(t_type *temp);
int						adresse_printer(t_type *temp);


int						print_string(t_type *temp, int everything);
int						print_string6(int everything, char *str_temp);
int						print_string5(t_type *temp, int i, int everything);
int						print_string4(t_type *temp, int total, int evr);
int						ft_wstrlen(wchar_t *s);
wchar_t					*ft_wstrdup(wchar_t *s1);
wchar_t					*ft_wstrsub(wchar_t *s, int start, size_t len);
int						ft_wputstr(wchar_t *str);

int						cast_for_number(t_type *temp, int i, int total, int t);
int						ft_putchar_spe(char c);
int						set_presschar_for_int(t_type *temp, int total);
int						print_number_inverse(t_type *temp,
		long long t, int total);
void					reset_type(t_type *temp);
int						cero_manager_forptr(t_type *temp, int total);
int						smalldparser(va_list args, t_type *temp, int i);
int						capitaldparser(va_list args, t_type *temp, int i);
int						o_parser(va_list args, t_type *temp, char *str, int i);
#endif

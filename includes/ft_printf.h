/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_printf.h										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: myernaux <myernaux@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2017/05/21 10:11:11 by ocojeda-		  #+#	#+#			 */
/*   Updated: 2017/05/26 11:20:21 by myernaux		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <wchar.h>
# include "../libft/libft.h"
/*
*TYPE OF VARIABLE DEFINE
*/
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

/*
* OPTIONS DEFINE
*/
# define HASH_TAG 2 
# define CURRENCY 1
# define POSITIVE 1
# define NEGATIVE 1
/*
* FLAGS DEFINE
*/
# define LONG_LONG 2 
# define LONG 1
# define UNSIGNED 5
# define UNSIGNED_CHAR 3
# define UNSIGNED_SHORT_INT 4
# define H_CAST 6
# define HH_CAST 7
# define J_CAST 8
# define Z_CAST 9

typedef struct	  s_type
{
	short		   type;
	unsigned int	unbr;
	long unsigned int lunbr;
	long int		lnbr;
	long long			 number;
	unsigned long long	   octal;
	unsigned long long	   hexa;
	unsigned long		  pointer;
	double		  fnumber;
	char			str1[1000];
	char			*str;
	unsigned int			 c;
	wchar_t		 *wstr;
	wchar_t		 wc;
	
	int			 pres_left;
	int			 pres_right;
	short		   no_pres_left;
	short		   no_pres_right;
	int			 spaces;
	short		   hash_tag;
	short		   plus;
	short		   negative;
	short		   currency;
	short		   cast;
	short			nopoint;
	short			cero;
}				   t_type;

int	 print_chars(t_type *temp);
int	 ft_double_modulo_handler(t_type *temp);
int	ft_putoctalm(t_type *temp);
char		*ft_hexa_itoa(unsigned long long n);
int   printer(t_type *all);
int		 option_handler(char *str, int i, t_type *temp);
int	 precission_handler(char *str, int i, t_type *temp);
int	 cast_handler(char *str, int i, t_type *temp);
int	set_presschar_forprev(t_type *temp, int total);
int	set_presschar_forp(t_type *temp, int total);
int	set_presschar(t_type *temp, int total);
int	set_presschar_octal(t_type *temp, int total);
int		ft_puthexa(t_type *temp);
int		ft_putoctal(t_type *temp);
void		ft_putunbr(unsigned int unbr);
void		ft_putlnbr(long int lnbr);
int		ft_putwchar(wchar_t wc);
int     ft_putwstr(t_type *temp, wchar_t *wstr, int everything);
int	putwstr4(t_type *temp, wchar_t *str_temp, int everything, int total);
void	putwstr5(t_type *temp, wchar_t *wstr, wchar_t *str_temp, int i);
int 	putwstr6(int everything, wchar_t *str_temp);
int		parse_all(char *str, va_list args);
void   parse_the_values3(va_list args, t_type *temp, char *str, int i);
void   parse_the_values4(va_list args, t_type *temp, char *str, int i);
void  parse_the_values2(va_list args, t_type *temp, char *str, int i);
int		 ft_printf(char *format, ...);
int		print_number(t_type *temp);
int		print_unumber(t_type *temp);
int		print_lunumber(t_type *temp);
int		print_lnumber(t_type *temp);
int		adresse_printer(t_type *temp);
int		set_presschar_for_int(t_type *temp, int total);
int		set_presschar(t_type *temp, int total);
int	    print_string(t_type *temp, int everything);
int	 ft_wstrlen(wchar_t *s);
wchar_t	  *ft_wstrdup(wchar_t *s1);
wchar_t  *ft_wstrsub(wchar_t *s, int start, size_t len);
int	 ft_wputstr(wchar_t *str);

#endif
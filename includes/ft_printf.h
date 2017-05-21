/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 10:11:11 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/21 16:01:47 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
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

typedef struct      s_type
{
    int             pres_left;
    int             pres_right;
    short           no_pres_left;
    short           no_pres_right;
    unsigned int    unbr;
    long unsigned int lunbr;
    long int        lnbr;
    short           type;
    long long             number;
    unsigned long long       octal;
    unsigned long long       hexa;
    unsigned long          pointer;
    double          fnumber;
    char            *str;
    int             c;
    wchar_t         *wstr;
    wchar_t         wc;
    int             spaces;
    short           hash_tag;
    short           plus;
    short           negative;
    short           currency;
    short           cast;
    struct s_type   *next;
}                   t_type;

char        *ft_hexa_itoa(unsigned long long n);
int   printer(t_type *all);
int         option_handler(char *str, int i, t_type *temp);
int        ft_puthexa(t_type *temp);
int        ft_putoctal(t_type *temp);
void        ft_putunbr(unsigned int unbr);
void        ft_putlunbr(long unsigned int lunbr);
void        ft_putlnbr(long int lnbr);
int        ft_putwchar(wchar_t wc);
int        ft_putwstr(wchar_t *wstr);
t_type      *parse_all(char *str, va_list args, char *format);
int         ft_printf(char *format, ...);
int        print_number(t_type *temp);
int        print_unumber(t_type *temp);
int        print_lunumber(t_type *temp);
int        print_lnumber(t_type *temp);
int        adresse_printer(t_type *temp);
int        set_presschar_for_int(t_type *temp, int total);
int        set_presschar(t_type *temp, int total);

#endif
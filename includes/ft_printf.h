/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/18 00:23:49 by ocojeda-         ###   ########.fr       */
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
# define UNSIGNED_CHAR 3
# define UNSIGNED_SHORT_INT 4 

typedef struct      s_type
{
    int    pres_left;
    int    pres_right;
    unsigned int    unbr;
    long unsigned int lunbr;
    long int        lnbr;
    short           type;
    int             number;
    long long       octal;
    long long       hexa;
    void *          pointer;
    double          fnumber;
    char            *str;
    int             c;
    wchar_t         *wstr;
    wchar_t         wc;
    short           hash_tag;
    short           plus;
    short           negative;
    short           currency;
    short           cast;
    struct s_type   *next;
}                   t_type;

int   printer(t_type *all);
int         option_handler(char *str, int i, t_type *temp);
void        ft_puthexa(t_type *temp);
void        ft_putoctal(t_type *temp);
void        ft_putunbr(unsigned int unbr);
void        ft_putlunbr(long unsigned int lunbr);
void        ft_putlnbr(long int lnbr);
void        ft_putwchar(wchar_t wc);
void        ft_putwstr(wchar_t *wstr);
t_type      *parse_all(char *str, va_list args, char *format);
int         ft_printf(char *format, ...);
void        print_unumber(t_type *temp);
void        print_lunumber(t_type *temp);
void        print_lnumber(t_type *temp);
void        adresse_printer(t_type *temp);
void        set_presschar_for_int(t_type *temp, int total);
void        set_presschar(t_type *temp, int total);

#endif
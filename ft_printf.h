/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/17 09:46:48 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"
/*
*TYPE OF VARIABLE DEFINE
*/
# define INTI 1
# define FLOAT 2
# define HEXA 3
# define HEXAM 4
# define CHAR 5
# define D_MOD 6
# define INTU 7
# define POINTER_ADRESSE 8
# define STR 9
# define INTLU 10
# define INTL 11
# define OCTAL 12
# define OCTALM 13
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
    unsigned int    pres_left;
    unsigned int    pres_right;
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
    short           hash_tag;
    short           plus;
    short           negative;
    short           currency;
    short           cast;
    struct s_type   *next;
}                   t_type;

void        printer(t_type *all);
int         option_handler(char *str, int i, t_type *temp);
void        ft_putfloat(t_type *temp);
void        ft_puthexa(t_type *temp);
void        ft_putoctal(t_type *temp);
void        ft_putunbr(unsigned int unbr);
void        ft_putlunbr(long unsigned int lunbr);
void        ft_putlnbr(long int lnbr);
t_type      *parse_all(char *str, va_list args, char *format);
int         ft_printf(char *format, ...);
void        print_unumber(t_type *temp);
void        print_lunumber(t_type *temp);
void        print_lnumber(t_type *temp);
void        adresse_printer(t_type *temp);
void        set_presschar_for_int(t_type *temp, int total);
void        set_presschar(t_type *temp, int total);

#endif
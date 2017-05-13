/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/10 13:08:43 by myernaux         ###   ########.fr       */
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
# define STR 9
# define D_MOD 6
# define CHAR 5
/*
* OPTIONS DEFINE
*/
# define HASH_TAG 2 
# define CURRENCY 1
/*
* OPTIONS DEFINE
*/
# define LONG_LONG 2 
# define LONG 1
# define UNSIGNED_CHAR 3
# define UNSIGNED_SHORT_INT 4 

typedef struct      s_type
{
    unsigned int    pres_left;
    unsigned int    pres_right;
    short           type;
    int             number;
    long long       hexa;
    double          fnumber;
    char            *str;
    int             c;
    short           hash_tag;
    short           currency;
    short           cast;
    struct s_type   *next;
}                   t_type;
int         option_handler(char *str, int i, t_type *temp);
void        ft_putfloat(t_type *temp);
void        ft_puthexa(t_type *temp);
t_type      *parse_all(char *str, va_list args, char *format);
int         ft_printf(char *format, ...);

#endif
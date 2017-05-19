/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 09:30:09 by myernaux          #+#    #+#             */
/*   Updated: 2017/05/19 16:09:59 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    base_octal(long long toctal, int total)
{
    long long a;
    
    a = 8;
    while (toctal >= a)
    {
        a += a * 8;
        total++;
    }
    return (total);
}

void    ft_itoa_octal_capital(int total, t_type *temp, char *str)
{
    int         i;
    long long   base;
    long long   octal;

    octal = temp->octal;
    base = 1;
    i = 0;
    while (++i < total)
        base = base * 8;
    i = 0;
    while (i < total)
    {
        if (octal >= base)
        {
            str[i] = (octal / base) + '0';
            octal %= base; 
        }
        else
            str[i] = '0';
        i++;
        base = base / 8;
    }
}

void    ft_itoa_octal(int total, t_type *temp, char *str)
{
    int         i;
    long long   base;
    long long   octal;

    octal = temp->octal;
    base = 1;
    i = 1;
    while (i < total)
    {
        base = base * 8;
        i++;
    }
    i = 0;
    while (i < total)
    {
        str[i] = (octal / base) + '0';
        octal %= base; 
        i++;  
        base = base / 8;
    }
}

int    ft_putoctal(t_type *temp)
{
    int     total;
    char    *str;
    int     all;

    total = base_octal(temp->octal, 1);
    str = semalloc(total + 1);
    str[total + 1] = '\0';
    all = set_presschar(temp, total);
    if (temp->type == OCTAL)
        ft_itoa_octal(total, temp, str);
    if (temp->type == OCTALM)
        ft_itoa_octal_capital(total, temp, str);
    int i = 0;
    while(i < total)
    {
        ft_putchar(str[i]);
        i++;
    }
    free(str);
    return all;
}
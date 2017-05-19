/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/19 13:31:06 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    base_hexa(long long thexa, int total)
{
    long long a;
    
    a = 16;
    while (thexa >= a)
    {
        a += a * 16;
        total++;
    }
    return (total);
}

int    set_presschar(t_type *temp, int total)
{
    int i;
    int all;
    
    all = 0;
    i = 0;
    if (temp->pres_left < total && temp->pres_right < total && 
    temp->hash_tag == 2)
        {
            ft_putstr("0x");
            all += 2;
        }
    if (temp->pres_left > total || temp->pres_right > total)
    {
        if (temp->pres_right < total)
            temp->pres_right = total;
        if (temp->pres_left > temp->pres_right)
             i = temp->pres_left - (temp->pres_right + temp->hash_tag);
        all += i;
        while (i > 0)
        {
            ft_putchar(' ');
            i--;
        }
        if (temp->hash_tag)
            {
                ft_putstr("0x");
                all += 2;
            }
        if (temp->pres_right > total)
            i = temp->pres_right - total;
        all += i;
        while (i > 0)
        {
            i--;
            ft_putchar('0');
        }
    }
    return (all + total);
}

void    ft_itoa_hexa_capital(int total, t_type *temp, char *str)
{
    int         i;
    long long   base;
    long long   hexa;

    hexa = temp->hexa;
    base = 1;
    i = 1;
    while (i < total)
    {
        base = base * 16;
        i++;
    }
    i = 0;
    while (i < total)
    {
        if (hexa >= base)
        {
            if (hexa / base >= 10)
                     str[i] = (hexa /base) + 55;
            else  
                str[i] = (hexa / base) + '0';
            hexa %= base; 
        }
        else
            str[i] = '0';
        i++;
        base = base / 16;
    }
}

void    ft_itoa_hexa(int total, t_type *temp, char *str)
{
    int i;
    long long base;
    long long hexa;

    hexa = temp->hexa;
    base = 1;
    i = 1;
    while (i < total)
    {
        base = base * 16;
        i++;
    }
    i = 0;
    while (i < total)
    {
        if (hexa >= base)
        {
            if (hexa / base >= 10)
                 str[i] = (hexa /base) + 87;
            else  
                str[i] = (hexa / base) + '0';
            hexa %= base; 
        }
        else
            str[i] = '0';
        i++;  
        base = base / 16;
    }
}

int    ft_puthexa(t_type *temp)
{
    int total;
    char *str;
    int all;

    if (temp->hexa < 0)
        temp->hexa = (16777210 - temp->hexa) + 0xff000000;
    total = base_hexa(temp->hexa, 1);
    str = semalloc(total + 1);
    str[total + 1] = '\0';
    all = set_presschar(temp, total);
    if (temp->type == HEXA)
        ft_itoa_hexa(total, temp, str);
    if (temp->type == HEXAM)
        ft_itoa_hexa_capital(total, temp, str);
    ft_putstr(str);
    free(str);
    return (all);
}
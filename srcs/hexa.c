/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/21 11:40:21 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
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
*/
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
/*
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
}*/
static    int    switch_hexam(int x)
{
    if (0 <= x && x <= 9)
        return (48 + x);
    if (x >= 10 && x <= 15)
    {
        x = x - 10;
        return (65 + x);
    }
    return (0);
}

char        *ft_hexa_itoa_capital(unsigned long long n)
{
    char                *str;
    int                    size;
    unsigned long long    x;

    x = n;
    size = 0;
    while (x >= 16)
    {
        x /= 16;
        size++;
    }
    str = (char *)malloc(sizeof(str) * (size + 1));
    if (str)
    {
        str[size + 1] = '\0';
        while (size >= 0)
        {
            x = n % 16;
            str[size] = switch_hexam(x);
            n /= 16;
            size--;
        }
    }
    return (str);
}
int    ft_puthexa(t_type *temp)
{
    char            *str;
    int i;

    if(temp->type == HEXAM)
        str = ft_hexa_itoa_capital(temp->hexa);
    else if(temp->type == POINTER_ADRESSE)
        str = ft_hexa_itoa(temp->pointer);
    else
        str = ft_hexa_itoa(temp->hexa);
    i = set_presschar(temp, ft_strlen(str));
    ft_putstr(str);
    free(str);
    return (i);
}
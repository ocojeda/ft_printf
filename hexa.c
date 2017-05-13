/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/10 13:08:41 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
unsigned int    base_hexa(unsigned int thexa, int total)
{
    if(thexa >= 0x000010)
        total = 2;
    if(thexa >= 0x000100)
        total = 3;
    if(thexa >= 0x001000)
        total = 4;
    if(thexa >= 0x010000)
        total = 5;
    if(thexa >= 0x100000)
        total = 6;
    return total;
}
void    set_presschar(t_type *temp, int total)
{
    int i;
    int x;

    i = 0;
    if(temp->pres_left > total || temp->pres_right > total)
    {
        if(temp->pres_left > temp->pres_right)
             i = temp->pres_left - (temp->pres_right + temp->hash_tag);
        while(i > 0)
        {
            ft_putchar(' ');
            i--;
        }
        if(temp->hash_tag)
            ft_putstr("0x");
        if(temp->pres_right > total)
            i = temp->pres_right - total;
            while(i > 0)
            {
               i--;
               ft_putchar('0');
            }
    }
}
void    ft_itoa_hexa_capital(int total, t_type *temp, char *str)
{
    int i;
    int base;
    int hexa;

    hexa = temp->hexa;
    base = 1;
    i = 1;
    while(i < total)
    {
        base = base * 16;
        i++;
    }
    i = 0;
    while(i < total)
    {
        if(hexa >= base)
            {
                if(hexa / base >= 10)
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
    int base;
    int hexa;

    hexa = temp->hexa;
    base = 1;
    i = 1;
    while(i < total)
    {
        base = base * 16;
        i++;
    }
    i = 0;
    while(i < total)
    {
        if(hexa >= base)
            {
                if(hexa / base >= 10)
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
void    ft_puthexa(t_type *temp)
{
    int pres;
    int total;
    char *str;

    total = base_hexa(temp->hexa, 1);
    str = semalloc(total + 1);
    str[total + 1] = '\0';
    set_presschar(temp, total);
    if(temp->type == HEXA)
        ft_itoa_hexa(total, temp, str);
    if(temp->type == HEXAM)
        ft_itoa_hexa_capital(total, temp, str);
    ft_putstr(str);
    free(str);
}
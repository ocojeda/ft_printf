/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/19 14:00:20 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     set_presschar_for_int(t_type *temp, int total)
{
    int i;
    int a;

    a = 0;
    i = 0;
    if (temp->pres_left > total || temp->pres_right > total)
    {
        if (temp->pres_right < total)
            temp->pres_right = total;
        if (temp->pres_left > temp->pres_right)
             i = temp->pres_left - temp->pres_right 
             - temp->plus - temp->negative;
        a += i;
        while (i > 0)
        {
            ft_putchar(' ');
            i--;
        }
        if (temp->plus)
            {
                ft_putchar('+');
                a++;
            }
        if(temp->negative)
            {
                ft_putchar('-');
                a++;
            }
        if (temp->pres_right > total)
            {
                i = temp->pres_right - total;
                a += i;
            }
        while (i > 0)
        {
           i--;
           ft_putchar('0');
        }
    }
    return (a + total);
}

int    print_number(t_type *temp)
{
    long long t;
    int total;
    int i;

    total = 0;
    if (temp->number < 0)
    {
        temp->number *= -1;
        temp->negative = NEGATIVE;
    }
    t = temp->number;
    while (t != 0)
    {
        total++;
        t /= 10;
    }
    if (temp->number < 0)
        total++;
    i = set_presschar_for_int(temp, total);
    ft_putnbr(temp->number);
    return i;
}

int    printer(t_type *all)
{
    t_type *temp;
    int everything;

    everything = 0;
    temp = all;
    while (temp)
    {
        if (temp->type == STR)
            {
                ft_putstr(temp->str);
                everything += ft_strlen(temp->str);
            }
        if (temp->type == INTI)
            everything += print_number(temp);
        if (temp->type == HEXA)
            everything += ft_puthexa(temp);
        if (temp->type == HEXAM)
            everything += ft_puthexa(temp);
        if (temp->type == D_MOD)
            {
                ft_putchar('%');
                everything++;
            }
        if (temp->type == CHAR)
            {
                ft_putchar(temp->c);
                everything++;
            }
        if (temp->type == INTU)
            everything += print_unumber(temp);
        if (temp->type == INTLU)
            everything += print_lunumber(temp);
        if (temp->type == INTL)
            everything += print_lnumber(temp);
        if (temp->type == POINTER_ADRESSE)
            everything += adresse_printer(temp);
        if (temp->type == OCTAL)
            everything += ft_putoctal(temp);
        if (temp->type == OCTALM)
            everything += ft_putoctal(temp);
        if (temp->type == WCHAR)
            ft_putwchar(temp->wc);
        if (temp->type == WSTR)
            ft_putwstr(temp->wstr);
        temp = temp->next;
    }
    return everything;
}
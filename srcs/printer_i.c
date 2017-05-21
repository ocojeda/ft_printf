/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/21 10:26:30 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     set_presschar_for_int(t_type *temp, int total)
{
    int i;
    int a;

    i = 0;
    if((temp->pres_left < total + temp->spaces) && temp->spaces && 
    temp->number > 0)
        {
            i = temp->spaces;
            a = temp->spaces;
            while(a)
            {
                ft_putchar(' ');
                a--;
            }
        }
    a = i;
    i = 0;
        if (temp->pres_right < total)
            temp->pres_right = total - temp->negative;
        if (temp->pres_left > temp->pres_right)
             i = temp->pres_left - temp->pres_right 
             - temp->plus - temp->negative;
        a += i;
        while (i > 0)
        {
            ft_putchar(' ');
            i--;
        }
        if (temp->plus && temp->number >= 0 && !temp->negative)
            {
                ft_putchar('+');
                a++;
            }
        if(temp->negative)
            {
                ft_putchar('-');
                a++;
            }
        if (temp->pres_right > total - temp->negative)
                i = temp->pres_right - total + temp->negative;
        a += i - temp->negative;
        while (i > 0)
        {
           i--;
           ft_putchar('0');
        }
    return (a + total);
}

int    print_number(t_type *temp)
{
    long long t;
    int total;
    int i;

    i = 0;
    total = 0;
    t = temp->number;
    while (t != 0)
    {
        total++;
        t /= 10;
    }
    if(temp->number <= INT_MIN)
    {
        temp->number = temp->number * -1;
    }
    if(temp->no_pres_left == 1 && temp->no_pres_right == 1 && temp->plus == 0)
        {
            if(temp->spaces)
                {
                    i = temp->spaces;
                    total += temp->spaces;
                    if(temp->number < 0)
                        {
                            total--;
                            i--;
                        }
                    while(i--)
                        ft_putchar(' ');
                }
            ft_putnbr(temp->number);
            if(temp->number < 0)
                return total +1;
            else if (temp->number == 0)
                return 1;
            else
                return (total);
        }
    if(temp->no_pres_left == 2 && (temp->no_pres_right == 2 || temp->no_pres_right == 0)
     && temp->number == 0)
        {
            return 0;
        }
    if(temp->number < 0)
        {
            total++;
            temp->negative = NEGATIVE;
            temp->number *= -1;
        }
    i = set_presschar_for_int(temp, total);
    //ft_putchar('\n');
    //ft_putnbr(total);
    //ft_putchar('\n');
    ft_putnbr(temp->number);
    if(temp->number == 0 && temp->pres_right)
        i++;
    return (i);
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
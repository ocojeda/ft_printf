/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/15 16:04:37 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void    set_presschar_for_int(t_type *temp, int total)
{
    int i;
    int x;

    i = 0;
    if (temp->pres_left > total || temp->pres_right > total)
    {
        if (temp->pres_right < total)
            temp->pres_right = total;
        if (temp->pres_left > temp->pres_right)
             i = temp->pres_left - temp->pres_right 
             - temp->plus - temp->negative;
        while (i > 0)
        {
            ft_putchar(' ');
            i--;
        }
        if (temp->plus)
            ft_putchar('+');
        if(temp->negative)
            ft_putchar('-');
        if (temp->pres_right > total)
            i = temp->pres_right - total;
        while (i > 0)
        {
           i--;
           ft_putchar('0');
        }
    }
}

static void    print_number(t_type *temp)
{
    long long t;
    int total;

    total = 0;
    if(temp->number < 0)
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
    set_presschar_for_int(temp, total);
    ft_putnbr(temp->number);
}

void    printer(t_type *all)
{
    t_type *temp;

    temp = all;
    while (temp)
    {
        if (temp->type == STR)
            ft_putstr(temp->str);
        if (temp->type == FLOAT)
            ft_putfloat(temp);
        if (temp->type == INTI)
            print_number(temp);
        if (temp->type == HEXA)
            ft_puthexa(temp);
        if (temp->type == HEXAM)
            ft_puthexa(temp);
        if (temp->type == D_MOD)
            ft_putchar('%');
        if (temp->type == CHAR)
            ft_putchar(temp->c);
        if (temp->type == INTU)
            ft_putunbr(temp->nbr);
        if (temp->type == POINTER_ADRESSE)
            adresse_printer(temp);
        temp = temp->next;
    }
}
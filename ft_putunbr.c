/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/15 16:15:04 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putunbr(unsigned int nbr)
{
    if (nbr / 10)
        ft_putunbr(nbr / 10);
    ft_putchar('0' + (nbr % 10));
}

/*static void    set_presschar_for_int(t_type *temp, int total)
{
    int i;
    int x;

    i = 0;
    if (temp->pres_left > total || temp->pres_right > total)
    {
        if (temp->pres_right < total)
            temp->pres_right = total;
        if (temp->pres_left > temp->pres_right)
             i = temp->pres_left - temp->pres_right - temp->plus;
        while (i > 0)
        {
            ft_putchar(' ');
            i--;
        }
        if (temp->plus)
            ft_putchar('+');
        if (temp->pres_right > total)
            i = temp->pres_right - total;
        while (i > 0)
        {
           i--;
           ft_putchar('0');
        }
    }
}

void    print_unumber(t_type *temp)
{
    long long t;
    int total;

    total = 0;
    t = temp->nbr;
    while (t != 0)
    {
        total++;
        t /= 10;
    }
  //  if (temp->nbr < 0)
    //    total++;
    set_presschar_for_int(temp, total);
    ft_putunbr(temp->nbr);
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/31 15:20:10 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putunbr(unsigned int unbr)
{
    if (unbr / 10)
        ft_putunbr(unbr / 10);
    ft_putchar('0' + (unbr % 10));
}

int    print_unumber(t_type *temp)
{
    long long t;
    int total;
    int all;

    total = 0;
    /*if (temp->number < 0)
    {
        temp->number *= -1;
        temp->negative = NEGATIVE;
    }*/
    t = temp->unbr;
    while (t != 0)
    {
        total++;
        t /= 10;
    }
    all = set_presschar_for_int(temp, total);
    if (temp->unbr > 0)
        ft_putunbr(temp->unbr);
    if (temp->unbr == 0 && temp->pres_right)
        all++;
    return (all);
}
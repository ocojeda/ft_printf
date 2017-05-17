/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/17 08:54:56 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putunbr(unsigned int unbr)
{
    if (unbr / 10)
        ft_putunbr(unbr / 10);
    ft_putchar('0' + (unbr % 10));
}

void    print_unumber(t_type *temp)
{
    long long t;
    int total;

    total = 0;
    if(temp->number < 0)
    {
        temp->number *= -1;
        temp->negative = NEGATIVE;
    }
    t = temp->unbr;
    while (t != 0)
    {
        total++;
        t /= 10;
    }
    set_presschar_for_int(temp, total);
    ft_putunbr(temp->unbr);
}
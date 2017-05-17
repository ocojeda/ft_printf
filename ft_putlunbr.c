/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlunbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:25:14 by myernaux          #+#    #+#             */
/*   Updated: 2017/05/17 08:54:45 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putlunbr(long unsigned int lunbr)
{
    if (lunbr / 10)
        ft_putlunbr(lunbr / 10);
    ft_putchar('0' + (lunbr % 10));
}

void    print_lunumber(t_type *temp)
{
    long long t;
    int total;

    total = 0;
    if(temp->number < 0)
    {
        temp->number *= -1;
        temp->negative = NEGATIVE;
    }
    t = temp->lunbr;
    while (t != 0)
    {
        total++;
        t /= 10;
    }
    set_presschar_for_int(temp, total);
    ft_putlunbr(temp->lunbr);
}
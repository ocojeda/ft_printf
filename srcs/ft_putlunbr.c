/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlunbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:25:14 by myernaux          #+#    #+#             */
/*   Updated: 2017/05/19 13:23:53 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putlunbr(long unsigned int lunbr)
{
    if (lunbr / 10)
        ft_putlunbr(lunbr / 10);
    ft_putchar('0' + (lunbr % 10));
}

int    print_lunumber(t_type *temp)
{
    long long t;
    int total;
    int all;

    total = 0;
    if (temp->number < 0)
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
    all = set_presschar_for_int(temp, total);
    ft_putlunbr(temp->lunbr);
    return (all);
}
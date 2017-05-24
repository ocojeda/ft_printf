/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlunbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:25:14 by myernaux          #+#    #+#             */
/*   Updated: 2017/05/24 10:05:27 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_putlunbr(long unsigned int lunbr, int all)
{
    if (lunbr == ULONG_MAX)
    {
        ft_putstr("18446744073709551615");
        return 20;
    }
    if (lunbr / 10)
        ft_putlunbr(lunbr / 10, all);
    ft_putchar('0' + (lunbr % 10));
    return all;
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
    all = ft_putlunbr(temp->lunbr, all);
    return (all);
}
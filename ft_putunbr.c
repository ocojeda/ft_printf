/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/16 11:23:04 by myernaux         ###   ########.fr       */
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
    t = temp->unbr;
    while (t != 0)
    {
        total++;
        t /= 10;
    }
    set_presschar_for_int(temp, total);
    ft_putunbr(temp->unbr);
}
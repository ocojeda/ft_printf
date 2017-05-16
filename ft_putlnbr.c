/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:25:14 by myernaux          #+#    #+#             */
/*   Updated: 2017/05/16 11:21:46 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlnbr(long int lnbr)
{
	long unsigned int nbr;

	if (lnbr < 0)
	{
		ft_putchar('-');
		nbr = -lnbr;
	}
	else
		nbr = lnbr;
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		ft_putchar(nbr + '0');
	}
}

void    print_lnumber(t_type *temp)
{
    long long t;
    int total;

    total = 0;
    t = temp->lnbr;
    while (t != 0)
    {
        total++;
        t /= 10;
    }
    set_presschar_for_int(temp, total);
    ft_putlnbr(temp->lnbr);
}
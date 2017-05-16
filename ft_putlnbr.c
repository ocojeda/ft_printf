/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:25:14 by myernaux          #+#    #+#             */
/*   Updated: 2017/05/16 09:32:27 by myernaux         ###   ########.fr       */
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

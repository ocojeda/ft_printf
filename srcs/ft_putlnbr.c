/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:41:00 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/07 13:41:24 by myernaux         ###   ########.fr       */
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

int		print_lnumber(t_type *temp)
{
	long long	t;
	int			total;
	int			all;

	total = 0;
	if (temp->number < 0)
	{
		temp->number *= -1;
		temp->negative = NEGATIVE;
	}
	t = temp->lnbr;
	while (t != 0)
	{
		total++;
		t /= 10;
	}
	all = set_presschar_for_int(temp, total);
	ft_putlnbr(temp->lnbr);
	return (all);
}

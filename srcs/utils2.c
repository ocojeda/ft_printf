/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 03:11:50 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/19 23:23:10 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_printlongnbr(long long ll)
{
	if (ll == LONG_LONG_MIN)
	{
		ft_putstr("-9223372036854775808");
		return ;
	}
	if (ll < 0)
	{
		ft_putchar('-');
		ll = -ll;
	}
	if (ll >= 10)
	{
		ft_printlongnbr(ll / 10);
		ft_printlongnbr(ll % 10);
	}
	else
		ft_putchar(ll + '0');
}

void			increase_one(int *a, int *b)
{
	*a = (*a) + 1;
	*b = (*b) + 1;
}

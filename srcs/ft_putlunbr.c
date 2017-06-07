/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlunbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:43:22 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/07 13:44:34 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putpresschar(int a, int i, int n)
{
	if (n == 1)
	{
		ft_putchar(' ');
		a--;
		return (a);
	}
	if (n == 2)
	{
		ft_putchar(' ');
		i--;
		return (i);
	}
	if (n == 3)
	{
		ft_putchar('+');
		a++;
		return (a);
	}
	if (n == 4)
	{
		ft_putchar('-');
		a++;
		return (a);
	}
	return (0);
}

int		set_presschar_for_ul2(t_type *temp, int total, int i, int a)
{
	while (i > 0)
		ft_putpresschar(a, i, 2);
	if (temp->plus && temp->number >= 0 && !temp->negative)
		ft_putpresschar(a, i, 3);
	if (temp->negative)
		ft_putpresschar(a, i, 4);
	if (temp->pres_right > total - temp->negative)
		i = temp->pres_right - total + temp->negative;
	a += i - temp->negative;
	while (i > 0)
	{
		i--;
		ft_putchar('0');
	}
	return (a);
}

int		set_presschar_for_ul(t_type *temp, int total)
{
	int i;
	int a;

	i = 0;
	if ((temp->pres_left < total + temp->spaces) && temp->spaces &&
			temp->lunbr > 0)
	{
		i = temp->spaces;
		a = temp->spaces;
		while (a)
			ft_putpresschar(a, i, 1);
	}
	a = i;
	i = 0;
	if (temp->pres_right < total)
		temp->pres_right = total - temp->negative;
	if (temp->pres_left > temp->pres_right)
		i = temp->pres_left - temp->pres_right - temp->plus - temp->negative;
	a += i;
	a = set_presschar_for_ul2(temp, total, i, a);
	return (a + total);
}

int		ft_putlunbr(long unsigned int lunbr, int all)
{
	if (lunbr == ULONG_MAX)
	{
		ft_putstr("18446744073709551615");
		return (20);
	}
	if (lunbr / 10)
		ft_putlunbr(lunbr / 10, all);
	ft_putchar('0' + (lunbr % 10));
	return (all);
}

int		print_lunumber(t_type *temp)
{
	long unsigned int	t;
	int					total;
	int					all;

	if (temp->lunbr == 0)
		total = 1;
	else
		total = 0;
	t = temp->lunbr;
	while (t != 0)
	{
		total++;
		t /= 10;
	}
	all = set_presschar_for_ul(temp, total);
	all = ft_putlunbr(temp->lunbr, all);
	return (all);
}

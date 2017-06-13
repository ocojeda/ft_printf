/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/13 06:17:35 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putunbr(unsigned long long unbr)
{
	if (unbr / 10)
		ft_putunbr(unbr / 10);
	ft_putchar('0' + (unbr % 10));
}

static int	set_pres_charuneg(t_type *temp, int total, int i, int all)
{
	int a;

	a = 0;
	ft_putunbr(temp->unbr);
	if (temp->pres_right < total)
		temp->pres_right = total - temp->negative;
	if (temp->pres_left > temp->pres_right)
		a += (i = temp->pres_left - temp->pres_right
		- temp->plus - temp->negative);
	while (i > 0)
		i -= ft_putchar_spe(' ');
	if (temp->pres_right > total - temp->negative)
		i = temp->pres_right - total + temp->negative;
	while (i--)
		a += ft_putchar_spe('0');
	all += a;
	return (all);
}

static int	set_pres_upos(t_type *temp, int total, int i, int all)
{
	int a;

	a = 0;
	if (temp->pres_right < total)
		temp->pres_right = total - temp->negative;
	if (temp->pres_left > temp->pres_right)
		a += (i = temp->pres_left - temp->pres_right
				- temp->plus - temp->negative);
	while (i > 0)
		i -= ft_putchar_spe(' ');
	if (temp->pres_right > total - temp->negative)
		i = temp->pres_right - total + temp->negative;
	while (i--)
		a += ft_putchar_spe('0');
	all += a;
	ft_putunbr(temp->unbr);
	return (all);
}

int			total_unumber(unsigned long long t, int total, t_type *temp)
{
	if (temp->cast == HH_CAST && temp->unbr >= 256)
	{
		while (temp->unbr >= 256)
			temp->unbr -= 256;
		t = temp->unbr;
	}
	while (t)
	{
		total++;
		t /= 10;
	}
	return (total);
}

int			print_unumber(t_type *temp)
{
	unsigned long long	t;
	int					total;
	int					all;

	total = 0;
	total = total_unumber(temp->unbr, total, temp);
	t = temp->unbr;
	all = total;
	if (temp->no_pres_left == 2 && (temp->no_pres_right == 2 ||
				temp->no_pres_right == 0) && temp->unbr == 0)
		return (0);
	if (temp->cero && temp->pres_left && !temp->pres_right)
	{
		temp->pres_right = temp->pres_left;
		temp->pres_left = 0;
	}
	if (temp->pres_left > temp->pres_right + total && temp->negative)
		all = set_pres_charuneg(temp, total, 0, all);
	else
		all = set_pres_upos(temp, total, 0, all);
	if (temp->unbr == 0)
		all++;
	return (all);
}

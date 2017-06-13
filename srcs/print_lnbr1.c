/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lnbr1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 03:16:57 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/13 04:06:33 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			set_presschar_for_long2(t_type *temp, int total, int i, int a)
{
	if (temp->plus && temp->lnbr >= 0)
	{
		a += ft_putchar_spe('+');
		if (temp->lnbr == 0)
			a++;
	}
	if (temp->lnbr < 0)
		temp->lnbr *= -ft_putchar_spe('-');
	if (temp->pres_right > total - temp->negative)
		i = temp->pres_right - total + temp->negative;
	while (i > 0)
	{
		i -= ft_putchar_spe('0');
		a++;
	}
	return (a);
}

int			set_presschar_for_long(t_type *temp, int total)
{
	int i;
	int a;

	i = 0;
	if ((temp->pres_left < total + temp->spaces) && temp->spaces &&
			temp->lnbr > 0)
	{
		i = temp->spaces;
		a = temp->spaces;
		while (a)
			a -= ft_putchar_spe(' ');
	}
	a = i;
	i = 0;
	if (temp->pres_right < total)
		temp->pres_right = total - temp->negative;
	if (temp->pres_left > temp->pres_right)
		i = temp->pres_left - temp->pres_right - temp->plus - temp->negative;
	a += i;
	while (i > 0)
		i -= ft_putchar_spe(' ');
	return (set_presschar_for_long2(temp, total, i, a) + total);
}

int			spaces_forlonginverse(t_type *temp, int i, int a, int total)
{
	if ((temp->pres_left < total + temp->spaces) &&
			temp->spaces && temp->lnbr > 0)
	{
		i = temp->spaces;
		a = temp->spaces;
		while (a)
			a -= ft_putchar_spe(' ');
	}
	return (i);
}

int			set_presschar_for_long_inverse(t_type *temp, int total)
{
	int i;
	int a;

	a = spaces_forlonginverse(temp, 0, 0, total);
	i = 0;
	if (temp->pres_right < total)
		temp->pres_right = total - temp->negative;
	if (temp->pres_left > temp->pres_right)
	{
		i = temp->pres_left - temp->pres_right - temp->plus - temp->negative;
		a += i;
	}
	while (i > 0)
		i -= ft_putchar_spe(' ');
	if (temp->pres_right > total - temp->negative)
		i = temp->pres_right - total + temp->negative;
	while (i > 0)
	{
		i -= ft_putchar_spe('0');
		a++;
	}
	return (a + total);
}

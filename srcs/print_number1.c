/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:11:01 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/08 14:29:11 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


void		cast_manager3(t_type *temp, int t)
{
	if (temp->nopoint && !temp->pres_left && temp->pres_right && temp->negative)
	{
		temp->pres_left = temp->pres_right;
		temp->pres_right = 0;
		temp->nopoint = 0;
	}
	if (temp->plus && t < 0 && temp->pres_left
			&& !temp->pres_right && temp->cero)
	{
		temp->plus = 0;
		temp->pres_right = temp->pres_left - 1;
		temp->pres_left = 0;
	}
	if (t < 0 && temp->plus)
		temp->plus = 0;
}
/*
static int	set_presschar_for_int2(t_type *temp, int total, int i, int a)
{
	int t;
	t = temp->number;
	if (temp->plus && temp->number >= 0)
	{
		ft_putchar('+');
		a++;
		if (temp->number == 0)
			a++;
	}
	if (t < 0)
		temp->number *= -ft_putchar_spe('-');
	if (temp->pres_right > total - temp->negative)
		i = temp->pres_right - total + temp->negative;
	while (i > 0)
	{
		i -= ft_putchar_spe('0');
		a++;
	}
	return (a);
}

int			set_presschar_for_int(t_type *temp, int total)
{
	int			i;
	int			a;
	short		t;

	t = temp->number;
	i = 0;
	if ((temp->pres_left < total + temp->spaces) && temp->spaces && t > 0)
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
	while (i--)
		ft_putchar(' ');
	return (set_presschar_for_int2(temp, total, i, a) + total);
}

static int	set_presschar_for_int_inverse(t_type *temp, int total, int i)
{
	int			a;

	if ((temp->pres_left < total + temp->spaces) &&
			temp->spaces && temp->number > 0)
	{
		i = temp->spaces;
		a = temp->spaces;
		while (a > 0)
			a -= ft_putchar_spe(' ');
	}
	a = i;
	i = 0;
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
	return (a + total);
}

int			print_number_inverse(t_type *temp, long long t, int total)
{
	int			temp1;

	if (temp->pres_right > total)
	{
		temp1 = temp->pres_right - total;
		if (temp->number > 0 && temp->plus)
		{
			total += ft_putchar_spe('+');
			temp->plus = 0;
		}
		while (temp1--)
		{
			temp->pres_right -= ft_putchar_spe('0');
			total++;
		}
	}
	ft_printlongnbr(t);
	if (t < 0)
	{
		temp->number *= -1;
		total++;
	}
	return (set_presschar_for_int_inverse(temp, total, 0));
}*/
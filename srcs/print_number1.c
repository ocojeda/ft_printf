/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:11:01 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/13 03:39:29 by ocojeda-         ###   ########.fr       */
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

void	cero_mng_foriandl(t_type *temp)
{
	if (temp->cero)
	{
		if (temp->pres_left && !temp->pres_right && temp->plus)
			temp->pres_right = temp->pres_left - 1;
		else if (temp->pres_left && !temp->pres_right)
			temp->pres_right = temp->pres_left;
	}
}

int			cero_manager_int(t_type *temp, int total, int t, int i)
{
	cero_mng_foriandl(temp);
	if (temp->no_pres_left == 1 && temp->no_pres_right == 1 && temp->plus == 0)
	{
		if (temp->spaces)
		{
			i = temp->spaces;
			total += temp->spaces;
			if (t < 0)
			{
				total--;
				i--;
			}
			while (i--)
				ft_putchar(' ');
		}
		ft_putnbr(temp->number);
		if (t < 0)
			return (total + 1);
		else if (t == 0)
			return (1);
		else
			return (total);
	}
	return (0);
}

int			spaces_forintinverse(t_type *temp, int i, int a, int total)
{
	if ((temp->pres_left < total + temp->spaces) &&
			temp->spaces && temp->number > 0)
	{
		i = temp->spaces;
		a = temp->spaces;
		while (a)
			a -= ft_putchar_spe(' ');
	}
	return (i);
}

int			set_presschar_for_int_inverse(t_type *temp, int total)
{
	int i;
	int a;

	a = spaces_forintinverse(temp, 0, 0, total);
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

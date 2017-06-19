/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 01:57:33 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/13 03:55:15 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
/*c bon*/
static int	cast_mng(t_type *temp, int t, int total)
{
	if (temp->cast == HH_CAST)
	{
		if (temp->number < -128)
		{
			while (temp->number <= -128)
				temp->number += 256;
			t = temp->number;
		}
		else if (temp->number >= 128)
		{
			while (temp->number >= 128)
				temp->number -= 256;
			t = temp->number;
		}
	}
	if (temp->cast == H_CAST && temp->number > 32767)
	{
		while (temp->number > 32767)
			temp->number -= 32768 * 2;
		t = temp->number;
	}
	return (total_int(t, total));
}
//*CBON
int			is_left(t_type *temp, int total, int t, int i)
{
	int temp1;

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
	ft_putnbr(t);
	if (t < 0)
	{
		temp->number *= -1;
		total++;
	}
	i = set_presschar_for_int_inverse(temp, total);
	return (i);
}
//*CBON
int			choose_l_o_r(t_type *temp, int total, int t, int i)
{
	if (temp->pres_left > temp->pres_right + total && temp->negative)
		i = is_left(temp, total, t, i);
	else
	{	
		t = temp->number;
		if (t < 0 && temp->cero && temp->pres_left)
			temp->pres_left--;
		if (temp->number == 0 && temp->pres_left && !temp->pres_right)
		{
			if(temp->point)
			{	
				i = set_presschar_for_int(temp, total);
				return (i);
			}
			else
				temp->pres_left--;
				i = set_presschar_for_int(temp, total);
				return(i + ft_putchar_spe('0'));
		}
		i = set_presschar_for_int(temp, total);
		if (temp->cero && temp->number == 0)
			i--;
		else
			ft_putnbr(temp->number);
		if (t < 0)
			i++;
	}
	if (t == 0 && temp->pres_right && !temp->plus)
		i++;
	return (i);
}
 // C BON
int			negative_press_right(t_type *temp, int total, int i)
{
	if (temp->cero)
	{
		if (temp->pres_left && !temp->pres_right)
		{
			temp->pres_right = temp->pres_left - 1;
			temp->pres_left = 0;
		}
	}
	temp->pres_left--;
	i = set_presschar_for_int(temp, total);
	if (temp->number < 0)
		ft_putnbr(-temp->number);
	else
		ft_putnbr(temp->number);
	return (i + 1);
}

int			print_number(t_type *temp)
{
	int total;
	int i;

	i = 0;
	total = 0;
	if (temp->no_pres_left == 2 && (temp->no_pres_right == 2 ||
		!temp->no_pres_right) && !temp->number)
		return (0);
	if (temp->cast == LONG_LONG || temp->cast == LONG
			|| temp->cast == Z_CAST || temp->cast == J_CAST)
		return (ft_putllnbr(temp));
	total = cast_mng(temp, temp->number, 0);
	cast_manager3(temp, temp->number);
	if (temp->number < 0 && (temp->pres_left > temp->pres_right + total) &&
			!temp->negative)
		return (negative_press_right(temp, total, i));
	if (temp->nopoint && temp->pres_right && !temp->pres_left
			&& temp->number < 0)
		temp->pres_right--;
	if ((i = cero_manager_int(temp, total, temp->number, i)))
		return (i);
	return (choose_l_o_r(temp, total, temp->number, i));
}

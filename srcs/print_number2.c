/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 02:43:20 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/13 02:46:16 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
/*c bon*/
int				set_presschar_for_int2(t_type *temp, int total, int i, int a)
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
		i--;
		ft_putchar('0');
		a++;
	}
	return (a);
}
/*c bon*/
int				set_presschar_for_int(t_type *temp, int total)
{
	int i;
	int a;

	i = 0;
	a = 0;
	if ((temp->pres_left < total + temp->spaces) && temp->spaces
			&& temp->number >= 0)
			{
				a = ft_putchar_spe(' ');
				if(temp->pres_right)
					temp->pres_right--;
				//if(temp->pres_right)temp->pres_left--;
			}
	i = 0;
	if (temp->pres_right < total)
		temp->pres_right = total - temp->negative;
	if (temp->pres_left > temp->pres_right)
		i = temp->pres_left - temp->pres_right - temp->plus - temp->negative;
	a += i;
	while (i > 0)
		i -= ft_putchar_spe(' ');
	return (set_presschar_for_int2(temp, total, i, a) + total);
}

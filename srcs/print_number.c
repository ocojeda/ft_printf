/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:22:17 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/08 14:54:06 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		cast_manager2(t_type *temp, int t, int total, int i)
{
	cast_manager3(temp, t);
	if (t < 0 && temp->pres_left > temp->pres_right + total && !temp->negative)
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
		(t < 0) ? ft_printlongnbr(-t) : ft_printlongnbr(t);
		return (i + 1);
	}
	return (0);
}

int		choose_to_print_lr_forll(t_type *temp, int i, long long t, int total)
{
	if (temp->pres_left > temp->pres_right + total && temp->negative)
		i = print_number_inverse(temp, t, total);
	else
	{
		if (temp->number < 0)
		{
			total++;
			temp->negative = NEGATIVE;
			t *= -1;
		}
		i = set_presschar_for_int(temp, total);
		ft_printlongnbr(t);
		if (t == 0 && temp->pres_right)
			i++;
	}
	return (i);
}

int		ft_putllnbr(t_type *temp)
{
	long long	t;
	int			total;
	int			i;

	i = 0;
	total = 0;
	t = temp->number;
	while (t != 0)
	{
		total++;
		t /= 10;
	}
	t = temp->number;
	if ((i = cero_manager(temp, i, total, t)))
		return (i);
	if (temp->no_pres_left == 2 && (temp->no_pres_right == 2
				|| temp->no_pres_right == 0) && t == 0)
		return (0);
	return (choose_to_print_lr_forll(temp, i, t, total));
}

int		choose_to_print_lr_fori(t_type *temp, int i, long long t, int total)
{
	if (temp->pres_left > temp->pres_right + total && temp->negative)
		i = print_number_inverse(temp, t, total);
	else
	{
		t = temp->number;
		if (t < 0 && temp->cero && temp->pres_left)
			temp->pres_left--;
		if (temp->number == 0 && temp->pres_left && !temp->pres_right)
		{
			i = set_presschar_for_int(temp, total);
			return (i);
		}
		i = set_presschar_for_int(temp, total);
		//problem!!!
		(temp->cero && temp->number == 0) ? i-- : ft_putnbr(temp->number);
		if (temp->number < 0)
			{
				i++;
			}
	}
	if (t == 0 && temp->pres_right)
		i++;
	return (i);
}

int		print_number(t_type *temp)
{
	int			t;
	int			total;
	int			i;

	i = 0;
	total = 0;
	if (temp->cast == LONG_LONG || temp->cast == LONG
			|| temp->cast == Z_CAST || temp->cast == J_CAST)
		return (ft_putllnbr(temp));
	total = cast_for_number(temp, i, 0, temp->number);
	t = temp->number;
	if (temp->no_pres_left == 2 && (temp->no_pres_right == 2 ||
				temp->no_pres_right == 0) && t == 0)
		return (0);
	if ((i = cast_manager2(temp, t, total, i)))
		return (i);
	if (temp->nopoint && temp->pres_right && !temp->pres_left && t < 0)
		temp->pres_right--;
	if ((i = cero_manager(temp, i, total, t)))
		return (i);
	i = choose_to_print_lr_fori(temp, i, t, total);
	return (i);
}

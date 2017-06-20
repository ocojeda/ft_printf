/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lnbr2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 12:12:51 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/20 12:28:23 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_left_for_long(t_type *temp, int total, long long t, int i)
{
	if (temp->pres_right > total)
	{
		i = temp->pres_right - total;
		if (temp->lnbr > 0 && temp->plus)
		{
			total += ft_putchar_spe('+');
			temp->plus = 0;
		}
		while (i--)
		{
			temp->pres_right -= ft_putchar_spe('0');
			total++;
		}
	}
	ft_printlongnbr(t);
	if (t < 0)
	{
		temp->lnbr = -t;
		total++;
	}
	return (set_presschar_for_long_inverse(temp, total));
}

void	choose2(t_type *temp, int *i, int total)
{
	*i = set_presschar_for_long(temp, total);
	if (temp->cero && temp->lnbr == 0)
		(*i)--;
	else
		ft_printlongnbr(temp->lnbr);
	if (temp->lnbr < 0)
		(*i)++;
}

int		choose_for_long(t_type *temp, int total, int i)
{
	if (temp->pres_left > temp->pres_right + total && temp->negative)
		i = is_left_for_long(temp, total, temp->lnbr, i);
	else
	{
		if (temp->lnbr < 0 && temp->cero && temp->pres_left)
			temp->pres_left--;
		if (temp->lnbr == 0 && temp->pres_left && !temp->pres_right)
		{
			if (temp->point)
				return (set_presschar_for_long(temp, total));
			else
				temp->pres_left--;
			return (set_presschar_for_long(temp, total) +
				ft_putchar_spe('0'));
		}
		choose2(temp, &i, total);
	}
	if (temp->lnbr == 0 && temp->pres_right && !temp->plus)
		i++;
	return (i);
}

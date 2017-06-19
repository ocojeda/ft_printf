/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 02:48:59 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/13 04:05:20 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		lcast_manager3(t_type *temp, long long t)
{
	if (temp->cero && !temp->pres_left && temp->pres_right && temp->negative)
	{
		temp->pres_left = temp->pres_right;
		temp->pres_right = 0;
		temp->nopoint = 0;
		temp->cero = 0;
	}
	if(temp->cero && temp->negative)
		temp->cero = 0;
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

int			lnegative_press_right(t_type *temp, int total, int i)
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
	if (temp->lnbr < 0)
		ft_printlongnbr(temp->lnbr);
	else
		ft_printlongnbr(temp->lnbr);
	return (i + 1);
}

void		cero_mng_forl(t_type *temp)
{
	if (temp->cero)
	{
		if(temp->pres_right && temp->lnbr >= 0 && temp->plus)
			temp->pres_right--;
		if (temp->pres_left && !temp->pres_right && temp->plus)
			temp->pres_right = temp->pres_left - 1;
		else if (temp->pres_left && !temp->pres_right)
			temp->pres_right = temp->pres_left;
	}
}

int			cero_manager_long(t_type *temp, int total, long long t, int i)
{
	cero_mng_forl(temp);
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
		ft_printlongnbr(temp->lnbr);
		if (t < 0)
			return (total + 1);
		else if (t == 0)
			return (1);
		else
			return (total);
	}
	return (0);
}

int		ft_putllnbr(t_type *temp)
{
	int total;
	int i;

	i = 0;
	total = 0;
	if (temp->no_pres_left == 2 && (temp->no_pres_right == 2
			|| !temp->no_pres_right) && !temp->lnbr)
		return (0);
	total = total_long(temp->lnbr, total);
	lcast_manager3(temp, temp->lnbr);
	if (temp->lnbr < 0 && (temp->pres_left > temp->pres_right + total) &&
			!temp->negative)
		return(lnegative_press_right(temp, total, i));
	if (temp->nopoint && temp->pres_right && !temp->pres_left
			&& temp->number < 0)
		temp->pres_right--;
	if ((i = cero_manager_long(temp, total, temp->lnbr, i)))
		return (i);
	return (choose_for_long(temp, total, temp->lnbr, i));
}
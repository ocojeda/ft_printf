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

int		lnbr_noptions(t_type *temp, int i, int total)
{
	cero_mng_foriandl(temp);
	if (temp->no_pres_left == 1 && temp->no_pres_right == 1 && temp->plus == 0)
	{
		if (temp->spaces)
		{
			i = temp->spaces;
			total += temp->spaces;
			if (temp->lnbr < 0)
			{
				total--;
				i--;
			}
			while (i--)
				ft_putchar(' ');
		}
		ft_printlongnbr(temp->lnbr);
		if (temp->lnbr < 0)
			return (total + 1);
		else if (temp->lnbr == 0)
			return (1);
		else
			return (total);
	}
	return (i);
}

int		print_leftlong(t_type *temp, int i, int total)
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
	ft_printlongnbr(temp->lnbr);
	if (temp->lnbr < 0)
	{
		temp->lnbr *= -1;
		total++;
	}
	i = set_presschar_for_long_inverse(temp, total);
	return (i);
}

int		print_rightlong(t_type *temp, int i, int total)
{
	if (temp->lnbr < 0)
	{
		total++;
		temp->lnbr = -temp->lnbr;
	}
	i = set_presschar_for_long(temp, total);
	ft_printlongnbr(temp->lnbr);
	if (temp->lnbr == 0 && temp->pres_right)
		i++;
	return (i);
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
	if ((i = lnbr_noptions(temp, i, total)))
		return (i);
	if (temp->no_pres_left == 2 && (temp->no_pres_right == 2 ||
			!temp->no_pres_right) && !temp->lnbr)
		return (0);
	if (temp->pres_left > temp->pres_right + total && temp->negative)
		i = print_leftlong(temp, 0, total);
	else
		i = print_rightlong(temp, i, total);
	return (i);
}

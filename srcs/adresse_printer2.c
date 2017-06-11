/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adresse_printer2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 08:41:10 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/07 13:32:12 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			set_presschar_forprev(t_type *temp, int total)
{
	int	i;
	int all;

	all = 0;
	i = -1;
	if (temp->pres_left > total || temp->pres_right > total)
	{
		if (temp->pres_right < total)
			temp->pres_right = total;
		if (temp->pres_left > temp->pres_right)
			i = temp->pres_left - (temp->pres_right + temp->hash_tag);
		all += i;
		while (--i > 0)
			ft_putchar(' ');
		if (temp->pres_right > total)
			i = temp->pres_right - total;
		all += i;
		while (--i > 0)
			ft_putchar('0');
	}
	return (all + total);
}

static int	set_presschar_forp2(t_type *temp, int all, int total)
{
	int i;

	i = -1;
	if (temp->pres_right < total)
		temp->pres_right = total;
	if (temp->pres_left > temp->pres_right)
		i = temp->pres_left - (temp->pres_right + temp->hash_tag);
	all += i;
	while (i > 0)
		i -= ft_putchar_spe(' ');
	if (temp->hash_tag)
	{
		ft_putstr("0x");
		all += 2;
	}
	if (temp->pres_right > total)
		i = temp->pres_right - total;
	all += i;
	while (--i > 0)
		ft_putchar('0');
	return (all);
}

int			set_presschar_forp(t_type *temp, int total)
{
	int all;

	all = 0;
	if (temp->pres_left < total && temp->pres_right < total &&
			temp->hash_tag == 2)
	{
		ft_putstr("0x");
		all += 2;
	}
	if (temp->pres_left > total || temp->pres_right > total)
		all = set_presschar_forp2(temp, all, total);
	return (all + total);
}

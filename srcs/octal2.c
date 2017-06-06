/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 08:52:57 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/06 08:53:49 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int set_presschar_octal2(t_type *temp, int i, int all, int total)
{
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	if (temp->hash_tag && !temp->negative)
	{
		ft_putstr("0");
		all++;
	}
	if (temp->pres_right > total)
		i = temp->pres_right - total;
	all += i;
	while (i > 0)
	{
		i--;
		ft_putchar('0');
	}
	return (all);
}

int	set_presschar_octal(t_type *temp, int total)
{
	int i;
	int all;

	all = 0;
	i = 0;
	if (temp->pres_left < total && temp->pres_right < total && 
			temp->hash_tag == 2)
	{
		ft_putstr("0");
		all ++;
	}
	if (temp->pres_left > total || temp->pres_right > total)
	{
		if (temp->pres_right < total)
			temp->pres_right = total;
		if (temp->pres_left > temp->pres_right)
		{
			i = temp->pres_left - (temp->pres_right);
			if (temp->hash_tag)
				i--;
		}
		all += i;
		all = set_presschar_octal2(temp, i, all, total);
	}
	return (all + total);
}
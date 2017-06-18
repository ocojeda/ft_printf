/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_for_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 13:28:48 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/13 05:33:09 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_string3(t_type *temp, int total, int i)
{
	if (temp->cero && temp->pres_left > total)
	{
		i = temp->pres_left - total;
		while (i--)
			total += ft_putchar_spe('0');
		ft_putstr(temp->str);
		return (total);
	}
	i = temp->pres_left - total;
	if (temp->negative)
	{
		ft_putstr(temp->str);
		while (i > 0)
			i -= ft_putchar_spe(' ');
	}
	else
	{
		while (i > 0)
			i -= ft_putchar_spe(' ');
		ft_putstr(temp->str);
	}
	return (temp->pres_left);
}

int		print_string2(t_type *temp, int i)
{
	if (temp->pres_left && temp->pres_right == 0 && temp->cero)
	{
		i = temp->pres_left;
		while (i > 0)
			i -= ft_putchar_spe('0');
		return (temp->pres_left);
	}
	i = temp->pres_left;
	while (i > 0)
		i -= ft_putchar_spe(' ');
	return (temp->pres_left);
}

int		print_string(t_type *temp, int everything)
{
	int		i;
	int		total;
	char 	*str;
	
	total = ft_strlen(temp->str);
	i = 0;
	if (temp->pres_right && temp->pres_right < total)
	{
		str = ft_strsub(temp->str, 0, temp->pres_right);
		temp->str = str;
		free(str);
		total = ft_strlen(temp->str);
	}
	else if (temp->pres_left && temp->no_pres_right == 2)
		return (print_string2(temp, i));
	if (temp->pres_left > total)
		return (print_string3(temp, total, i));
	else if (temp->pres_right)
		return (print_string5(temp, i, (everything =
				print_string4(temp, total, everything))));
	else
		everything = print_string6(everything, temp->str);
	return (everything);
}
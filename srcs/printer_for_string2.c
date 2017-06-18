/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_for_string2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 13:30:21 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/08 17:35:57 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_string6(int everything, char *str_temp)
{
	everything += ft_strlen(str_temp);
	ft_putstr(str_temp);
	return (everything);
}

int		print_string5(t_type *temp, int i, int everything)
{
	while (temp->pres_right)
	{
		ft_putchar(temp->str[i]);
		i++;
		temp->pres_right--;
	}
	return (everything);
}

int		print_string4(t_type *temp, int total, int evr)
{
	if (total < temp->pres_right)
		total -= temp->pres_right;
	if (total < 0)
		total = ft_strlen(temp->str);
	if (temp->pres_right > total)
		evr += total;
	else
		evr += temp->pres_right;
	return (evr);
}
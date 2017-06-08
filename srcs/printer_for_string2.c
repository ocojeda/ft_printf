/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_for_string2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 13:30:21 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/08 13:39:32 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_string6(int everything, char *str_temp)
{
	everything += ft_strlen(str_temp);
	ft_putstr(str_temp);
	return (everything);
}

int		print_string5(t_type *temp, int i, int everything, char *str_temp)
{
	while (temp->pres_right)
	{
		ft_putchar(temp->str1[i]);
		i++;
		temp->pres_right--;
	}
	free(str_temp);
	return (everything);
}

int		print_string4(t_type *temp, int total, int everything, char *str_temp)
{
	if (total < temp->pres_right)
		total -= temp->pres_right;
	if (total < 0)
		total = ft_strlen(str_temp);
	if (temp->pres_right > total)
		everything += total;
	else
		everything += temp->pres_right;
	return (everything);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_modulo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:19:21 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/13 01:06:23 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_double_modulo_handler1(t_type *temp, int everything)
{
	if (temp->pres_left && temp->pres_right == 0 && temp->cero)
	{
		temp->pres_right = temp->pres_left;
		temp->pres_left = 0;
		temp->nopoint = 1;
	}
	if (temp->nopoint && temp->pres_right)
	{
		temp->pres_right--;
		while (temp->pres_right--)
			everything += ft_putchar_spe('0');
		return (everything + ft_putchar_spe('%'));
	}
	else if (temp->negative)
	{
		everything += ft_putchar_spe('%');
		if (temp->pres_left)
			while (--temp->pres_left)
				everything += ft_putchar_spe(' ');
		return (everything);
	}
	return (0);
}

int		ft_double_modulo_handler(t_type *temp)
{
	int everything;

	everything = 0;
	if ((everything = ft_double_modulo_handler1(temp, everything)))
		return (everything);
	if (temp->pres_left)
	{
		if (temp->pres_left)
		{
			temp->pres_left--;
			while (temp->pres_left--)
			{
				everything++;
				ft_putchar(' ');
			}
		}
		ft_putchar('%');
		everything++;
		return (everything);
	}
	else
		return (ft_putchar_spe('%'));
}

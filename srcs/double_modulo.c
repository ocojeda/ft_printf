/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_modulo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:19:21 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/07 13:36:19 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_double_modulo_handler(t_type *temp)
{
	int everything;

	everything = 0;
	if(temp->pres_left && temp->pres_right == 0 && temp->cero)
	{
		temp->pres_right = temp->pres_left;
		temp->pres_left = 0;
		temp->nopoint = 1;
	}
	//ft_putnbr(temp->pres_left);
	//ft_putnbr(temp->pres_right);
	//ft_putnbr(temp->cero);
	if (temp->nopoint && temp->pres_right)
	{
		temp->pres_right--;
		while (temp->pres_right--)
		{
			ft_putchar('0');
			everything++;
		}
		ft_putchar('%');
		everything++;
		return (everything);
	}

	else if(temp->negative)
	{
		ft_putchar('%');
		if (temp->pres_left)
		{
			temp->pres_left--;
			while (temp->pres_left--)
			{
				everything++;
				ft_putchar(' ');
			}
		}
		everything++;
	return (everything);
	}
	else if (temp->pres_left)
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
		return(ft_putchar_spe('%'));
}

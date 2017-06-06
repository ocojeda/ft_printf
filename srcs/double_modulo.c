/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_modulo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:19:21 by myernaux          #+#    #+#             */
/*   Updated: 2017/05/31 14:19:36 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putpress(t_type *temp)
{
		ft_putchar(' ');
		temp->pres_left--;
}

int	 ft_double_modulo_handler(t_type *temp)
{
	int i;
 
	i = 1;
	if (temp->negative)
	{
		ft_putchar('%');	
		if (temp->pres_left)
			temp->pres_left--;
		i = temp->pres_left;
		while (temp->pres_left)
			ft_putpress(temp);
	}
	else
	{
		if (temp->pres_left)
			temp->pres_left--;
		i = temp->pres_left;
		while (temp->pres_left)
			ft_putpress(temp);
		ft_putchar('%'); 
	}
	return (i + 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:14:25 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/20 12:48:05 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_chars4(t_type *temp, int everything)
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
	if (temp->c != 0)
		ft_putchar(temp->c);
	everything++;
	return (everything);
}

int		print_chars3(t_type *temp, int everything)
{
	if (temp->c != 0)
		ft_putchar(temp->c);
	if (temp->pres_left)
	{
		temp->pres_left--;
		while (temp->pres_left--)
		{
			everything++;
			ft_putchar(' ');
		}
	}
	return (everything + 1);
}

int		print_chars2(t_type *temp, int everything)
{
	temp->pres_right--;
	while (temp->pres_right--)
	{
		ft_putchar('0');
		everything++;
	}
	ft_putchar(temp->c);
	everything++;
	return (everything);
}

int		print_chars(t_type *temp)
{
	if (temp->pres_left && temp->pres_right == 0 && temp->cero)
	{
		temp->pres_right = temp->pres_left;
		temp->pres_left = 0;
		temp->nopoint = 1;
	}
	if (temp->nopoint && temp->pres_right)
		return (print_chars2(temp, 0));
	else if (temp->negative)
		return (print_chars3(temp, 0));
	else if (temp->pres_left)
		return (print_chars4(temp, 0));
	else if (!temp->c)
		return (1);
	else
		return (ft_putchar_spe(temp->c));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:14:25 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/07 14:35:35 by myernaux         ###   ########.fr       */
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
	everything++;
	return (everything);
}

int		print_chars2(t_type *temp, int everything)
{
	ft_putnbr(temp->nopoint);
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
	int everything;

	everything = 0;
	//ft_putnbr(temp->pres_right);
	//	ft_putnbr(temp->pres_left);
	//	ft_putnbr(temp->c);
	/*if(temp->cero)
	{
		if(temp->pres_left && !temp->pres_right)
			{
				temp->pres_right = temp->pres_left - 1;
				temp->pres_left = 0;
			}
	//	if(temp->c == 0)
	//		ft_putchar('h');
		if(temp->c == 0 && temp->pres_right)
		{
			while(temp->pres_right--)
				everything += ft_putchar_spe('0');
			return (everything + 1);
		}
	}*/
	if (temp->nopoint && temp->pres_right)
		everything = print_chars2(temp, everything);
	else if (temp->negative)
		everything = print_chars3(temp, everything);
	else if (temp->type == CHAR && temp->pres_left)
		everything = print_chars4(temp, everything);
	else if (temp->c == 0)
		return (1);
	else
	{
		ft_putchar(temp->c);
		everything = 1;
	}
	return (everything);
}

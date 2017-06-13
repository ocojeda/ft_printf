/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_for_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 13:28:48 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/08 13:38:22 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_string3(t_type *temp, int total, int i, char *str_temp)
{
	/*ft_putnbr(temp->pres_right);
	ft_putnbr(temp->pres_left);
	ft_putnbr(temp->cero);
	ft_putnbr(total);*/
	if(temp->cero && temp->pres_left > total)
	{
		i = temp->pres_left - total;
		while(i--)
			total += ft_putchar_spe('0');
		ft_putstr(str_temp);
		return total;
	}
	i = temp->pres_left - total;
	if (temp->negative)
	{
		ft_putstr(str_temp);
		while (i > 0)
		{
			ft_putchar(' ');
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			ft_putchar(' ');
			i--;
		}
		ft_putstr(str_temp);
	}
	free(str_temp);
	return (temp->pres_left);
}

int		print_string2(t_type *temp, int i)
{
	
	if(temp->pres_left && temp->pres_right == 0 && temp->cero)
	{
		i = temp->pres_left;
		while (i > 0)
		{
			ft_putchar('0');
			i--;
		}
		return (temp->pres_left);	
	}
	i = temp->pres_left;
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	return (temp->pres_left);
}

int		print_string(t_type *temp, int everything)
{
	int		i;
	int		total;
	char	*str_temp;

	total = ft_strlen(temp->str1);
	i = 0;
	
	
	if (temp->pres_right && temp->pres_right < total)
	{
		str_temp = ft_strsub(temp->str1, 0, temp->pres_right);
		total = ft_strlen(str_temp);
	}
	else if (temp->pres_left && temp->no_pres_right == 2)
		return (print_string2(temp, i));
	else
		str_temp = ft_strdup(temp->str1);
	if (temp->pres_left > total)
		return (print_string3(temp, total, i, str_temp));
	else if (temp->pres_right)
		return (print_string5(temp, i, (everything =
				print_string4(temp, total, everything, str_temp)), str_temp));
	else
		everything = print_string6(everything, str_temp);
	free(str_temp);
	return (everything);
}

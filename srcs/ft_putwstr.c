/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:00:55 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/13 06:19:38 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		putwstr3(t_type *temp, int i, int total, wchar_t *str_temp)
{
	i = temp->pres_left - total;
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	ft_wputstr(str_temp);
	free(str_temp);
	return (temp->pres_left);
}

int		putwstr2(t_type *temp, int i)
{
	if (temp->pres_left && temp->pres_right == 0 && temp->cero)
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

int		ft_putwstr(t_type *temp, wchar_t *wstr, int everything, int i)
{
	int		total;
	wchar_t *str_temp;

	total = ft_wstrlen(wstr);
	if (temp->pres_left == 0 && temp->pres_right == 0)
		return (ft_wputstr(wstr));
	if (temp->pres_right && temp->pres_right < total)
	{
		str_temp = ft_wstrsub(wstr, 0, temp->pres_right);
		total = ft_wstrlen(str_temp);
	}
	else if (temp->pres_left && temp->no_pres_right == 2)
		return (putwstr2(temp, i));
	else
		str_temp = ft_wstrdup(wstr);
	if (temp->pres_left > total)
		return (putwstr3(temp, i, total, str_temp));
	else if (temp->pres_right)
	{
		everything = putwstr4(temp, str_temp, everything, total);
		return (putwstr5(temp, wstr, str_temp, everything));
	}
	else
		everything = putwstr6(everything, str_temp);
	return (everything);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 08:58:01 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/06 08:59:20 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	putwstr6(int everything, wchar_t *str_temp)
{
	everything += ft_wstrlen(str_temp);
	ft_wputstr(str_temp);
	return (everything);
}

void	putwstr5(t_type *temp, wchar_t *wstr, wchar_t *str_temp, int i)
{
	while (temp->pres_right)
	{
		ft_putwchar(wstr[i]);
		i++;
		temp->pres_right--;
	}
	free(str_temp);
}

int	putwstr4(t_type *temp, wchar_t *str_temp, int everything, int total)
{
	if (total < temp->pres_right)
		total -= temp->pres_right;
	if (total < 0)
		total = ft_wstrlen(str_temp);
	if (temp->pres_right > total)
		everything += total;
	else 
		everything += temp->pres_right;
	return (everything);
}
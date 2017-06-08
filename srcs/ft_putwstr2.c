/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 08:58:01 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/08 17:33:52 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		putwstr6(int everything, wchar_t *str_temp)
{
	everything += ft_wstrlen(str_temp);
	ft_wputstr(str_temp);
	free(str_temp);
	return (everything);
}

int		putwstr5(t_type *temp, wchar_t *wstr, wchar_t *str_temp, int evr)
{
	int i;

	i = 0;
	while (temp->pres_right)
	{
		ft_putwchar(wstr[i]);
		i++;
		temp->pres_right--;
	}
	free(str_temp);
	return (evr);
}

int		putwstr4(t_type *temp, wchar_t *str_temp, int evr, int total)
{
	if (total < temp->pres_right)
		total -= temp->pres_right;
	if (total < 0)
		total = ft_wstrlen(str_temp);
	if (temp->pres_right > total)
		evr += total;
	else
		evr += temp->pres_right;
	return (evr);
}

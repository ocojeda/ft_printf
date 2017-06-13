/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:15:15 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/13 06:03:44 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_puthexaneg(t_type *temp, int i, char *str)
{
	if (temp->negative)
	{
		if (temp->hash_tag)
		{
			ft_putstr("0x");
			i = 2;
			temp->hash_tag = 0;
		}
		ft_putstr(str);
		i += set_presschar(temp, ft_strlen(str));
	}
	else
	{
		i = set_presschar(temp, ft_strlen(str));
		if (temp->pres_left && temp->pres_right == 1 && temp->hexa == 0
				&& (temp->type == HEXA || temp->type == HEXAM))
		{
			ft_putchar(' ');
			return (i);
		}
		else
			ft_putstr(str);
	}
	return (i);
}

void	ft_puthexacast(t_type *temp)
{
	if (temp->cast == H_CAST)
	{
		if (temp->hexa > 65535)
		{
			while (temp->hexa > 65535)
				temp->hexa -= 65535;
			temp->hexa--;
		}
	}
	if (temp->cast == HH_CAST)
	{
		while (temp->hexa > 256)
			temp->hexa -= 256;
	}
}

int		ft_puthexa2(t_type *temp, int i, char *str)
{
	if (temp->pres_left && !temp->pres_right && temp->cero)
	{
		temp->pres_right = temp->pres_left;
		temp->pres_left = 0;
	}
	if (temp->hexa == 0 && temp->hash_tag)
		temp->hash_tag = 0;
	i = ft_puthexaneg(temp, i, str);
	free(str);
	return (i);
}

int		ft_puthexa(t_type *temp)
{
	char	*str;
	int		i;

	if (temp->nopoint && !temp->pres_left && temp->pres_right && temp->negative)
	{
		temp->pres_left = temp->pres_right - temp->hash_tag;
		temp->pres_right = 0;
		temp->nopoint = 0;
	}
	if (temp->no_pres_left == 2 && (temp->no_pres_right == 2 ||
				temp->no_pres_right == 0) && temp->hexa == 0)
		return (0);
	if ((temp->hexa == 0) && (temp->nopoint))
		return (0);
	ft_puthexacast(temp);
	if (temp->type == HEXAM)
		str = ft_hexa_itoa_capital(temp->hexa);
	else
		str = ft_hexa_itoa(temp->hexa);
	i = 0;
	return (ft_puthexa2(temp, i, str));
}

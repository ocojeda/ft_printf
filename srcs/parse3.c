/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:44:24 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/13 05:23:15 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		cast_handler2(char *str, int i, t_type *temp)
{
	if (str[i])
	{
		if (str[i] == 'l')
		{
			if (str[i + 1] == 'l')
			{
				temp->cast = LONG_LONG;
				i++;
			}
			else
				temp->cast = LONG;
			i++;
		}
		if (str[i] == 'j')
		{
			temp->cast = J_CAST;
			i++;
		}
		if (str[i] == 'j')
		{
			temp->cast = J_CAST;
			i++;
		}
	}
	return (i);
}

int		cast_handler(char *str, int i, t_type *temp)
{
	i = cast_handler2(str, i, temp);
	if (str[i])
	{
		if (str[i] == 'h')
		{
			if (str[i + 1] == 'h')
			{
				temp->cast = HH_CAST;
				i++;
			}
			else
				temp->cast = H_CAST;
			i++;
		}
		if (str[i] == 'z')
		{
			temp->cast = Z_CAST;
			i++;
		}
		if (temp->plus && temp->spaces)
			temp->spaces = 0;
	}
	return (i);
}

int		option_handler2(char *str, int i, t_type *temp)
{
	while (str[i] == ' ' && str[i])
	{
		temp->spaces++;
		i++;
	}
	if (str[i])
	{
		if (str[i] == '#')
		{
			temp->hash_tag = HASH_TAG;
			i++;
		}
		if (str[i] == '+')
		{
			temp->plus = POSITIVE;
			i++;
		}
	}
	return (i);
}

int		option_handler(char *str, int i, t_type *temp)
{
	if (str[i])
	{
		if (str[i] == '0' && (str[i + 1] == '#' || str[i + 1] == '+' ||
		str[i + 1] == '-' || str[i + 1] == ' ' || (str[i + 1] >= '0' &&
			str[i + 1] <= '9')) && str[i + 1])
		{
			temp->cero = 1;
			i++;
		}
		while ((str[i] == '#' || str[i] == '+' ||
					str[i] == '-' || str[i] == ' '))
		{
			i = option_handler2(str, i, temp);
			if (str[i] == '-')
			{
				temp->negative = NEGATIVE;
				i++;
			}
		}
	}
	return (precission_handler(str, i, temp));
}
